using System;
using System.Collections.Generic;
using System.Text;

using System.Diagnostics;

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
                string line = e.Line;

                if (command == null)
                {
                    if (line == "")
                        return;

                    command = NntpCommandFactory.Create(ref line);
                }

                try
                {
                    command.Parse(line);
                }
                catch (Exception exception)
                {
                    throw new ArgumentException("Parse error", exception);
                }

                try
                {
                    command.Execute(this);

                    if (command.IsComplete)
                        command = null;
                }
                catch (Exception exception)
                {
                    throw new Exception("Internal error", exception);
                }
            }
            catch (NotSupportedException exception)
            {
                Trace.WriteLine(exception.InnerException.Message);
                connection.SendLine("500 " + exception.Message);
                command = null;
            }
            catch (ArgumentException exception)
            {
                Trace.WriteLine(exception.InnerException.Message);
                connection.SendLine("501 " + exception.Message);
                command = null;
            }
            catch (Exception exception)
            {
                Trace.WriteLine(exception.InnerException.Message);
                connection.SendLine("403 " + exception.Message);
                command = null;
            }
        }
    }
}