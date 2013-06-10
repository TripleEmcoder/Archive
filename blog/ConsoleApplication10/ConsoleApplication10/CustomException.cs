using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ClrDumpAspectDemo
{
    class CustomException : Exception
    {
        public CustomException()
        {
            ClrDump.Dump();
        }
    }
}
