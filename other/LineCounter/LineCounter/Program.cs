using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace LineCounter
{
    class Program
    {
        private static string[] exceptions = { ".svn", "bin", "obj" };
        private static string[] extensions = { "c", "h", "cpp", "hpp", "cs", "java", "php" };

        public static void Main(string[] args)
        {
            if (Directory.Exists(args[1]))
                Recurse(new DirectoryInfo(args[1]), 0, int.Parse(args[0]));
        }

        private static int Recurse(DirectoryInfo parent, int current, int max)
        {
            if (max >= 0 && current > max)
                return 0;

            if (Array.IndexOf(exceptions, parent.Name) >= 0)
                return 0;

            int count = 0;

            foreach (FileInfo child in parent.GetFiles())
                count += Count(child);

            foreach (DirectoryInfo child in parent.GetDirectories())
                count += Recurse(child, current + 1, max);

            Console.WriteLine(parent.FullName + " - " + count);

            return count;
        }

        private static int Count(FileInfo file)
        {
            if (Array.IndexOf(extensions, file.Extension.Trim('.')) < 0)
                return 0;

            int count = 0;

            using (StreamReader reader = file.OpenText())
            {
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine().Trim();

                    if (line.Length == 0)
                        continue;

                    if (line.StartsWith("//"))
                        continue;

                    count++;
                }
            }

            return count;
        }
    }
}
