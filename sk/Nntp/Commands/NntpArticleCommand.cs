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
        private enum RequestType { ByMessageId, ByArticleNumber, ByCurrentArticleNumber };

        private RequestType type;
        private int number;
        private string id;

        public NntpArticleCommand(string name, string parameters)
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
                type = RequestType.ByArticleNumber;
                number = int.Parse(parameters);
            }
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateTransaction())
            {
                KeyValuePair<int, INntpArticle> pair = new KeyValuePair<int, INntpArticle>(0, null);
                INntpGroup group = null;

                switch (type)
                {
                    case RequestType.ByMessageId:
                        pair = new KeyValuePair<int, INntpArticle>(0, session.Repository.GetArticle(id));

                        if (pair.Value == null)
                        {
                            session.Connection.SendLine("430 No article with that message-id");
                            return;
                        }

                        break;

                    case RequestType.ByArticleNumber:
                        if (!session.Context.ContainsKey(typeof(INntpGroup)))
                        {
                            session.Connection.SendLine("412 No newsgroup selected");
                            return;
                        }

                        group = session.Repository.GetGroup((string)session.Context[typeof(INntpGroup)]);
                        pair = new KeyValuePair<int, INntpArticle>(number, group.GetArticle(number));

                        if (pair.Value == null)
                        {
                            session.Connection.SendLine("423 No article with that number");
                            return;
                        }

                        session.Context[typeof(INntpArticle)] = number;
                        break;

                    case RequestType.ByCurrentArticleNumber:
                        if (!session.Context.ContainsKey(typeof(INntpGroup)))
                        {
                            session.Connection.SendLine("412 No newsgroup selected");
                            return;
                        }

                        group = session.Repository.GetGroup((string)session.Context[typeof(INntpGroup)]);
                        int _number = (int)session.Context[typeof(INntpArticle)];
                        pair = new KeyValuePair<int, INntpArticle>(number, group.GetArticle(_number));

                        if (pair.Value == null)
                        {
                            session.Connection.SendLine("420 Current article number is invalid");
                            return;
                        }

                        break;
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
                    session.Connection.SendLine("{0}: <{1}>", NntpHeaderName.MessageID, pair.Value.MessageID);
                    session.Connection.SendLine("{0}: {1}", NntpHeaderName.Subject, pair.Value.Subject);
                    session.Connection.SendLine("{0}: {1}", NntpHeaderName.From, pair.Value.From);
                    session.Connection.SendLine("{0}: {1}", NntpHeaderName.Date, pair.Value.Date);
                    session.Connection.SendLine("{0}: {1}", NntpHeaderName.References, pair.Value.References);
                    session.Connection.SendLine("{0}: {1}", NntpHeaderName.Newsgroups, pair.Value.Newsgroups);

                    foreach (KeyValuePair<string, string> header in pair.Value.Headers)
                        session.Connection.SendLine("{0}: {1}", header.Key, header.Value);
                }

                if (name == "ARTICLE")
                    session.Connection.SendLine("");

                if (name == "ARTICLE" || name == "BODY")
                    session.Connection.SendLine(pair.Value.Body);

                if (name != "STAT")
                    session.Connection.SendLine(".");
            }
        }
    }
}
