using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MdbgSample
{
    partial class Program
    {
        private static void RunDebugee(string type)
        {
            switch (type)
            {
                case "ok":
                    A(1);
                    break;

                case "user":
                    A(2);
                    break;

                case "zero":
                    A(0);
                    break;

                case "loop":
                    L();
                    break;
            }

            Console.WriteLine("Press any key...");
            Console.ReadLine();
        }

        private static void A(int i)
        {
            try
            {
                B(i);
            }
            catch (Exception exception)
            {
                //symulujemy ogólny mechanizm łapania błedów, taki sam mają:
                // - ASP.NET (YSOD), 
                // - WinForms (okienko)
                // - i aplikacje konsolowe (stack trace)

                //możemy tutaj wypisać wartość i, ale co z x i y?
                Console.WriteLine("{0}: i = {1}", exception.Message, i);
            }
        }

        private static void B(int i)
        {
            //skomplikowane obliczenia, których nie da się zrobić poza programem
            var x = i*44 + 1337;
            C(i, x);
        }

        private static void C(int i, int x)
        {
            //zupełnie nieoczekiwany wyjątek spowodowany magicznym układem liczb
            if (i == 2)
                throw new InvalidOperationException();

            //wyjątki mogą też pochodzić z samego .NET Framework! (i == 0)
            var y = x / i;
        }

        private static void L()
        {
            var x = 1;

            for (int i = 1; i < 10; i++)
            {
                x = x * i;
            }
        }
    }
}
