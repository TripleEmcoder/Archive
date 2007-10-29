using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    interface ILineConnection : IDisposable
    {
        void SendLine(string data);
        event EventHandler<LineEventArgs> LineReceived;
    }
}
