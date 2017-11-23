using System.Web.Services.Protocols;
using System.Xml;
using System.Xml.Serialization;

namespace MapPointEmulator
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