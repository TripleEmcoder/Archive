using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    interface ILineConnection : IDisposable
    {
        void SendLine(string format, params object[] values);
        void Close();
        event EventHandler<LineEventArgs> LineReceived;
    }
}
