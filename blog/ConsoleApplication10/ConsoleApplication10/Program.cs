using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PostSharp.Aspects;

namespace ClrDumpAspectDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Foo(1);
        }

        private static void Foo(int i)
        {
            Bar(i + 1);
        }

        private static void Bar(int i)
        {
            try
            {
                Throw(i + 1);
            }
            catch(Exception)
            {
            }
        }

        [ClrDumpAspect2]
        private static void Throw(int i)
        {
            if (i == 3)
            {
                //very complex calculation
                var j = i + 2;

                if (j == 5)
                    throw new CustomException();
            }

            if (i == 4)
                throw new CustomException();
        }
    }
}


