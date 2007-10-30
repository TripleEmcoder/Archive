using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    public class TestLineConnection : ILineConnection
    {
        public void SendLine(string format, params object[] values)
        {
            if (LineSent != null)
                LineSent(this, new LineEventArgs(string.Format(format, values)));
        }

        public void ReceiveLine(string format, params object[] values)
        {
            if (LineReceived != null)
                LineReceived(this, new LineEventArgs(string.Format(format, values)));
        }

        public void Close()
        {
        }

        public event EventHandler<LineEventArgs> LineSent;
        public event EventHandler<LineEventArgs> LineReceived;

        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }
    }
}
