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

        public NntpOverCommand(string name, string parameters)
            : base(name)
        {
            if (parameters == "")
            {
                type = RequestType.ByCurrentArticleNumber;
            }
            else if (parameters.StartsWith("<") && parameters.EndsWith(">"))
            {
                type = RequestType.ByMessageId;
                id = parameters.Substring(1, parameters.Length - 2);
            }
            else
            {
                type = RequestType.ByArticleNumberRange;
                string[] parts = parameters.Split(new char[] { '-' }, 2);

                low = high = int.Parse(parts[0]);

                if (parts.Length == 2)
                    high = (parts[0] == "") ? 0 : int.Parse(parts[1]);
            }
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateTransaction())
            {
                List<KeyValuePair<int, INntpArticle>> pairs = new List<KeyValuePair<int, INntpArticle>>();
                INntpGroup group = null;

                switch (type)
                {
                    case RequestType.ByMessageId:
                        pairs.Add(new KeyValuePair<int, INntpArticle>(0, session.Repository.GetArticle(id)));

                        if (pairs[0].Value == null)
                        {
                            session.Connection.SendLine("430 No article with that message-id");
                            return;
                        }

                        break;

                    case RequestType.ByArticleNumberRange:
                        if (!session.Context.ContainsKey(typeof(INntpGroup)))
                        {
                            session.Connection.SendLine("412 No newsgroup selected");
                            return;
                        }

                        group = session.Repository.GetGroup((string)session.Context[typeof(INntpGroup)]);
                        pairs.AddRange(group.GetArticles(low, high));

                        if (pairs.Count == 0)
                        {
                            session.Connection.SendLine("423 No articles in that range");
                            return;
                        }

                        break;

                    case RequestType.ByCurrentArticleNumber:
                        if (!session.Context.ContainsKey(typeof(INntpGroup)))
                        {
                            session.Connection.SendLine("412 No newsgroup selected");
                            return;
                        }

                        group = session.Repository.GetGroup((string)session.Context[typeof(INntpGroup)]);
                        int number = (int)session.Context[typeof(INntpArticle)];
                        pairs.Add(new KeyValuePair<int, INntpArticle>(number, group.GetArticle(number)));

                        if (pairs[0].Value == null)
                        {
                            session.Connection.SendLine("420 Current article number is invalid");
                            return;
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