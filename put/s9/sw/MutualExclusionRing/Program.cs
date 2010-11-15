using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Net;
using System.Net.Sockets;

namespace MutualExclusionRing
{
    class Token
    {
        public int Id;
    }

    class Program
    {
        // 0 0 2 8 5 127.0.0.1 1001 127.0.0.1 1002
        // 1 0 2 8 5 127.0.0.1 1002 127.0.0.1 1003
        // 1 0 2 8 5 127.0.0.1 1003 127.0.0.1 1001
        static void Main(string[] args)
        {
            var program = new Program(int.Parse(args[0]), int.Parse(args[1]), int.Parse(args[2]), int.Parse(args[3]), int.Parse(args[4]));
            program.Run(new IPEndPoint(IPAddress.Parse(args[5]), int.Parse(args[6])), new IPEndPoint(IPAddress.Parse(args[7]), int.Parse(args[8])));
        }

        int processId;
        int lastId;

        TcpClient previous;
        TcpClient next;

        int linkDelay;
        int lossDivider;
        int tokenCount;
        int workTime;
        int sleepTime;

        public Program(int processId, int linkDelay, int lossDivider, int workTime, int sleepTime)
        {
            this.processId = processId;
            this.linkDelay = linkDelay;
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
            var result = listener.BeginAcceptTcpClient(null, null);

            next = new TcpClient();

            while (true)
            {
                try
                {
                    Console.WriteLine("Connecting to: {0}.", nextEndpoint);
                    next.Connect(nextEndpoint);
                    previous = listener.EndAcceptTcpClient(result);
                    OnRun();
                }
                catch (Exception exception)
                {
                    Console.WriteLine("Connection failed: {0}.", exception.Message);
                    Sleep("Sleeping before next attempt", 5);
                }
            }
        }

        Token TryReceive()
        {
            if (!previous.GetStream().DataAvailable)
                return null;

            var data = new byte[4];
            previous.GetStream().Read(data, 0, data.Length);
            return new Token { Id = BitConverter.ToInt32(data, 0) };
        }

        void TrySend(Token token)
        {
            if (lossDivider != 0 && tokenCount++ % lossDivider == 0)
            {
                Console.WriteLine("Simulating token loss.");
                return;
            }

            Sleep("Simulating link delay", linkDelay);
            var data = BitConverter.GetBytes(token.Id);
            next.GetStream().Write(data, 0, data.Length);
        }

        void Sleep(string text, int time)
        {
            if (time > 0)
                Console.WriteLine(text + ".");

            //Console.Write(text + ":);
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
            {
                var token = TryReceive();
                if (token != null)
                    OnReceive(token);
                OnIdle();
            }
        }

        void OnSend(Token token)
        {
            Console.WriteLine("Sending token: {0}.", token.Id);
            TrySend(token);
        }

        void OnReceive(Token token)
        {
            Console.WriteLine("Received token: {0}.", token.Id);
            if (lastId != token.Id)
            {
                lastId = token.Id;
                OnWork();
            }
            else
            {
                Console.WriteLine("Ïgnoring token.");
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

            Sleep("Sleeping before retransmission", sleepTime);
        }

        void OnWork()
        {
            var old = Console.BackgroundColor;
            Console.BackgroundColor = ConsoleColor.Red;
            Sleep("In critical section", workTime);
            Console.BackgroundColor = old;
        }
    }
}
