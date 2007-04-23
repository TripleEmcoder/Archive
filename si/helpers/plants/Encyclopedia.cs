using System;
using System.Collections.Generic;
using System.Text;

using System.IO;
using System.Xml.Serialization;

namespace plants
{
    [XmlRoot("encyclopedia")]
    public class Encyclopedia
    {
        [XmlElement("plant")]
        public Plant[] Plants;

        public void WriteRules(TextWriter output)
        {
            foreach (Plant plant in Plants)
                plant.WriteRule(output);
        }
    }
}
