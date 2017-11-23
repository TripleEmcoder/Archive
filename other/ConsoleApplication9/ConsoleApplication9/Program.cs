using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;

namespace ConsoleApplication9
{
    class Program
    {
        static void Main(string[] args)
        {
            //Time(() => CPU(1000000), 10);
            Time(() => Exception(1000), 10);
        }

        private static void Time(Action action, int count)
        {
            var sum = 0L;

            for (var i = 0; i < count; i++)
            {
                var s = new Stopwatch();
                s.Start();
                action();
                s.Stop();
                sum += s.ElapsedMilliseconds;
                Thread.Sleep(1000);
            }
            Trace.WriteLine(sum / count);
            Console.WriteLine(sum / count);
        }

        private static void CPU(int count)
        {
            Array.Sort(Enumerable.Range(1, count).Reverse().ToArray());
        }

        private static void Exception(int count)
        {
            for (int i = 0; i < count; i++)
            {
                try
                {
                    throw new Exception();
                }
                catch
                {
                }
            }
        }
    }
}
