using System;
using System.Collections.Generic;
using System.Text;

using System.IO;
using System.Xml.Serialization;

namespace plants
{
    public class Property
    {
        [XmlAttribute("name")]
        public string Name;

        [XmlAttribute("value")]
        public string Value;

        public void WriteQueries(TextWriter output)
        {
            if (Name == "podlewanie" ||
                Name == "nawożenie" ||
                Name == "stanowisko")
            {
                string[] parts = Value.Split(
                    new string[] { ", " }, StringSplitOptions.None);

                output.WriteLine("\t(property \"{0}\" \"dowolne\"|\"{1}\")",
                    Name, parts[0].Replace(" lub ", "\"|\""));
            }
        }
    }
}
