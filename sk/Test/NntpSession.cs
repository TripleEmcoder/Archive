using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    class NntpSession : IDisposable
    {
        private ILineConnection connection;
        private INntpRepository repository;
        private Dictionary<Type, IDisposable> context;
        private NntpCommand command;

        public NntpSession(ILineConnection connection)
        {
            this.connection = connection;

            connection.LineReceived += OnLineReceived;
            connection.SendLine("200 Service available, posting allowed");

            repository = new NntpRepository();
            context = new Dictionary<Type, IDisposable>();
        }

        public void Dispose()
        {
        }

        internal ILineConnection Connection
        {
            get { return connection; }
        }

        internal INntpRepository Repository
        {
            get { return repository; }
        }

        internal void Save<T>(T value) where T : IDisposable
        {
            context[typeof(T)] = value;
        }

        internal T Get<T>()
        {
            return (T)context[typeof(T)];
        }

        void OnLineReceived(object sender, LineEventArgs e)
        {
            if (e.Line == "")
                return;

            try
            {
                if (command == null)
                {
                    command = NntpCommandFactory.Create(e.Line);
                }
                else
                {
                    command.Parse(e.Line);
                }

                command.Execute(this);

                if (command.IsComplete)
                    command = null;
            }
            catch (NotSupportedException exception)
            {
                connection.SendLine("500 " + exception.Message);
            }
            catch (ArgumentException exception)
            {
                connection.SendLine("501 " + exception.Message);
            }
        }
    }
}
