using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("OVER")]
    [NntpCommandName("XOVER")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("OVER MSGID")]
    public class NntpOverCommand : NntpCommand
    {
        private enum RequestType { ByMessageId, ByArticleNumberRange, ByCurrentArticleNumber };

        private RequestType type;
        private string id;
        private int low;
        private int high;

        public NntpOverCommand(string name)
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
                type = RequestType.ByMessageId;
                id = line;//.Substring(1, parameters.Length - 2);
            }
            else
            {
                type = RequestType.ByArticleNumberRange;
                ParseRange(line, out low, out high);
            }
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateConnection())
            {
                List<KeyValuePair<int, INntpArticle>> pairs = new List<KeyValuePair<int, INntpArticle>>();

                switch (type)
                {
                    case RequestType.ByMessageId:
                        {
                            KeyValuePair<int, INntpArticle> pair;

                            if (!GetArticleByMessageID(connection, session, id, out pair))
                                return;

                            pairs.Add(pair);
                        }

                        break;

                    case RequestType.ByArticleNumberRange:
                        {
                            INntpGroup group;

                            if (!GetGroupByCurrentName(connection, session, out group))
                                return;

                            if (high == 0)
                                high = group.High;

                            pairs.AddRange(group.GetArticles(low, high));

                            if (pairs.Count == 0)
                            {
                                session.Connection.SendLine("423 No articles in that range");
                                return;
                            }
                        }

                        break;

                    case RequestType.ByCurrentArticleNumber:
                        {
                            KeyValuePair<int, INntpArticle> pair;

                            if (!GetArticleByCurrentNumber(connection, session, out pair))
                                return;

                            pairs.Add(pair);
                        }

                        break;
                }

                session.Connection.SendLine("224 Overview information follows");

                foreach (KeyValuePair<int, INntpArticle> pair in pairs)
                    session.Connection.SendLine("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}\t{7}",
                            pair.Key, pair.Value.Subject, pair.Value.From, pair.Value.Date,
                            pair.Value.MessageID, pair.Value.References, pair.Value.Bytes, pair.Value.Lines);

                session.Connection.SendLine(".");
            }
        }
    }
}