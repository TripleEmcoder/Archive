using System;
using System.Collections.Generic;
using System.Text;

using System.IO;
using System.Xml.Serialization;

namespace plants
{
    public class Plant
    {
        [XmlAttribute("name")]
        public string Name;

        [XmlElement("property")]
        public Property[] Properties;

        public string Identifier
        {
            get { return ClipsTools.MakeIdentifier(Name); }
        }
	
        public void WriteRule(TextWriter output)
        {
            output.WriteLine("(defrule plant_{0}", Identifier);

            foreach (Property property in Properties)
                property.WriteQueries(output);

            output.WriteLine("=>");
            output.WriteLine("\t(assert (plant \"{0}\"))", Name);
            output.WriteLine(")");
        }
    }
}
