using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    public class NntpSession : IDisposable
    {
        private ILineConnection connection;
        private INntpRepository repository;
        private Dictionary<Type, object> context;
        private NntpCommand command;

        public NntpSession(ILineConnection connection, INntpRepository repository)
        {
            this.connection = connection;
            this.repository = repository;

            connection.LineReceived += OnLineReceived;
            connection.SendLine("200 Service available, posting allowed");

            context = new Dictionary<Type, object>();
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

        internal Dictionary<Type, object> Context
        {
            get { return context; }
        }

        void OnLineReceived(object sender, LineEventArgs e)
        {
            try
            {
                if (command == null)
                {
                    if (e.Line == "")
                        return;

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
            catch (Exception exception)
            {
                connection.SendLine("403 " + exception.Message);
            }
        }
    }
}