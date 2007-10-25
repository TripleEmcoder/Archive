using System;
using System.Collections.Generic;
using System.Text;

using InstantMessaging.Protocols.GG;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            using (GGSession s = new GGSession())
            {
                s.send("test");
            }            
        }
    }
}
