using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp
{
    public interface ILineConnection : IDisposable
    {
        void SendLine(string format, params object[] values);
        void Close();
        event EventHandler<LineEventArgs> LineReceived;
    }
}
