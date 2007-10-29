using System;
using System.Collections.Generic;
using System.Text;

using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Threading;

namespace Test
{
    class Program
    {
        static ManualResetEvent close;
        static bool closing;
        static Socket listener;
        static List<StreamLineConnection> connections;

        static void Main(string[] args)
        {
            closing = false;

            using (close = new ManualResetEvent(false))
            {
                Console.CancelKeyPress += OnShutdownRequested;

                using (listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp))
                {
                    listener.Bind(new IPEndPoint(IPAddress.Any, 119));
                    listener.Listen(0);//(int)listener.GetSocketOption(SocketOptionLevel.Tcp, SocketOptionName.MaxConnections));

                    listener.BeginAccept(new AsyncCallback(OnClientConnected), null);
                    close.WaitOne();
                }
            }

            Console.WriteLine("Shutdown complete.");
        }

        static void OnShutdownRequested(object sender, ConsoleCancelEventArgs e)
        {
            Console.WriteLine("Shutdown requested from console.");
            e.Cancel = true;
            closing = true;
            close.Set();
        }

        static void OnClientConnected(IAsyncResult result)
        {
            if (!closing)
            {
                Socket connection = listener.EndAccept(result);
                Console.WriteLine("Client connected from {0}.", connection.RemoteEndPoint);

                Thread thread = new Thread(new ParameterizedThreadStart(ProcessConnection));
                thread.Start(connection);

                listener.BeginAccept(new AsyncCallback(OnClientConnected), null);
            }
        }

        static void ProcessConnection(object parameter)
        {
            Socket connection = (Socket)parameter;

            using (NetworkStream stream = new NetworkStream(connection))
            using (StreamLineConnection _connection = new StreamLineConnection(stream))
            {
                NntpSession session = new NntpSession(_connection);
                _connection.Process();
            }
        }
    }
}
