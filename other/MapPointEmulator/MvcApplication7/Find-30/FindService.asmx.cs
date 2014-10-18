using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using System.Web;
using System.Web.Services;
using System.Xml.Serialization;
using GoogleMapsApi;
using GoogleMapsApi.Entities.Geocoding.Request;
using GoogleMapsApi.Entities.Geocoding.Response;

namespace MvcApplication7.Find_30
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
        public class LatLong
        {
            public double Latitude { get; set; }
            public double Longitude { get; set; }
        }

        public class Entity
        {
            public int ID { get; set; }
            public string Name { get; set; }
            public string DisplayName { get; set; }
            public string TypeName { get; set; }

            [XmlArrayItem("Property")]
            public EntityPropertyValue[] Properties { get; set; }
        }

        public class EntityPropertyValue
        {
            public string Name { get; set; }
            public object Value { get; set; }
        }

        public class Address
        {
            public string AddressLine { get; set; }
            public string PrimaryCity { get; set; }
            public string SecondaryCity { get; set; }
            public string Subdivision { get; set; }
            public string PostalCode { get; set; }
            public string CountryRegion { get; set; }
            public string FormattedAddress { get; set; }
        }

        public class Location
        {
            public LatLong LatLong { get; set; }
            public Entity Entity { get; set; }
            public Address Address { get; set; }
            //public MapViewRepresentations BestMapView { get; set; }
            public string DataSourceName { get; set; }
        }

        public class GetInfoOptions
        {
            [DefaultValue(true)]
            public bool IncludeAddresses { get; set; }

            [DefaultValue(true)]
            public bool IncludeAllEntityTypes { get; set; }

            public string[] EntityTypesToReturn { get; set; }
        }

        [WebMethod]
        public Location[] GetLocationInfo(LatLong location, string dataSourceName, GetInfoOptions options)
        {
            var response = MapsAPI.GetGeocode(new GeocodingRequest
                                             {
                                                 Location = new GoogleMapsApi.Entities.Common.Location(location.Latitude, location.Longitude)
                                             });

            if (response.Status != Status.OK)
                throw new Exception(response.Status.ToString());
            
            //foreach (var x in response.Results.SelectMany(r => r.AddressComponents).SelectMany(c => c.Types).Distinct())
            //    Debug.WriteLine(x);

            //foreach (var r in response.Results)
            //    Debug.WriteLine("{0} - {1}", string.Join(", ", r.Types), r.FormattedAddress);

            //var types = new[]
            //                {

            //                };

            Thread.Sleep(250);
            var result = response.Results
                .Where(IsBestChoice)
                .Select(GetLocation)
                .ToArray();

            return result;
        }

        private static bool IsBestChoice(Result result)
        {
            if (result.Types.Contains("street_address"))
                return true;

            if (result.Types.Contains("route") && GetComponent(result, "administrative_area_level_3") != null)
                return true;

            if (result.Types.Contains("administrative_area_level_3"))
                return true;

            if (result.Types.Contains("route"))
            {
                var route = GetComponent(result, "route");

                if (route != route.ToUpper())
                    return true;
            }                
                

            return false;
        }

        private static Location GetLocation(Result result)
        {
            return new Location
                       {
                           Entity = new Entity
                                        {
                                            DisplayName = "",
                                        },
                           Address = new Address
                                         {
                                             CountryRegion = GetComponent(result, "country"),
                                             Subdivision = GetSubdivision(result),
                                             PrimaryCity = GetPrimaryCity(result),
                                             PostalCode = GetComponent(result, "postal_code"),
                                             AddressLine = GetAddressLine(result),
                                             FormattedAddress = result.FormattedAddress
                                         }
                       };
        }

        private static string GetSubdivision(Result result)
        {
            return GetComponent(result, "administrative_area_level_1")
                   ?? GetComponent(result, "country");
        }

        private static string GetPrimaryCity(Result result)
        {
            return GetComponent(result, "locality") 
                ?? GetComponent(result, "administrative_area_level_3") 
                ?? GetSubdivision(result);
        }

        private static string GetAddressLine(Result result)
        {
            var components = new[]
                                 {

                                     GetComponent(result, "sublocality"),
                                     GetComponent(result, "route")
                                 };

            return GetNullJoin(components) ?? GetPrimaryCity(result);
        }

        private static string GetNullJoin(IEnumerable<string> components)
        {
            components = components.Where(c => c != null);
            
            if (!components.Any())
                return null;

            return string.Join(", ", components);
        }

        private static string GetComponent(Result result, string type)
        {
            var component = result.AddressComponents.FirstOrDefault(c => c.Types.Contains(type));

            if (component == null)
                return null;

            return component.LongName;
        }
    }
}
