using System;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using System.Web.Services;
using System.Web.Services.Protocols;
using GoogleMapsApi;
using GoogleMapsApi.Entities.Geocoding.Request;
using GoogleMapsApi.Entities.Geocoding.Response;
using Newtonsoft.Json;

namespace MapPointEmulator
{
    /// <summary>
    /// Summary description for FindService
    /// </summary>
    [WebService(Namespace = "http://s.mappoint.net/mappoint-30/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class FindService : System.Web.Services.WebService
    {
        public FindHeader FindHeader { get; set; }

        public FindService()
        {
            FindHeader = new FindHeader();
        }

        [WebMethod]
        [SoapHeader("FindHeader", Direction = SoapHeaderDirection.Out)]
        public Location[] GetLocationInfo(LatLong location, string dataSourceName, GetInfoOptions options)
        {
            var response = MapsAPI.GetGeocode(
                new GeocodingRequest
                {
                    Location = new GoogleMapsApi.Entities.Common.Location(location.Latitude, location.Longitude),
                    Language = "pl"
                });

            if (response.Status != Status.OK)
                throw new Exception(response.Status.ToString());

            Thread.Sleep(250);

            FindHeader.Original = JsonConvert.SerializeObject(
                response.Results
                    .GroupBy(r => string.Join(", ", r.Types))
                    .ToDictionary(
                        rg => rg.Key,
                        rg => rg.Select(
                            r => r.AddressComponents
                                .GroupBy(c => string.Join(", ", c.Types))
                                .ToDictionary(
                                    cg => cg.Key,
                                    cg => cg.Select(
                                        c => string.Format("{0} ({1})", c.ShortName, c.LongName)
                                        )
                                )
                            )
                    ),
                Formatting.Indented);

            Debug.WriteLine(FindHeader.Original);

            var country = response.Results.GetType("country");
            var admin1 = response.Results.GetType("administrative_area_level_1");
            var admin2 = response.Results.GetType("administrative_area_level_2");
            var admin3 = response.Results.GetType("administrative_area_level_3");
            var neighborhood = response.Results.GetType("neighborhood");
            var street = response.Results.GetType("street_address");
            var route = response.Results.GetType("route");

            // ReSharper disable ConstantNullCoalescingCondition
            var result = new Location
            {
                Entity = new Entity {DisplayName = "",},
                Address = new Address
                {
                    CountryRegion = null
                                    ?? country.GetComponent("country")
                                    ?? street.GetComponent("country")
                                    ?? route.GetComponent("country"),
                    Subdivision = null
                                  ?? admin1.GetComponent("administrative_area_level_1")
                                  ?? street.GetComponent("administrative_area_level_1")
                                  ?? route.GetComponent("administrative_area_level_1"),
                    PrimaryCity = null
                                  ?? street.GetComponent("locality")
                                  ?? route.GetComponent("locality"),
                    AddressLine = new[]
                    {
                        null
                        ?? street.GetComponent("route")
                        ?? route.GetComponent("route"),
                        null
                        ?? street.GetComponent("sublocality")
                        ?? route.GetComponent("sublocality")
                        ?? neighborhood.GetComponent("sublocality")
                        ?? admin3.GetComponent("administrative_area_level_3")
                    }.JoinNotEmpty(", "),
                    FormattedAddress = null
                                       ?? street.GetComponent("formatted_address")
                                       ?? route.GetComponent("formatted_address")
                }
            };
            // ReSharper restore ConstantNullCoalescingCondition

            if (result.Address.Subdivision == null)
                result.Address.Subdivision = result.Address.CountryRegion;

            return new[] { result };
        }
    }
}
