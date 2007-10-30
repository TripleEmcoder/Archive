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
                    
                    Console.WriteLine("Listening for connections on {0}.", listener.LocalEndPoint);
                    
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

                Thread thread = new Thread(new ParameterizedThreadStart(ProcessConnection));
                thread.Start(connection);

                listener.BeginAccept(new AsyncCallback(OnClientConnected), null);
            }
        }

        static void ProcessConnection(object parameter)
        {
            using (Socket socket = (Socket)parameter)
            {
                Console.WriteLine("Serving connection from {0}.", socket.RemoteEndPoint);

                using (NetworkStream stream = new NetworkStream(socket))
                using (StreamLineConnection connection = new StreamLineConnection(stream))
                {
                    List<INntpArticle> articles = new List<INntpArticle>();
                    articles.Add(new MemoryArticle("test1"));

                    List<INntpGroup> groups = new List<INntpGroup>();
                    groups.Add(new MemoryGroup("test", articles.AsReadOnly()));

                    INntpRepository repository = new MemoryRepository(articles.AsReadOnly(), groups.AsReadOnly());
                    using (NntpSession session = new NntpSession(connection, repository))
                        connection.Process();
                }

                Console.WriteLine("Connection closed.");
            }
        }
    }
}
