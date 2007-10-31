using System;
using System.Collections.Generic;
using System.Text;

using System.Reflection;

namespace Server
{
    class Program
    {
        static void Main(string[] args)
        {
            Assembly assembly = Assembly.GetExecutingAssembly();
            args = new string[] { assembly.Location };
            NUnit.ConsoleRunner.Runner.Main(args);
        }
    }
}
