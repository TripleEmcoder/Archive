using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using porter;

namespace Lab1
{
    class Program
    {
        class WithTerms
        {
            private Dictionary<string, int> Terms { get; set; }

            protected WithTerms(IEnumerable<string> terms)
            {
                Terms = new Dictionary<string, int>();

                foreach (var term in terms)
                    Terms[term] = 0;
            }

            protected void AddTerm(string term)
            {
                if (Terms.ContainsKey(term))
                    Terms[term]++;
            }

            public int GetMaxTermCount()
            {
                return Terms.Values.Max();
            }

            public int GetTermCount(string term)
            {
                return Terms[term];
            }

            public bool HasTerm(string term)
            {
                return Terms[term] > 0;
            }
        }

        class Document : WithTerms
        {
            public string Title { get; private set; }
            public string StemmedTitle { get; private set; }
            public string Body { get; private set; }
            public string StemmedBody { get; private set; }

            public Document(IEnumerable<string> terms, string title, IEnumerable<string> body)
                : base(terms)
            {
                var stemmedTitle = StemLine(title);
                var stemmedBody = body.Select(line => StemLine(line));

                Title = title;
                StemmedTitle = string.Join(" ", stemmedTitle);
                Body = string.Join("\n", body);
                StemmedBody = string.Join("\n", body.Select(line => string.Join(" ", StemLine(line))));

                foreach (var term in stemmedBody.Aggregate(stemmedTitle, (current, line) => current.Concat(line)))
                    AddTerm(term);
            }

            public override string ToString()
            {
                return Title;
            }
        }

        class Query : WithTerms
        {
            public string Text { get; private set; }
            public string StemmedText { get; private set; }

            public Query(IEnumerable<string> terms, string text)
                : base(terms)
            {
                var stemmedText = StemLine(text);

                Text = text;
                StemmedText = string.Join(" ", stemmedText);

                foreach (var term in stemmedText)
                    AddTerm(term);
            }
        }

        static void Main(string[] args)
        {
            var ts = GetTerms();
            var ds = GetDocuments(ts);

            var d_tf = new double[ds.Count, ts.Count];
            for (int di = 0; di < ds.Count; di++)
            {
                var max = ds[di].GetMaxTermCount();

                for (int ti = 0; ti < ts.Count; ti++)
                    d_tf[di, ti] = 1.0 * ds[di].GetTermCount(ts[ti]) / max;
            }

            var t_idf = new double[ts.Count];
            for (int ti = 0; ti < ts.Count; ti++)
                t_idf[ti] = Math.Log10(1.0 * ds.Count / ds.Count(document => document.HasTerm(ts[ti])));

            var d_tf_idf = new double[ds.Count, ts.Count];
            for (int di = 0; di < ds.Count; di++)
                for (int ti = 0; ti < ts.Count; ti++)
                    d_tf_idf[di, ti] = d_tf[di, ti] * t_idf[ti];

            var d_v = new double[ds.Count];
            for (int di = 0; di < ds.Count; di++)
            {
                for (int ti = 0; ti < ts.Count; ti++)
                    d_v[di] += Math.Pow(d_tf_idf[di, ti], 2);
                d_v[di] = Math.Sqrt(d_v[di]);
            }

            Console.WriteLine("Terms:");
            foreach (var term in ts.OrderBy(term => term))
                Console.WriteLine("\t{0}*", term);

            while (true)
            {
                Console.WriteLine("Zapytanie:");
                Console.Write("\t");
                var q = new Query(ts, Console.ReadLine());

                var q_tf = new double[ts.Count];
                for (int ti = 0; ti < ts.Count; ti++)
                    q_tf[ti] = q.HasTerm(ts[ti]) ? 1 : 0;

                var q_tf_idf = new double[ts.Count];
                for (int ti = 0; ti < ts.Count; ti++)
                    q_tf_idf[ti] = q_tf[ti] * t_idf[ti];

                var q_v = 0.0;
                for (int ti = 0; ti < ts.Count; ti++)
                    q_v += Math.Pow(q_tf_idf[ti], 2);
                q_v = Math.Sqrt(q_v);

                var sim = new double[ds.Count];
                for (int di = 0; di < ds.Count; di++)
                {
                    for (int ti = 0; ti < ts.Count; ti++)
                        sim[di] += d_tf_idf[di, ti] * q_tf_idf[ti];

                    sim[di] /= d_v[di] * q_v;
                }

                Console.WriteLine("Results:");
                foreach (var di in Enumerable.Range(0, ds.Count).OrderByDescending(di => sim[di]))
                    Console.WriteLine("\t{0:0.0000}: {1}", sim[di], ds[di].Title);
            }
        }

        private static List<string> GetTerms()
        {
            var terms = new List<string>();

            using (var file = File.OpenText("keywords.txt"))
            {
                while (!file.EndOfStream)
                    terms.Add(StemLine(file.ReadLine()).First());
            }

            return terms;
        }

        private static List<Document> GetDocuments(IEnumerable<string> terms)
        {
            var documents = new List<Document>();

            using (var file = File.OpenText("documents.txt"))
            {
                while (!file.EndOfStream)
                {
                    var title = file.ReadLine();
                    var body = new List<string>();

                    while (!file.EndOfStream)
                    {
                        var line = file.ReadLine();

                        if (line == "")
                            break;

                        body.Add(line);
                    }

                    documents.Add(new Document(terms, title, body));
                }
            }
            return documents;
        }

        private static IEnumerable<string> StemLine(string line)
        {
            var words = line.Split(new[] { ' ', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);

            for (int i = 0; i < words.Length; i++)
                words[i] = StemWord(words[i]);

            return words;
        }

        private static string StemWord(string word)
        {
            var stemmer = new Stemmer();

            foreach (var letter in word)
                stemmer.add(letter);

            stemmer.stem();
            word = stemmer.ToString();

            word = word.ToLower();
            word = word.Trim(',', ';', ':', '.', '(', ')');

            switch (word)
            {
                case "fli":
                    return "fly";
                case "flight":
                    return "fly";
                case "fruiti":
                    return "fruit";
                default:
                    return word;
            }
        }
    }
}
