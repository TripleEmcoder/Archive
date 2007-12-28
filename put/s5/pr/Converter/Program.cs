using System;
using System.Collections.Generic;
using System.Text;

using System.IO;

namespace Converter
{
    class Program
    {
        static void Main(string[] args)
        {
            Schedule schedule = new Schedule();

            using (TextReader reader = File.OpenText("../../../PR2 m=3.lp.csv"))
                schedule.LoadSimulation(reader);

            using (TextReader reader = File.OpenText("../../../PR2 m=3.lp.real.txt"))
                schedule.LoadReal(reader);

            using (TextWriter writer = File.CreateText("../../../PR2 m=3.lp.real.csv"))
                schedule.Save(writer);
        }
    }
}
