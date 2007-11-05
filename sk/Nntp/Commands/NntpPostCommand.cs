using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("POST")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("POST")]
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

        public NntpPostCommand(string name)
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

                    if (line.StartsWith(" ") || line.StartsWith("\t"))
                    {
                        headers[header] += " " + line.Substring(1);
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
                    state = RequestState.ReceivingHeaders;
                    session.Connection.SendLine("340 Send article to be posted");
                    break;

                case RequestState.RequestFinished:
                    using (INntpConnection connection = session.Repository.CreateConnection())
                    {
                        INntpArticle article = connection.CreateArticle();

                        SetOverviewHeaders(article);
                        SetOtherHeaders(article);
                        article.Body = body.ToString();

                        connection.PostArticle(article);
                    }

                    session.Connection.SendLine("240 Article received OK");
                    break;
            }
        }

        private void SetOverviewHeaders(INntpArticle article)
        {
            article.Subject = headers[NntpHeaderName.Subject];
            article.From = headers[NntpHeaderName.From];
            article.Date = headers[NntpHeaderName.Date];
            article.Newsgroups = headers[NntpHeaderName.Newsgroups];

            if (headers.ContainsKey(NntpHeaderName.References))
                article.References = headers[NntpHeaderName.References];
        }

        private void SetOtherHeaders(INntpArticle article)
        {
            Dictionary<string, string> headers
                = new Dictionary<string, string>(this.headers);

            headers.Remove(NntpHeaderName.Subject);
            headers.Remove(NntpHeaderName.From);
            headers.Remove(NntpHeaderName.Date);
            headers.Remove(NntpHeaderName.Newsgroups);
            headers.Remove(NntpHeaderName.References);

            foreach (KeyValuePair<string, string> header in headers)
                article.Headers[header.Key] = header.Value;
        }
    }
}
