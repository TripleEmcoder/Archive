using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeTwoFolderSyncAuto
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            var comparer = new Comparer();
            var outlook = new Outlook();
            var addin = new FolderSyncConfiguration();
            var folders = new List<string[]>();
            var pairs = new List<KeyValuePair<string[], string[]>>();

            //outlook.CreateFolder(new[] { "Personal Folders", "Test", DateTime.Now.ToString() });
            //return;

            //addin.AddSyncPairs(new[]
            //                       {
            //                           new KeyValuePair<string[], string[]>(
            //                               new[] {"Personal Folders", "Archive"},
            //                               new[] {"marcin.mikolajczak@hotmail.com", "Archive"})
            //                       });

            //return;

            Console.WriteLine("Available folders:");

            foreach (string[] path in addin.GetAvailableFolders())
            {
                var realPath = DecodePath(path);
                Console.WriteLine(FormatPath(realPath));
                folders.Add(realPath);
            }

            Console.WriteLine("Present sync pairs:");

            foreach (KeyValuePair<string[], string[]> pair in addin.GetSyncPairs())
            {
                var realPair = new KeyValuePair<string[], string[]>(DecodePath(pair.Key), DecodePath(pair.Value));
                Console.WriteLine(FormatPair(realPair));
                pairs.Add(realPair);
            }

            string primaryRoot = "Personal Folders";
            string secondaryRoot = "marcin.mikolajczak@hotmail.com";

            var primaryFolders = folders
                .Where(folder => folder.Length >= 2 && folder[0] == primaryRoot && folder[1] == "Archive")
                .Select(folder => folder.Skip(1).ToArray());

            var secondaryFolders = folders
                .Where(folder => folder.Length >= 2 && folder[0] == secondaryRoot && folder[1] == "Archive")
                .Select(folder => folder.Skip(1).ToArray());

            var missingPrimaryFolders = secondaryFolders.Except<string[]>(primaryFolders, comparer);
            var missingSecondaryFolders = primaryFolders.Except<string[]>(secondaryFolders, comparer);

            Console.WriteLine("Missing primary folders:");

            foreach (string[] path in missingPrimaryFolders)
            {
                string[] fullPath = new[] { primaryRoot }.Concat(path).ToArray();
                Console.WriteLine(FormatPath(fullPath));
                //outlook.CreateFolder(fullPath);
            }

            Console.WriteLine("Missing secondary folders:");

            foreach (string[] path in missingSecondaryFolders)
            {
                string[] fullPath = new[] { secondaryRoot }.Concat(path).ToArray();
                Console.WriteLine("{0} ", FormatPath(fullPath));
                //outlook.CreateFolder(fullPath);
            }

            var newPairs = new List<KeyValuePair<string[], string[]>>();
            var newFolders = primaryFolders.Intersect<string[]>(secondaryFolders, comparer);

            Console.WriteLine("New sync pairs:");

            foreach (string[] path in newFolders)
            {
                string[] primaryFullPath = new[] { primaryRoot }.Concat(path).ToArray();
                string[] secondaryFullPath = new[] { secondaryRoot }.Concat(path).ToArray();
                var newRealPair = new KeyValuePair<string[], string[]>(primaryFullPath, secondaryFullPath);

                if (!pairs.Contains<KeyValuePair<string[], string[]>>(newRealPair, comparer))
                {
                    Console.WriteLine(FormatPair(newRealPair));
                    var newPair = new KeyValuePair<string[], string[]>(EncodePath(newRealPair.Key), EncodePath(newRealPair.Value));
                    newPairs.Add(newPair);
                }
            }

            addin.AddSyncPairs(newPairs);
        }

        private static string FormatPair(KeyValuePair<string[], string[]> pair)
        {
            return string.Format("{0} <-> {1}", FormatPath(pair.Key), FormatPath(pair.Value));
        }

        private static string FormatPath(string[] path)
        {
            return string.Join(@" \ ", path);
        }

        private static string[] DecodePath(string[] path)
        {
            if (path.Length == 2 && path[0] == "marcin.mikolajczak@hotmail.com")
                path = new[] { path[0] }.Concat(path[1].Split('-')).ToArray();

            return path;
        }

        private static string[] EncodePath(string[] path)
        {
            if (path.Length >= 1 && path[0] == "marcin.mikolajczak@hotmail.com")
                path = new[] { path[0], string.Join("-", path.Skip(1).ToArray()) };

            return path;
        }
    }
}
