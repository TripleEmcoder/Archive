using System;
using PP.DB.Inf75922.Model.Tests;

// Marcin Mikołajczak, 75922, czwartek, 13:30

namespace PP.DB.Inf75922.Runner
{
    class Program
    {
        static void Main(string[] args)
        {
            NUnit.ConsoleRunner.Runner.Main(
                new[]
                    {
                        typeof (LibraryTestFixture).Assembly.Location
                    });

            Console.ReadKey();
        }
    }
}
