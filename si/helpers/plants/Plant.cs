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
            get
            {
                string result = Name.ToLower();

                result = result.Replace(' ', ' ');
                result = result.Replace('ą', 'a');
                result = result.Replace('ć', 'c');
                result = result.Replace('ę', 'e');
                result = result.Replace('ć', 'c');
                result = result.Replace('ń', 'n');
                result = result.Replace('ś', 's');
                result = result.Replace('ź', 'z');
                result = result.Replace('ż', 'z');

                result = result.Replace(' ', '_');
                result = result.Replace("\'", "");

                return result;
            }
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
