using System;
using System.Collections.Generic;
using System.Text;

using System.Net.Sockets;
using System.IO;

namespace Test
{
    class StreamLineConnection : ILineConnection
    {
        private StreamReader reader;
        private StreamWriter writer;

        public StreamLineConnection(Stream stream)
        {
            reader = new StreamReader(stream);
            writer = new StreamWriter(stream);
        }

        public void Dispose()
        {
            reader.Dispose();
            writer.Dispose();
        }

        public void Process()
        {
            while (true)
            {
                string line = reader.ReadLine();
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

        public event EventHandler<LineEventArgs> LineReceived;
    }
}
