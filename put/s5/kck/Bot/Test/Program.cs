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
            using (GGSession s = new GGSession(9444333, "alamakota"))
            {
                s.send(1817471, new Random().Next().ToString() + " ¹æê³ñóœ¿Ÿ");
            }            
        }
    }
}
