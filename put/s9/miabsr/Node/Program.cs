using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.Net;
using System.IO;

namespace Node
{
    public class Program
    {
        public static void Main(string[] args)
        {
            switch (args[0])
            {
                case "send":
                    {
                        string key;
                        string[][] data;

                        using (var stream = Console.OpenStandardInput())
                            RetrievePacket(stream, out key, out data);

                        using (var client = new TcpClient())
                        {
                            client.Connect(GetEndpoint(args[1], args[2]));
                            using (var stream = client.GetStream())
                                SendPacket(stream, key, data);
                        }
                    }
                    break;

                case "receive":
                    {
                        string key;
                        string[][] data;

                        var listener = new TcpListener(GetEndpoint(args[1], args[2]));

                        listener.Start();

                        while (true)
                        {
                            using (var client = listener.AcceptTcpClient())
                            using (var stream = client.GetStream())
                                RetrievePacket(stream, out key, out data);

                            using (var stream = Console.OpenStandardOutput())
                                SendPacket(stream, key, data);
                        }
                    }

                case "process":
                    {
                        while (true)
                        {
                        }
                    }
            }

        }

        private static IPEndPoint GetEndpoint(string ip, string port)
        {
            return new IPEndPoint(IPAddress.Parse(ip), int.Parse(port));
        }

        private static void RetrievePacket(Stream stream, out string key, out string[][] data)
        {
            using (var reader = new StreamReader(stream))
            {
                key = reader.ReadLine();

                var rows = reader.ReadToEnd().Split(new[] { '\n' }, StringSplitOptions.RemoveEmptyEntries);
                data = new string[rows.Length][];

                for (int i = 0; i < rows.Length; i++)
                    data[i] = rows[i].Split(';');
            }
        }

        private static void SendPacket(Stream stream, string key, string[][] data)
        {
            using (var writer = new StreamWriter(stream))
            {
                writer.WriteLine(key);

                for (int i = 0; i < data.Length; i++)
                    writer.WriteLine(string.Join(";", data[i]));
            }
        }
    }
}
