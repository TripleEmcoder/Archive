using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    class LineEventArgs : EventArgs
    {
        private string line;

        public LineEventArgs(string line)
        {
            this.line = line;
        }

        public string Line
        {
            get { return line; }
        }
    }
}
