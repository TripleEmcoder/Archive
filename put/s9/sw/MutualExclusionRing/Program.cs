using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Net;
using System.Net.Sockets;

namespace MutualExclusionRing
{
    struct Token
    {
        public int Id;
    }

    class Program
    {
        static void Main(string[] args)
        {
            var program = new Program(int.Parse(args[0]), int.Parse(args[1]), int.Parse(args[2]), int.Parse(args[3]));
            program.Run(new IPEndPoint(IPAddress.Parse(args[4]), int.Parse(args[5])), new IPEndPoint(IPAddress.Parse(args[6]), int.Parse(args[7])));
        }

        int processId;
        int lastId;

        TcpClient previous;
        TcpClient next;

        int lossDivider;
        int workTime;
        int sleepTime;

        public Program(int processId, int lossDivider, int workTime, int sleepTime)
        {
            this.processId = processId;
            this.lossDivider = lossDivider;
            this.workTime = workTime;
            this.sleepTime = sleepTime;
        }

        #region 

        public void Run(IPEndPoint thisEndpoint, IPEndPoint nextEndpoint)
        {
            Console.WriteLine("Listening on: {0}.", thisEndpoint);
            var listener = new TcpListener(thisEndpoint);
            listener.Start();
            listener.BeginAcceptTcpClient(result => 
                {
                    previous = listener.EndAcceptTcpClient(result);
                    Receive();
                }, null);

            next = new TcpClient();

            while (true)
            {
                try
                {
                    Console.WriteLine("Connecting to: {0}.", nextEndpoint);
                    next.Connect(nextEndpoint);
                    OnRun();
                }
                catch (Exception exception)
                {
                    Console.WriteLine("Connection failed: {0}.", exception.Message);
                    Sleep("Sleeping before next attempt:", 5);
                }
            }
        }

        void Receive()
        {
            var data = new byte[4];
            previous.GetStream().BeginRead(data, 0, data.Length, result2 =>
                {
                    OnReceive(new Token { Id = BitConverter.ToInt32(data, 0) });
                    Receive();
                }, null);
        }

        void Send(Token token)
        {
            if (lossDivider != 0 && lastId % lossDivider == 0)
                return;

            var data = BitConverter.GetBytes(token.Id);
            next.GetStream().BeginWrite(data, 0, data.Length, null, null);
        }

        private void Sleep(string text, int time)
        {
            Console.Write(text);
            for (int i = time - 1; i >= 0; i--)
            {
                Thread.Sleep(1000);
                //Console.Write(" " + i);
            }
            //Console.WriteLine(".");
        }

        #endregion

        void OnRun()
        {
            OnStart();
            while (true)
                OnIdle();
        }

        void OnSend(Token token)
        {
            Console.WriteLine("Sending token: {0}.", token.Id);
            Send(token);
        }

        void OnReceive(Token token)
        {
            Console.WriteLine("Received token: {0}.", token.Id);
            if (lastId != token.Id)
            {
                lastId = token.Id;
                OnWork();
            }
        }

        void OnStart()
        {
            if (processId == 0)
            {
                OnWork();
                lastId = 1;
            }
        }

        void OnIdle()
        {
            if (lastId != 0)
                OnSend(new Token { Id = lastId + 1 });

            Sleep("Sleeping before retransmission:", sleepTime);
        }

        void OnWork()
        {
            var old = Console.BackgroundColor;
            Console.BackgroundColor = ConsoleColor.Red;
            Sleep("In critical section:", workTime);
            Console.BackgroundColor = old;
        }
    }
}
