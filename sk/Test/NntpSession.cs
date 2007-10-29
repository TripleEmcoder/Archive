using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    class NntpSession : IDisposable
    {
        static char[] separators = new char[] { ' ', '\t' };

        private ILineConnection connection;
        private ILineCommand command;

        public NntpSession(ILineConnection connection)
        {
            this.connection = connection;

            connection.LineReceived += OnLineReceived;
            connection.SendLine("200 Service available, posting allowed");
        }

        public void Dispose()
        {
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

                if (command.IsComplete)
                {
                    command.Execute(connection);
                    command = null;
                }
            }
            catch (NotSupportedException exception)
            {
                connection.SendLine("500 Unknown command");
            }
            catch (ArgumentException exception)
            {
                connection.SendLine("501 Syntax error");
            }
        }
    }
}
