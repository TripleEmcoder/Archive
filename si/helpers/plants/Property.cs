﻿using System;
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
            if (Name == "grupa" ||
                Name == "podlewanie" ||
                Name == "nawożenie" ||
                Name == "stanowisko")
            {
                string[] parts = Value.Split(
                    new string[] { ", " }, StringSplitOptions.None);

                //if (!parts[0].Contains("nieokreślone"))
                output.WriteLine("\t(property \"{0}\" \"dowolne\"|\"{1}\")",
                    Name, parts[0].Replace(" lub ", "\"|\""));
            }

            if (Name == "pochodzenie")
            {
                string[] parts = Value.Split(
                    new string[] { ", " }, StringSplitOptions.None);

                //if (!parts[0].Contains("nieokreślone"))
                output.WriteLine("\t(property \"{0}\" \"dowolne\"|\"{1}\")",
                    Name, parts[0].Replace(" i ", "\"|\""));
            }

            if (Name == "kwiaty")
            {
                output.Write("\t(property \"kwiaty\" ");

                Dictionary<string, string[]> groups = new Dictionary<string, string[]>();

                groups["brak"] = new string[] { "brak", "rzadk" };
                groups["białe"] = new string[] { "biał", "siw", "kremow" };
                groups["czerwone"] = new string[] { "czerwon", "rdzaw", "bordow", "malinow" };
                groups["fioletowe"] = new string[] { "fioletow", "liliow" };
                groups["niebieskie"] = new string[] { "niebieskie", "błękit" };
                groups["pomarańczowe"] = new string[] { "pomarańczow" };
                groups["purpurowe"] = new string[] { "purpurow" };
                groups["różowe"] = new string[] { "różow", "pąsow" };
                groups["żółte"] = new string[] { "żółt", "złot" };
                groups["różnobarwne"] = new string[] { "różnobarwn" };

                List<string> selectors = new List<string>();
                string value = Value.ToLower();

                foreach (KeyValuePair<string, string[]> group in groups)
                    foreach (string part in group.Value)
                        if (value.Contains(part) && !selectors.Contains(group.Key))
                            selectors.Add(group.Key);

                if (selectors.Count == 0)
                    selectors.Add("inne");

                if (!selectors.Contains("brak"))
                    selectors.Insert(0, "dowolne");

                output.WriteLine("\"{0}\")", string.Join("\"|\"", selectors.ToArray()));
            }
        }
    }
}
