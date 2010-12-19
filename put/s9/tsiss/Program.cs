using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Xml.Linq;
using HtmlAgilityPack;
using QuickGraph.Algorithms.ConnectedComponents;
using QuickGraph.Algorithms.Search;
using SemWeb;
using SemWeb.Query;
using SemWeb.Remote;
using Path = Fluent.IO.Path;
using QuickGraph;

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
            /*
            var triples = Path
                .Get("../../wiki")
                .Files(f => f.Extension == ".html")
                .Take(20)
                .Select(f => new Page(f))
                .SelectMany(p => p.Triples);

            foreach (var triple in triples)
                Console.WriteLine(triple);
             * */

            var namespaces =
                new[]
                    {
                        new {Prefix = "foaf", Uri = "http://xmlns.com/foaf/0.1/"},
                        new {Prefix = "dbo", Uri = "http://dbpedia.org/ontology/"},
                        new {Prefix = "dbp", Uri = "http://dbpedia.org/property/"},
                        new {Prefix = "skos", Uri = "http://www.w3.org/2004/02/skos/core#"},
                    };

            var attributes =
                new[]
                    {
                        new {Name = "foaf:page", Variable = "page"},
                        new {Name = "dbo:thumbnail", Variable = "photo"},
                        new {Name = "foaf:name", Variable = "name"},
                        new {Name = "dbo:abstract", Variable = "description"},
                        new {Name = "dbo:birthDate", Variable = "birthDate"},
                        new {Name = "dbo:birthPlace", Variable = "birthPlace"},
                        new {Name = "dbo:deathDate", Variable = "deathYear"},
                        new {Name = "dbo:deathPlace", Variable = "deathDate "},
                        new {Name = "dbp:children", Variable = "child "},
                        new {Name = "dbp:parents", Variable = "parent "},
                    };

            var root = Path.Get("../..");
            var dbpedia = root.Combine("dbpedia.xml");

            if (!dbpedia.Exists)
            {
                Console.WriteLine("Refreshing DBpedia data...");
                var query = new StringBuilder();

                foreach (var @namespace in namespaces)
                    query.AppendLine(string.Format("PREFIX {0}: <{1}>", @namespace.Prefix, @namespace.Uri));

                query.AppendLine("CONSTRUCT {");

                foreach (var attribute in attributes)
                    query.AppendLine(string.Format("?person {0} ?{1} .", attribute.Name, attribute.Variable));

                query.AppendLine("} WHERE {");
                query.AppendLine("?person skos:subject <http://dbpedia.org/resource/Category:American_inventors> .");

                foreach (var attribute in attributes)
                    query.AppendLine(string.Format("OPTIONAL {{ ?person {0} ?{1} . }}", attribute.Name, attribute.Variable));

                query.AppendLine("FILTER (bound(?name) && LANG(?name) = 'en') .");
                query.AppendLine("FILTER (!bound(?description) || LANG(?description) = 'en') .");
                query.AppendLine("} ORDER BY ?person");

                Console.WriteLine(query);

                using (var writer = new RdfXmlWriter(dbpedia.FullPath))
                {
                    foreach (var @namespace in namespaces)
                        writer.Namespaces.AddNamespace(@namespace.Uri, @namespace.Prefix);

                    var source = new SparqlHttpSource("http://dbpedia.org/sparql");
                    source.RunSparqlQuery(query.ToString(), writer);
                }
            }

            var store = new MemoryStore();
            using (var reader = new RdfXmlReader(dbpedia.FullPath))
                reader.Select(store);

            using (var client = new WebClient())
            {
                var wiki = root.Combine("wiki");
                Path.CreateDirectory(wiki.FullPath);

                //DownloadResources(store, client, "http://xmlns.com/foaf/0.1/page", wiki, ".html");
                //DownloadResources(store, client, "http://dbpedia.org/ontology/thumbnail", wiki, ".jpg");
            }

            var results =
                new[]
                    {
                        store.Select(new Statement(null, "http://dbpedia.org/ontology/birthDate", null)),
                        //store.Select(new Statement(null, "http://dbpedia.org/ontology/birthPlace", null)),
                        store.Select(new Statement(null, "http://dbpedia.org/ontology/deathDate", null)),
                        //store.Select(new Statement(null, "http://dbpedia.org/ontology/deathPlace", null)),
                    };

            var edges = results.SelectMany(result => result.Select(statement => StatementToEdge(statement)));
            var graph = edges.ToUndirectedGraph<string, Edge<string>>();
            var map = new Dictionary<string, int>();

            var algo = new ConnectedComponentsAlgorithm<string, Edge<string>>(graph);
            algo.Compute();

            foreach (var group in algo.Components.GroupBy(pair => pair.Value).OrderByDescending(group => group.Count()).Take(10))
            {
                Console.WriteLine("Count = {0}", group.Count());
                foreach (var vertex in algo.Components.Where(pair => pair.Value == group.Key).Select(pair => pair.Key))
                    Console.WriteLine("\t{0}", vertex);
            }
        }

        private static Edge<string> StatementToEdge(Statement statement)
        {
            return new Edge<string>(statement.Subject.Uri, GetResourceData(statement.Object));
        }

        private static string GetResourceData(Resource resource)
        {
            if (resource.Uri != null)
                return resource.Uri;

            if (resource is Literal)
            {
                var literal = resource as Literal;

                //if (literal.DataType == "http://www.w3.org/2001/XMLSchema#gYear")
                    //return (Math.Truncate(1.0*DateTime.Parse(literal.Value).Year/100)*100).ToString();
                    //return (DateTime.Parse(literal.Value).Year / 10 * 10).ToString();

                return literal.Value;
            }

            return null;
        }

        private static string GetPersonName(Entity person)
        {
            return Path.Get(person.Uri).FileName;
        }

        private static void DownloadResources(MemoryStore store, WebClient client, string predicate, Path path, string extension)
        {
            foreach (var result in store.Select(new Statement(null, predicate, null)).OrderBy(result => result.Subject.Uri))
            {
                var page = path.Combine(GetPersonName(result.Subject) + extension);

                if (!page.Exists)
                {
                    Console.WriteLine("Downloading {0}...", result.Object.Uri);
                    try
                    {
                        client.DownloadFile(result.Object.Uri, page.FullPath);
                    }
                    catch (Exception exception)
                    {

                    }
                }
            }
        }
    }
}
