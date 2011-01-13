using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Palindromader
{
    class Program
    {
        class Vertex
        {
            public Dictionary<char, Vertex> Succesors { get; private set; }
            public Dictionary<string, bool> Texts { get; private set; }
            public Dictionary<string, bool> AllTexts { get; private set; }

            public Vertex()
            {
                Succesors = new Dictionary<char, Vertex>();
                Texts = new Dictionary<string, bool>();
                AllTexts = new Dictionary<string, bool>();
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
            //Console.WriteLine("{0} {1} {2}", new string(buffer.ToArray()), vertex.Texts.Count, vertex.AllTexts.Count);

            foreach (var succesor in vertex.Succesors)
            {
                if (succesor.Value.Texts.Count == count)
                {
                    buffer.Add(succesor.Key);

                    if (buffer.Count > result.Length)
                    {
                        result = new string(buffer.ToArray());
                        //Console.WriteLine("New result: {0}", result);
                    }

                    Traverse(succesor.Value, count, ref result, buffer);
                    buffer.RemoveAt(buffer.Count - 1);
                }
            }
        }

        static void Main(string[] args)
        {
            var inputStream = Console.OpenStandardInput(1024);
            Console.SetIn(new StreamReader(inputStream, Console.InputEncoding));

            while (true)
            {
                Console.Write("Enter text: ");
                var text = Console.ReadLine();

                if (text == null)
                    break;

                text = text.ToLower();
                foreach (var token in new[] { "\"", "„", "”", " ", ".", ",", "–", "-", "!", "(", ")", ";", ":", "?", "…" })
                    text = text.Replace(token, "");

                Console.WriteLine("Processing text: {0}", text);

                var root = new Vertex();

                Build(root, text);
                Build(root, new string(text.Reverse().ToArray()));

                var result = "";
                Traverse(root, 2, ref result);
                Console.WriteLine("Longest result: {0} ({1})", result, result.SequenceEqual(result.Reverse()));
            }
        }

        /*
0) „Kobyła ma mały bok i krótkie nogi.” 
1) „Ta mała kobyła ma manny żywo je; żywiej zje i wyżej – o, wyżynna! – ma mały bok.” 
2) „I kominiarza i zduna zaraz cna jawa budzi w gwałt tła, w gwizd, ubaw - a janczara zanudzi zaraz.” 
3) „Wronę tycz - Iwono, ty rabuj okop spokoju barytonowi, czy tenorowi” 
4) „I lali masoni wydrom w mordy wino, sami lali!” - 9 - 
5) „A mason zrobi lożą Żoliborz: nosa ma do tego.” 
6) „Ma, Ireno! Sama? A po co tu ta kołdra? Gładko na szaro nas zrobi loża: Żoliborz, San oraz Sanok dał gardło katu! To co? Pa? A, masoneria!...” 
7) „I potwór-kujon gwałty też, o Boże, tytła, w gnoju krów topi.” 
8) „O, w tse-tse jest estyma dla życia, losu (kopy pokus) – o, laicy! Żal… damy tse-tse jestestwo?” 
9) „Co? Zakopane pyszne? Ten zsyp? E, na pokaz!” 
10) „Jak łyso było Gotom i Maurom! U-ha! Sama zaraza – masa humoru, A mimo to goły-bosy łkaj!” 
11) „Twa ocena: Wady – weto! Łzy! Marazm! Ech, ci cynicy! Ryciny cichcem za ramy złote wydawane, co?!” 
12) „Hasło słyszane na wiecu: No, Jim, jedz bób; zdejmij onuce, Iwan!” 
13) „A car: Bojarom Rady róg od imago nacinaj i piel! – a je jeża, i nawraca masona, i suką złowi pensa; ja na to: Do gęby ryż, o bracia moi, włóżmy tym umytym żółwiom, a i car Boży rybę-Godota na jasne piwo łzą kusi (a nosa ma car-Wania, że jej!... – ale i, pijanica, nogami do góry darmo Raj obraca!).”
         */
    }
}

