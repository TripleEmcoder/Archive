using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    public abstract class NntpCommand
    {
        protected string name;

        public NntpCommand(string name)
        {
            this.name = name;
        }

        public virtual bool IsComplete
        {
            get { return true; }
        }

        public virtual void Parse(string line)
        {
        }

        public abstract void Execute(NntpSession session);

        protected static void ParseRange(string expression, out int low, out int high)
        {
            string[] parts = expression.Split(new char[] { '-' }, 2);

            low = high = int.Parse(parts[0]);

            if (parts.Length == 2)
                high = (parts[1] == "") ? 0 : int.Parse(parts[1]);
        }

        protected static bool GetGroupByName(INntpConnection connection, NntpSession session, string name, out INntpGroup group)
        {
            group = connection.GetGroup(name);

            if (group == null)
            {
                session.Connection.SendLine("411 No such newsgroup");
                return false;
            }

            session.Context[typeof(INntpGroup)] = name;
            session.Context[typeof(INntpArticle)] = group.Low;

            return true;
        }

        protected static bool GetGroupByCurrentName(INntpConnection connection, NntpSession session, out INntpGroup group)
        {
            group = null;

            if (!session.Context.ContainsKey(typeof(INntpGroup)))
            {
                session.Connection.SendLine("412 No newsgroup selected");
                return false;
            }

            group = connection.GetGroup((string)session.Context[typeof(INntpGroup)]);

            if (group == null)
            {
                session.Connection.SendLine("412 No newsgroup selected");
                return false;
            }

            return true;
        }

        protected static bool GetArticleByMessageID(INntpConnection connection, NntpSession session, string id, out KeyValuePair<int, INntpArticle> pair)
        {
            pair = new KeyValuePair<int, INntpArticle>(0, connection.GetArticle(id));

            if (pair.Value == null)
            {
                session.Connection.SendLine("430 No article with that message-id");
                return false;
            }

            return true;
        }

        protected static bool GetArticleByNumber(INntpConnection connection, NntpSession session, int number, out KeyValuePair<int, INntpArticle> pair)
        {
            pair = new KeyValuePair<int, INntpArticle>(number, null);

            INntpGroup group;

            if (!GetGroupByCurrentName(connection, session, out group))
                return false;

            pair = new KeyValuePair<int, INntpArticle>(number, group.GetArticle(number));

            if (pair.Value == null)
            {
                session.Connection.SendLine("423 No article with that number");
                return false;
            }

            session.Context[typeof(INntpArticle)] = number;

            return true;
        }

        protected static bool GetArticleByCurrentNumber(INntpConnection connection, NntpSession session, out KeyValuePair<int, INntpArticle> pair)
        {
            pair = new KeyValuePair<int, INntpArticle>(0, null);

            INntpGroup group;

            if (!GetGroupByCurrentName(connection, session, out group))
                return false;

            int number = (int)session.Context[typeof(INntpArticle)];
            pair = new KeyValuePair<int, INntpArticle>(number, group.GetArticle(number));

            if (pair.Value == null)
            {
                session.Connection.SendLine("420 Current article number is invalid");
                return false;
            }

            return true;
        }
    }
}
