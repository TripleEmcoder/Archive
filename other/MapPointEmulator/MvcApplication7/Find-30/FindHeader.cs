using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services.Protocols;
using System.Xml;
using System.Xml.Serialization;

namespace MvcApplication7
{
    public class FindHeader : SoapHeader
    {
        private readonly XmlDocument xml;

        public FindHeader()
        {
            xml = new XmlDocument();
        }

        [XmlIgnore]
        public string Original { get; set; }

        [XmlElement("Original")]
        public XmlCDataSection OriginalCData
        {
            get { return xml.CreateCDataSection(Original); }
            set { Original = value.InnerText; }
        }
    }
}