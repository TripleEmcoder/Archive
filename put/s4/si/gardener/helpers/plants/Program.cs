using System;
using System.Collections.Generic;
using System.Text;

using System.IO;
using System.Xml.Serialization;

namespace plants
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(Encyclopedia));

            using (StreamReader input = new StreamReader(args[0]))
            using (StreamWriter output = new StreamWriter(args[1]))
                ((Encyclopedia)serializer.Deserialize(input)).WriteRules(output);
        }
    }
}
