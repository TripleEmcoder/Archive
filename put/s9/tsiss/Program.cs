using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Xml.Linq;
using HtmlAgilityPack;
using QuickGraph.Algorithms;
using QuickGraph.Algorithms.ConnectedComponents;
using QuickGraph.Algorithms.Search;
using SemWeb;
using SemWeb.Query;
using SemWeb.Remote;
using Path = Fluent.IO.Path;
using QuickGraph;

namespace FactFinder
{
    class Program
    {
        private const string mys = "urn:75922/static/";
        private const string myd = "urn:75922/dynamic/";
        private const string dbo = "http://dbpedia.org/ontology/";
        private const string foaf = "http://xmlns.com/foaf/0.1/";

        [STAThread]
        static void Main(string[] args)
        {
            var root = Path.Get("../..");
            var dbpedia = root.Combine("dbpedia.xml");
            var dbpedia2 = root.Combine("dbpedia2.xml");
            var cache = root.Combine("Downloads");

            MemoryStore store;

            //if (!dbpedia2.Exists)
            if (true)
            {
                if (!dbpedia.Exists)
                    ExecuteQuery(dbpedia);

                store = LoadResults(dbpedia);
                FilterDuplicates(store);
                MergePredicates(store, mys + "birth", dbo + "birthPlace", dbo + "birthYear");
                MergePredicates(store, mys + "death", dbo + "deathPlace", dbo + "deathYear");
                ParseFiles(store, cache);
                SaveResults(store, dbpedia2);
            }
            else
            {
                store = LoadResults(dbpedia2);
            }

            if (!cache.Exists)
                cache.CreateDirectories();

            //using (var client = new WebClient())
            //{
            //    foreach (var predicate in new[] { foaf + "page", dbo + "thumbnail" })
            //        foreach (var result in store.Select(new Statement(null, predicate, null)).OrderBy(result => result.Subject.Uri))
            //            DownloadResource(client, result, cache);
            //}

            Console.WriteLine("Creating edges...");
            var edges = CreateEdges(store, cache).ToArray();

            Console.WriteLine("Computing components...");
            var map = new Dictionary<Vertex, int>();
            //edges.ToUndirectedGraph<Vertex, Edge>().ConnectedComponents(map);
            edges.ToBidirectionalGraph<Vertex, Edge>().WeaklyConnectedComponents(map);

            Console.WriteLine("Building subgraphs...");
            var subgraphs = map
                .GroupBy(pair => pair.Value)
                .OrderByDescending(group => group.Count())
                .Take(10)
                //.Select(group => group.Select(pair => pair.Key).ToArray())
                .Select(group => GetGroupEdges(group.Select(pair => pair.Key), edges).ToBidirectionalGraph<Vertex, Edge>())
                .ToArray();

            Console.WriteLine("Cleaning subgraphs...");
            foreach (var graph in subgraphs)
                graph.RemoveVertexIf(vertex => vertex is LiteralVertex && graph.OutDegree(vertex) + graph.InDegree(vertex) < 2);

            foreach (var group in subgraphs)
            {
                Console.WriteLine("Count = {0}", group.VertexCount);
                //foreach (var vertex in group.Vertices)
                //    Console.WriteLine("\t{0}", vertex);
            }

            Console.WriteLine("Initializing viewer...");
            var viewer = new Viewer();
            viewer.DataContext = subgraphs;
            viewer.ShowDialog();
        }

        private static void ExecuteQuery(Path cache)
        {
            var namespaces =
                new[]
                    {
                        new {Prefix = "foaf", Uri = foaf},
                        new {Prefix = "dbo", Uri = dbo},
                        new {Prefix = "dbp", Uri = "http://dbpedia.org/property/"},
                        new {Prefix = "skos", Uri = "http://www.w3.org/2004/02/skos/core#"},
                        new {Prefix = "xsd", Uri = "http://www.w3.org/2001/XMLSchema#"},
                    };

            var attributes =
                new[]
                    {
                        new {Name = "foaf:page", Variable = "page"},
                        new {Name = "dbo:thumbnail", Variable = "photo"},
                        new {Name = "foaf:name", Variable = "name"},
                        new {Name = "dbo:abstract", Variable = "description"},
                        new {Name = "dbo:birthYear", Variable = "birthYear"},
                        new {Name = "dbo:birthPlace", Variable = "birthPlace"},
                        new {Name = "dbo:deathYear", Variable = "deathYear"},
                        new {Name = "dbo:deathPlace", Variable = "deathPlace "},
                        new {Name = "dbp:children", Variable = "child "},
                        new {Name = "dbp:parents", Variable = "parent "},
                    };

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

            query.AppendLine("FILTER (bound(?name) && lang(?name) = 'en') .");
            query.AppendLine("FILTER (!bound(?description) || lang(?description) = 'en') .");
            //query.AppendLine("FILTER (!bound(?birthYear) || datatype(?birthYear) = xsd:gYear) .");
            //query.AppendLine("FILTER (!bound(?deathYear) || datatype(?deathYear) = xsd:gYear) .");
            query.AppendLine("} ORDER BY ?person");
            //query.AppendLine("LIMIT 20");

            Console.WriteLine(query);

            using (var writer = new RdfXmlWriter(cache.FullPath))
            {
                foreach (var @namespace in namespaces)
                    writer.Namespaces.AddNamespace(@namespace.Uri, @namespace.Prefix);

                var source = new SparqlHttpSource("http://dbpedia.org/sparql");
                source.RunSparqlQuery(query.ToString(), writer);
            }
        }

        private static MemoryStore LoadResults(Path file)
        {
            var store = new MemoryStore();

            using (var reader = new RdfXmlReader(file.FullPath))
                reader.Select(store);

            Console.WriteLine("Loaded {0} statements.", store.StatementCount);

            return store;
        }

        private static void SaveResults(MemoryStore store, Path file)
        {
            using (var writer = new RdfXmlWriter(file.FullPath))
                writer.Write(store);

            Console.WriteLine("Wrote {0} statements.", store.StatementCount);
        }

        private static void FilterDuplicates(MemoryStore store)
        {
            var statements = store
                .Select(new Statement(null, null, null))
                .GroupBy(statement => new { Subject = statement.Subject.Uri, Predicate = statement.Predicate.Uri })
                .Select(group => group.First())
                .ToArray();

            store.Clear();
            foreach (var statement in statements)
                store.Add(statement);

            Console.WriteLine("Filtered to {0} statements.", store.StatementCount);
        }

        private static void MergePredicates(MemoryStore store, string merged, string entity, params string[] others)
        {
            var groups = store
                .Select(new Statement(null, entity, null))
                .Select(statement => new
                                         {
                                             Main = statement,
                                             Others = others
                                         .Select(other => store.SelectSingle(new Statement(statement.Subject, other, null)))
                                         .Where(other => other.HasValue)
                                         .Select(other => other.Value)
                                         .ToArray()
                                         })
                .Where(group => group.Others.Length > 0)
                .ToArray();

            //foreach (var group in groups)
            //{
            //    store.Remove(group.Main);
            //    foreach (var other in group.Others)
            //        store.Remove(other);
            //}

            foreach (var group in groups)
            {
                var values = group.Others.Select(other => other.Object).Cast<Literal>().Select(GetLiteralValue).ToArray();
                var uri = string.Join("/", new[] { group.Main.Object.Uri }.Concat(values));

                store.Add(new Statement(group.Main.Subject, merged, new Entity(uri)));

                var name = GetEntityName(store, new Uri(group.Main.Object.Uri));

                if (values.Length > 0)
                    name = string.Format("{0} ({1})", name, string.Join(", ", values));

                store.Add(new Statement(uri, foaf + "name", new Literal(name)));
            }

            Console.WriteLine("Merged to {0} statements.", store.StatementCount);
        }

        private static void ParseFiles(MemoryStore store, Path cache)
        {
            Console.WriteLine("Searching cross-references...");

            foreach (var statement in store.Select(new Statement(null, foaf + "page", null)).OrderBy(statement => statement.Subject.Uri))
            {
                var file = GetResourceCache(statement, cache);

                if (file.Exists)
                {
                    Console.WriteLine("\t{0}", GetEntityName(store, new Uri(statement.Subject.Uri)));

                    var document = new HtmlDocument();
                    document.Load(file.FullPath);

                    foreach (var node in document.DocumentNode.SelectNodes("//div[@id='bodyContent']/p//a[@href]"))
                    {
                        var uri = new Uri(new Uri(statement.Object.Uri), node.Attributes["href"].Value);
                        var tag = GetBeforeWords(node, 4).Concat(new[] { node.InnerText }).Concat(GetAfterWords(node, 4));

                        var predicate = StripNonAscii(string.Join("-", tag));
                        foreach (var stop in new[] { "&", "#", ";", ":", ",", ".", " ", "(", ")", "[", "]", "\"", "'", "$" })
                            predicate = predicate.Replace(stop, "");

                        predicate = myd + predicate;

                        var entity = store.SelectSingle(new Statement(null, foaf + "page", new Entity(uri.AbsoluteUri)));

                        if (entity.HasValue)
                        {
                            if (entity.Value.Subject != statement.Subject)
                            {
                                Console.WriteLine("\t\t[{0}] {1} = {2}", predicate, node.InnerText, uri.AbsoluteUri);
                                store.Add(new Statement(statement.Subject, new Entity(predicate), entity.Value.Subject));
                            }
                        }
                        else
                        {
                            //Console.WriteLine("\t\t[{0}] {1} = {2}", predicate, node.InnerText, uri.AbsoluteUri);
                            //store.Add(new Statement(statement.Subject, new Entity(predicate), new Entity(uri.AbsoluteUri)));
                        }
                    }
                }
            }
        }

        private static string StripNonAscii(string text)
        {
            var converter = Encoding.GetEncoding(Encoding.ASCII.EncodingName, new EncoderReplacementFallback(string.Empty), new DecoderExceptionFallback());
            return Encoding.ASCII.GetString(Encoding.Convert(Encoding.UTF8, converter, Encoding.UTF8.GetBytes(text)));
        }

        private static string[] GetBeforeWords(HtmlNode node, int count)
        {
            if (node.PreviousSibling == null)
                return new string[0];

            return node.PreviousSibling.InnerText.TrimEnd().Split(' ').Reverse().Take(count).Reverse().ToArray();
        }

        private static string[] GetAfterWords(HtmlNode node, int count)
        {
            if (node.NextSibling == null)
                return new string[0];

            return node.NextSibling.InnerText.TrimStart().Split(' ').Take(count).ToArray();
        }

        private static void DownloadResource(WebClient client, Statement statement, Path path)
        {
            var file = GetResourceCache(statement, path);

            if (!file.Exists)
            {
                Console.WriteLine("Downloading {0}...", statement.Object.Uri);
                try
                {
                    client.DownloadFile(statement.Object.Uri, file.FullPath);
                }
                catch (Exception exception)
                {
                    Console.WriteLine(exception.Message);
                }
            }
        }

        private static Path GetResourceCache(Statement statement, Path cache)
        {
            var name = Path.Get(statement.Subject.Uri).FileName.ToLower();
            var extension = Path.Get(statement.Object.Uri).Extension.ToLower();

            if (extension == "" || extension.StartsWith("._"))
                extension = ".html";

            return cache.Combine(name + extension);
        }

        private static IEnumerable<Edge> CreateEdges(MemoryStore store, Path cache)
        {
            var entityVertices = new Dictionary<Uri, EntityVertex>();
            var literalVertices = new Dictionary<string, LiteralVertex>();

            Func<Uri, EntityVertex> getEntityVertex =
                uri =>
                {
                    if (!entityVertices.ContainsKey(uri))
                    {
                        var name = GetEntityName(store, uri);
                        var photo = GetEntityPhoto(store, uri, cache);
                        entityVertices[uri] = new EntityVertex(uri, name, photo);
                    }

                    return entityVertices[uri];
                };

            Func<string, LiteralVertex> getLiteralVertex =
                literal =>
                {
                    if (!literalVertices.ContainsKey(literal))
                        literalVertices[literal] = new LiteralVertex(literal);

                    return literalVertices[literal];
                };

            Func<Resource, Vertex> getResourceVertex =
                resource =>
                {
                    if (resource.Uri != null)
                        return getEntityVertex(new Uri(resource.Uri));

                    if (resource is Literal)
                        return getLiteralVertex(GetLiteralValue(resource as Literal));

                    throw new NotSupportedException();
                };

            Func<IEnumerable<IEnumerable<Statement>>, Func<Vertex, Vertex, Uri, Edge>, IEnumerable<Edge>> getEdges =
                (results, ctor) =>
                {
                    return results
                        //merge all query results
                        .SelectMany(result => result)
                        //.OrderBy(statement => statement.Subject.Uri)
                        //.ThenBy(statement => statement.Predicate.Uri)
                        .Select(statement => ctor(getEntityVertex(new Uri(statement.Subject.Uri)), getResourceVertex(statement.Object), new Uri(statement.Predicate.Uri)));
                };

            var statements = store.Select(new Statement(null, null, null));

            var forward = getEdges(new[]
                                       {
                                           //store.Select(new Statement(null, dbo + "deathYear", null)),
                                           store.Select(new Statement(null, dbo + "deathPlace", null)),
                                           //statements.Where(statement => statement.Predicate == mys + "death"),
                                           statements.Where(statement => statement.Predicate.Uri.StartsWith(myd)),
                                       },
                                   (entity, resource, predicate) => new Edge(entity, resource, predicate));

            var backward = getEdges(new[]
                                        {
                                            //store.Select(new Statement(null, dbo + "birthYear", null)),
                                            store.Select(new Statement(null, dbo + "birthPlace", null)),
                                            //statements.Where(statement => statement.Predicate == mys + "birth"),
                                            statements.Where(statement => statement.Predicate.Uri.StartsWith(myd)),
                                        },
                                    (entity, resource, predicate) => new Edge(resource, entity, predicate));

            return forward.Concat(backward);
        }

        private static string GetLiteralValue(Literal literal)
        {
            if (literal.DataType == "http://www.w3.org/2001/XMLSchema#gYear")
                //return Math.Truncate(1.0 * DateTime.Parse(literal.Value).Year / 100) * 100).ToString();
                //return DateTime.Parse(literal.Value).Year / 10 * 10).ToString();
                return DateTime.Parse(literal.Value).Year.ToString();

            throw new NotSupportedException();
        }

        private static Path GetEntityPhoto(MemoryStore store, Uri uri, Path cache)
        {
            return store.Select(new Statement(uri.AbsoluteUri, dbo + "thumbnail", null))
                .Select(statement => GetResourceCache(statement, cache))
                .FirstOrDefault();
        }

        private static string GetEntityName(MemoryStore store, Uri uri)
        {
            var name = store.Select(new Statement(uri.AbsoluteUri, foaf + "name", null))
                .Select(statement => statement.Object)
                .Cast<Literal>()
                .Select(literal => literal.Value)
                .FirstOrDefault();

            if (name == null)
                name = Path.Get(uri.AbsolutePath).FileName;

            return name;
        }

        private static IEnumerable<Edge> GetGroupEdges(IEnumerable<Vertex> group, IEnumerable<Edge> edges)
        {
            return group.SelectMany(vertex => edges.Where(edge => edge.Source == vertex || edge.Target == vertex)).Distinct();
        }
    }
}
