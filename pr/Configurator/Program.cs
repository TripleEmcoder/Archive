using System;
using System.Collections.Generic;
using System.Text;

using System.IO;

namespace Configurator
{
    class Program
    {
        static void Main(string[] args)
        {
            Header header = new Header();
            
            //header.Load(Console.In);
            
            using (TextReader reader = File.OpenText("../../../PR2 m=3.lp.csv"))
                header.Load(reader);
            
            //header.Save(Console.Out, "sizes");
            
            using (TextWriter writer = File.CreateText("../../../cube/sizes.h"))
                header.Save(writer, "sizes");
        }
    }
}
