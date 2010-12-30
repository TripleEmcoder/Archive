using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Palindromader
{
    class Program
    {
        class Vertex
        {
            public Dictionary<char, Vertex> Succesors { get; private set; }
            public Dictionary<string, bool> Texts { get; private set; }

            public Vertex()
            {
                Succesors = new Dictionary<char, Vertex>();
                Texts = new Dictionary<string, bool>();
            }
        }

        private static void Build(Vertex root, string text)
        {
            foreach (var start in Enumerable.Range(0, text.Length))
            {
                var vertex = root;
                var index = start;

                while (index < text.Length && vertex.Succesors.ContainsKey(text[index]))
                {
                    vertex = vertex.Succesors[text[index++]];
                    vertex.Texts[text] = true;
                }

                while (index < text.Length)
                {
                    vertex.Succesors[text[index]] = new Vertex();
                    vertex = vertex.Succesors[text[index++]];
                    vertex.Texts[text] = true;
                }
            }
        }

        private static void Traverse(Vertex root, int count, ref string result)
        {
            Traverse(root, count, ref result, new List<char>());
        }

        private static void Traverse(Vertex vertex, int count, ref string result, List<char> buffer)
        {
            Console.WriteLine("{0} {1}", new string(buffer.ToArray()), vertex.Texts.Count);

            foreach (var succesor in vertex.Succesors)
            {
                if (succesor.Value.Texts.Count == count)
                {
                    buffer.Add(succesor.Key);
                    
                    if (buffer.Count > result.Length)
                        result = new string(buffer.ToArray());

                    Traverse(succesor.Value, count, ref result, buffer);
                    buffer.RemoveAt(buffer.Count - 1);
                }
            }
        }

        static void Main(string[] args)
        {
            while (true)
            {
                Console.Write("Enter text: ");
                var text = Console.ReadLine();

                if (text == null)
                    break;

                text = text.ToLower().Replace(" ", "");
                Console.WriteLine("Processing text: {0}", text);

                var root = new Vertex();

                Build(root, text);
                Build(root, new string(text.Reverse().ToArray()));

                var result = "";
                Traverse(root, 2, ref result);
                Console.WriteLine("Longest result: {0}", result);
            }
        }
    }
}

