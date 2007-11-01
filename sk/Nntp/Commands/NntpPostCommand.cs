using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("POST")]
    public class NntpPostCommand : NntpCommand
    {
        private enum RequestState
        {
            StartingRequest,
            ReceivingHeaders,
            ReceivingBody,
            RequestFinished
        };

        private RequestState state;
        private Dictionary<string, string> headers;
        private StringBuilder body;
        private string header;

        public NntpPostCommand(string name, string parameters)
            : base(name)
        {
            state = RequestState.StartingRequest;
            headers = new Dictionary<string, string>();
            body = new StringBuilder();
        }

        public override bool IsComplete
        {
            get { return state == RequestState.RequestFinished; }
        }

        public override void Parse(string line)
        {
            switch (state)
            {
                case RequestState.ReceivingHeaders:
                    if (line == "")
                    {
                        state = RequestState.ReceivingBody;
                        return;
                    }

                    if (line == ".")
                    {
                        state = RequestState.RequestFinished;
                        return;
                    }

                    if (line.StartsWith(" "))
                    {
                        headers[header] += line;
                    }
                    else
                    {
                        string[] parts = line.Split(new char[] { ':' }, 2);
                        header = parts[0];
                        headers[header] = parts[1].Substring(1);
                    }

                    break;

                case RequestState.ReceivingBody:
                    if (line == ".")
                    {
                        state = RequestState.RequestFinished;
                        return;
                    }

                    body.AppendLine(line);
                    break;

                case RequestState.RequestFinished:
                    throw new InvalidOperationException();
            }
        }

        public override void Execute(NntpSession session)
        {
            switch (state)
            {
                case RequestState.StartingRequest:
                    session.Connection.SendLine("340 Send article to be posted");
                    state = RequestState.ReceivingHeaders;
                    break;

                case RequestState.RequestFinished:
                    session.Connection.SendLine("240 Article received OK");

                    using (INntpTransaction transacion = session.Repository.CreateTransaction())
                        ;//store

                    break;
            }
        }
    }
}
