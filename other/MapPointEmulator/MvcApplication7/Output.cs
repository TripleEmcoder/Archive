using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Web;
using System.Web.Services.Protocols;
using System.Xml.Serialization;

namespace MvcApplication7
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
}