using System;
using System.IO;
using System.Reflection;
using Mono.Cecil;
using Mono.Cecil.Cil;

namespace PdbInfo
{
    class Program
    {
        static void Main(string[] args)
        {
            var x = 1;

            for (int i = 1; i < 10; i++)
            {
                x =
                    x
                    *
                    i;
                Console.WriteLine("{0} - {1}", i, x);
            }

            Dump(true);
        }

        //doinstaluj Mono.Cecil z NuGeta!
        private static void Dump(bool symbols)
        {
            var assembly = AssemblyDefinition.ReadAssembly(
                Assembly.GetExecutingAssembly().Location,
                new ReaderParameters
                    {
                        ReadSymbols = symbols
                    });

            Console.WriteLine(assembly.EntryPoint.FullName);

            foreach (var instruction in assembly.EntryPoint.Body.Instructions)
                Console.WriteLine("{0} {1}", instruction, FormatSequencePoint(instruction.SequencePoint));
        }

        private static string FormatSequencePoint(SequencePoint point)
        {
            if (point == null)
                return null;

            return string.Format(
                " - {0}: ({1},{2}) - ({3}, {4})",
                Path.GetFileName(point.Document.Url), point.StartLine, point.StartColumn, point.EndLine, point.EndColumn);
        }
    }
}
