using System;
using SymbolSource.DemoLibrary.Calculator;

namespace SourceStepping
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("test");
            
            var c = new SimpleCalculator().Add(1, 2);
            Console.WriteLine("1 + 2 = {0}", c);

            VisualStudioWhenHit();
        }

        private static void VisualStudioWhenHit()
        {
            var x = 1;

            for (int i = 1; i < 10; i++)
            {
                x = x*i;
            }
        }
    }
}
