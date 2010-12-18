using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Xml.Linq;
using Fluent.IO;
using HtmlAgilityPack;

namespace FactFinder
{
    public class Triple
    {
        private readonly string subject;
        private readonly string predicate;
        private readonly string @object;

        public Triple(string subject, string predicate, string @object)
        {
            this.subject = subject;
            this.predicate = predicate;
            this.@object = @object;
        }

        public override string ToString()
        {
            return string.Format("{0} {1} {2}", subject, predicate, @object);
        }
    }

    class Page
    {
        private readonly Path path;
        private readonly string subject;
        private readonly HtmlNode root;

        public Page(Path path)
        {
            this.path = path;
            subject = path.FileNameWithoutExtension;
            var document = new HtmlDocument();
            document.Load(path.FullPath);
            root = document.DocumentNode;
        }

        public IEnumerable<Triple> Triples
        {
            get
            {
                yield return CreateTriple("loadedFrom", path.FullPath);
                yield return CreateTriple("name", GetFromId("firstHeading"));

                if (HasInfobox)
                {
                    foreach (var triple in ProcessWhenWhere(GetFromInfobox("Born"), "born"))
                        yield return triple;

                    foreach (var triple in ProcessWhenWhere(GetFromInfobox("Died"), "died"))
                        yield return triple;

                    foreach (var education in GetFromInfobox("Education"))
                    {
                        var title = new Regex(@"(from|at) ([\w\s]+)");
                        var match = title.Match(education);

                        if (match.Success)
                            yield return CreateTriple("education", match.Groups[2].Value);
                        else
                            yield return CreateTriple("education", education);
                    }
                }
            }
        }

        private IEnumerable<Triple> ProcessWhenWhere(string[] lines, string prefix)
        {
            var year = new Regex(@"(\d{4})");
            var sb = new StringBuilder();

            foreach (var line in lines)
            {
                var match = year.Match(line);

                if (match.Success)
                    yield return CreateTriple(prefix + "When", match.Groups[1].Value);
                else
                    sb.Append(line);
            }

            if (sb.Length > 0)
                yield return CreateTriple(prefix + "Where", sb.ToString());
        }

        private Triple CreateTriple(string predicate, string @object)
        {
            return new Triple(subject, predicate, @object);
        }

        private string GetFromId(string name)
        {
            return root.SelectSingleNode(string.Format("id('{0}')", name)).InnerText;
        }

        private bool HasInfobox
        {
            get { return root.SelectSingleNode("//table[contains(@class, 'infobox')]") != null; }
        }

        private string[] GetFromInfobox(string predicate)
        {
            var query = string.Format("//table[contains(@class, 'infobox')]//tr[th = '{0}']/td", predicate);
            var node = root.SelectSingleNode(query);

            if (node == null)
                return new string[0];

            var indexes = new Regex(@"\[\d+\]");
            return indexes.Replace(node.InnerText, "").Split('\n');
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var triples = Path
                .Get("../../wiki")
                .Files(f => f.Extension == ".html")
                .Take(20)
                .Select(f => new Page(f))
                .SelectMany(p => p.Triples);

            foreach (var triple in triples)
                Console.WriteLine(triple);
        }
    }
}
