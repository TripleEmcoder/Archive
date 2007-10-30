using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("ARTICLE")]
    public class NntpArticleCommand : NntpCommand
    {
        private enum RequestType { ByMessageId, ByNumber, ByCurrentArticleNumber };

        private RequestType type;
        private int number;
        private string id;

        public NntpArticleCommand(string name, string parameters)
            :base(name)
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
                     group = session.Get<INntpGroup>();

                     if (group == null)
                     {
                         session.Connection.SendLine("412 No newsgroup selected");
                         return;
                     }

                     article = group.GetArticle(number);

                     if (article == null)
                     {
                         session.Connection.SendLine("423 No article with that number");
                         return;
                     }

                     session.Save(article);
                     break;

                 case RequestType.ByCurrentArticleNumber:
                     group = session.Get<INntpGroup>();

                     if (group == null)
                     {
                         session.Connection.SendLine("412 No newsgroup selected");
                         return;
                     }

                     article = session.Get<INntpArticle>(); //report error when not selected
                     break;
             }             

            session.Connection.SendLine("220 0 {0}", article.ID);

            session.Connection.SendLine("From: {0}", article.From);
            session.Connection.SendLine("Subject: {0}", article.Subject);
            session.Connection.SendLine("Date: {0}", article.Date);
            session.Connection.SendLine("Message-ID: {0}", article.ID);
            session.Connection.SendLine("");

            session.Connection.SendLine(article.Body);
            session.Connection.SendLine(".");
        }
    }
}
