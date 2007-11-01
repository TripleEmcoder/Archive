using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("ARTICLE")]
    public class NntpArticleCommand : NntpCommand
    {
        private enum RequestType { ByMessageId, ByNumber, ByCurrentArticleNumber };

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
                type = RequestType.ByNumber;
                number = int.Parse(parameters);
            }
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateTransaction())
            {
                INntpArticle article = null;
                INntpGroup group = null;

                switch (type)
                {
                    case RequestType.ByMessageId:
                        article = session.Repository.GetArticle(id);

                        if (article == null)
                        {
                            session.Connection.SendLine("430 No article with that message-id");
                            return;
                        }

                        break;

                    case RequestType.ByNumber:
                        if (!session.Context.ContainsKey(typeof(INntpGroup)))
                        {
                            session.Connection.SendLine("412 No newsgroup selected");
                            return;
                        }

                        group = session.Repository.GetGroup((string)session.Context[typeof(INntpGroup)]);
                        article = group.GetArticle(number);

                        if (article == null)
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

                         //report error when not selected
                        article = group.GetArticle((int)session.Context[typeof(INntpArticle)]);
                        break;
                }

                session.Connection.SendLine("220 0 {0}", article.MessageID);

                session.Connection.SendLine("{0}: <{1}>", NntpHeaderName.MessageID, article.MessageID);
                session.Connection.SendLine("{0}: {1}", NntpHeaderName.Subject, article.Subject);
                session.Connection.SendLine("{0}: {1}", NntpHeaderName.From, article.From);
                session.Connection.SendLine("{0}: {1}", NntpHeaderName.Date, article.Date);
                session.Connection.SendLine("{0}: {1}", NntpHeaderName.References, article.References);
                session.Connection.SendLine("{0}: {1}", NntpHeaderName.Newsgroups, article.Newsgroups);
                session.Connection.SendLine("");

                session.Connection.SendLine(article.Body);
                session.Connection.SendLine(".");
            }
        }
    }
}
