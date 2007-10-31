using System;
using System.Collections.Generic;
using System.Text;

using System.Net.Sockets;
using System.IO;

using Nntp;

namespace Test
{
    class StreamLineConnection : ILineConnection
    {
        private StreamReader reader;
        private StreamWriter writer;
        bool closing;

        public StreamLineConnection(Stream stream)
        {
            reader = new StreamReader(stream);
            writer = new StreamWriter(stream);
            closing = false;
        }

        public void Dispose()
        {
            reader.Dispose();
            writer.Dispose();
        }

        public void Process()
        {
            while (!closing)
            {
                string line = reader.ReadLine();

                if (line == null)
                    return;

                Console.WriteLine("<< " + line);
                LineReceived(this, new LineEventArgs(line));
            }
        }

        public void SendLine(string line)
        {
            Console.WriteLine(">> " + line);
            writer.WriteLine(line);
            writer.Flush();
        }

        public void SendLine(string format, params object[] values)
        {
            SendLine(string.Format(format, values));
        }

        public void Close()
        {
            closing = true;
        }

        public event EventHandler<LineEventArgs> LineReceived;
    }
}
