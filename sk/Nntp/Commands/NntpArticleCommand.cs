using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("ARTICLE")]
    [NntpCommandName("HEAD")]
    [NntpCommandName("BODY")]
    [NntpCommandName("STAT")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("READER")]
    public class NntpArticleCommand : NntpCommand
    {
        private enum RequestType { ByMessageID, ByArticleNumber, ByCurrentArticleNumber };

        private RequestType type;
        private int number;
        private string id;

        public NntpArticleCommand(string name)
            : base(name)
        {
        }

        public override void Parse(string line)
        {
            if (line == "")
            {
                type = RequestType.ByCurrentArticleNumber;
            }
            else if (line.StartsWith("<") && line.EndsWith(">"))
            {
                type = RequestType.ByMessageID;
                id = line;//.Substring(1, line.Length - 2);
            }
            else
            {
                type = RequestType.ByArticleNumber;
                number = int.Parse(line);
            }
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateConnection())
            {
                KeyValuePair<int, INntpArticle> pair;

                switch (type)
                {
                    case RequestType.ByMessageID:
                        if (!GetArticleByMessageID(connection, session, id, out pair))
                            return;

                        break;

                    case RequestType.ByArticleNumber:
                        if (!GetArticleByNumber(connection, session, number, out pair))
                            return;

                        break;

                    case RequestType.ByCurrentArticleNumber:
                        if (!GetArticleByCurrentNumber(connection, session, out pair))
                            return;

                        break;

                    default:
                        throw new InvalidOperationException("Unknown request type");
                }

                if (name == "ARTICLE")
                    session.Connection.SendLine("220 {0} {1}", pair.Key, pair.Value.MessageID);

                if (name == "HEAD")
                    session.Connection.SendLine("221 {0} {1}", pair.Key, pair.Value.MessageID);

                if (name == "BODY")
                    session.Connection.SendLine("222 {0} {1}", pair.Key, pair.Value.MessageID);

                if (name == "STAT")
                    session.Connection.SendLine("223 {0} {1}", pair.Key, pair.Value.MessageID);

                if (name == "ARTICLE" || name == "HEAD")
                {
                    SendHeader(session, NntpHeaderName.MessageID, pair.Value.MessageID);
                    SendHeader(session, NntpHeaderName.Subject, pair.Value.Subject);
                    SendHeader(session, NntpHeaderName.From, pair.Value.From);
                    SendHeader(session, NntpHeaderName.Date, pair.Value.Date);
                    SendHeader(session, NntpHeaderName.Newsgroups, pair.Value.Newsgroups);

                    if (pair.Value.References != "")
                        SendHeader(session, NntpHeaderName.References, pair.Value.References);

                    foreach (KeyValuePair<string, string> header in pair.Value.Headers)
                        SendHeader(session, header.Key, header.Value);
                }

                if (name == "ARTICLE")
                    session.Connection.SendLine("");

                if (name == "ARTICLE" || name == "BODY")
                {
                    string[] lines = pair.Value.Body.Split('\n');

                    for (int i = 0; i < lines.Length-1; i++)
                    {
                        string line = lines[i];

                        if (line.StartsWith("."))
                            line =  '.' + line;

                        session.Connection.SendLine(line);
                    }
                }

                if (name != "STAT")
                    session.Connection.SendLine(".");
            }
        }

        private static void SendHeader(NntpSession session, string name, string value)
        {
            session.Connection.SendLine("{0}: {1}", name, value);
        }
    }
}
