using System;
using System.Collections.Generic;
using System.Text;

using System.Globalization;
using System.IO;
using System.Text.RegularExpressions;
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
            #region Pozostałe

            if (Name == "grupa" ||
                Name == "podlewanie" ||
                Name == "nawożenie" ||
                Name == "stanowisko")
            {
                string[] parts = Value.Split(
                    new string[] { ", " }, StringSplitOptions.None);

                //if (!parts[0].Contains("nieokreślone"))
                output.WriteLine("\t(property \"{0}\" \"=\" \"dowolne\"|\"{1}\")",
                    Name, parts[0].Replace(" lub ", "\"|\""));
            }

            #endregion

            #region Pochodzenie

            if (Name == "pochodzenie")
            {
                string[] parts = Value.Split(
                    new string[] { ", " }, StringSplitOptions.None);

                //if (!parts[0].Contains("nieokreślone"))
                output.WriteLine("\t(property \"{0}\" \"=\" \"dowolne\"|\"{1}\")",
                    Name, parts[0].Replace(" i ", "\"|\""));
            }

            #endregion

            #region Kwiaty

            if (Name == "kwiaty")
            {
                output.Write("\t(property \"kwiaty\" \"=\" ");

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

            #endregion

            #region Rozmiary

            if (Name == "rozmiary")
            {
                #region Regex

                const string number = @"(\d+(,\d+)?)|metra";
                const string seperator = @"\s*(-|do)\s*";
                const string postfix = @"\w+";

                Regex regex = new Regex(String.Format(
                    @"((?<min>{0}){1})?(?<max>{0})\s*(?<unit>{2})",
                    number, seperator, postfix));

                #endregion

                #region Search

                int start = 0;

            Retry:
                Match match = regex.Match(Value, start);

                string min = match.Groups["min"].Value;
                string max = match.Groups["max"].Value;
                string unit = match.Groups["unit"].Value;

                if (unit == "latach")
                {
                    start = match.Index + match.Length;
                    goto Retry;
                }

                #endregion 

                if (min != "" || max != "" || unit != "")
                {
                    #region Parse

                    if (min == "")
                        min = "0";

                    if (max == "metra")
                    {
                        max = "1";
                        unit = "m";
                    }

                    if (unit.StartsWith("metr"))
                        unit = "m";

                    CultureInfo culture = CultureInfo.GetCultureInfo("pl-PL");
                    float _min = float.Parse(min, culture.NumberFormat);
                    float _max = float.Parse(max, culture.NumberFormat);

                    #endregion

                    #region Unit

                    if (unit == "cm")
                    {
                        _min *= 1;
                        _max *= 1;
                    }
                    else if (unit == "m")
                    {
                        _min *= 100;
                        _max *= 100;
                    }
                    else
                    {
                        throw new Exception(unit);
                    }

                    #endregion

                    #region Output

                    output.WriteLine("\t(property \"wysokość\" \">=\" ?min)");
                    output.WriteLine("\t(test (>= {0} ?min))", _min);

                    output.WriteLine("\t(property \"wysokość\" \"<=\" ?max)");
                    output.WriteLine("\t(test (<= {0} ?max))", _max);

                    #endregion
                }
            }

            #endregion
        }
    }
}
