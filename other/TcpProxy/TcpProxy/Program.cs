using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Text.RegularExpressions;
using System.Runtime.CompilerServices;

namespace TcpProxy
{
    class Program
    {
        private const int RelayBufferSize = 32 * 1024;
        private const int StrippedPreviewLength = 110;

        public static void Main(string[] args)
        {
            TcpListener listener = new TcpListener(new IPEndPoint(
                IPAddress.Parse(args[0]), int.Parse(args[1])));

            listener.Start();

            while (true)
            {
                TcpClient client = listener.AcceptTcpClient();
                client.NoDelay = true;

                TcpClient server = new TcpClient(args[2], int.Parse(args[3]));
                server.NoDelay = true;

                SetupRelay(ConsoleColor.Green, client, server);
                SetupRelay(ConsoleColor.Red, server, client);
            }
        }

        private static void SetupRelay(ConsoleColor color, TcpClient input, TcpClient output)
        {
            Thread thread = new Thread(new ThreadStart(
                delegate() { RelayData(color, input.GetStream(), output.GetStream()); }));

            thread.Name = string.Format("{0} -> {1}",
                input.Client.RemoteEndPoint, output.Client.RemoteEndPoint);

            thread.Start();
        }

        private static void RelayData(ConsoleColor color, NetworkStream input, NetworkStream output)
        {
            LogMessage(color, "OPENING");

            while (true)
            {
                byte[] buffer = new byte[RelayBufferSize];
                int count = input.Read(buffer, 0, buffer.Length);

                if (count == 0)
                    break;

                LogMessage(color, PreviewStrippedBuffer(buffer, count));

                output.Write(buffer, 0, count);
            }

            LogMessage(color, "CLOSING");
        }

        [MethodImpl(MethodImplOptions.Synchronized)]
        private static void LogMessage(ConsoleColor color, string message)
        {
            Console.ForegroundColor = color;
            Console.Write("{0} | {1} | ", DateTime.Now, Thread.CurrentThread.Name);

            Console.ForegroundColor = ConsoleColor.Gray;
            Console.WriteLine(message);
        }

        private static string PreviewFullBuffer(byte[] buffer, int count)
        {
            return Encoding.ASCII.GetString(buffer, 0, count);
        }

        private static string PreviewStrippedBuffer(byte[] buffer, int count)
        {
            byte[] _buffer = new byte[StrippedPreviewLength];
            count = Math.Min(_buffer.Length, count);
            Array.Copy(buffer, 0, _buffer, 0, count);
            
            string text = Encoding.ASCII.GetString(_buffer, 0, count);
            
            Regex filter1 = new Regex(@"\s");
            text = filter1.Replace(text, " ");

            return text;
        }
    }
}
