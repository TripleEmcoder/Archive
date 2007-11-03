using System;
using System.Collections.Generic;
using System.Text;

using Iesi.Collections.Generic;

using NHibernate;
using NHibernate.Expression;
using NHibernate.Classic;

namespace Nntp.Storage.Database
{
    public class DatabaseArticle : DatabaseEntity, INntpArticle
    {
        private int id;
        private DatabaseArticle parent;
        private string messageID;
        private string subject;
        private string from;
        private DateTime date;
        private int bytes;
        private int lines;

        private ICollection<DatabaseGroup> groups;
        private IDictionary<string, string> headers;
        private ICollection<string> bodies;

        public DatabaseArticle()
        {
            groups = new HashedSet<DatabaseGroup>();
            headers = new Dictionary<string, string>();
            bodies = new HashedSet<string>();
        }

        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public override LifecycleVeto OnSave(ISession session)
        {
            messageID = "<" + Guid.NewGuid().ToString() + ">";
            date = DateTime.Now;
            return base.OnSave(session);
        }

        public virtual int ID
        {
            get { return id; }
        }

        string INntpArticle.MessageID
        {
            get { return messageID; }
        }

        string INntpArticle.Subject
        {
            get { return subject; }
            set { subject = value; }
        }

        string INntpArticle.From
        {
            get { return from; }
            set { from = value; }
        }

        string INntpArticle.Date
        {
            get { return date.ToString(); }
            set { date = DateTime.Parse(value); }
        }

        string INntpArticle.References
        {
            get
            {
                if (parent != null)
                {
                    int id = parent.ID;
                    session.Evict(parent);
                    parent = session.Get<DatabaseArticle>(id);
                    
                    string result = parent.messageID;

                    if (((INntpArticle)parent).References != "")
                        result = ((INntpArticle)parent).References + " " + result;

                    return result;
                }

                return "";
            }

            set
            {
                if (value == "")
                {
                    parent = null;
                    return;
                }

                string[] parts = value.Split(' ', '\t');

                ICriteria criteria = session.CreateCriteria(typeof(DatabaseArticle));
                criteria.Add(Expression.Eq("MessageID", parts[parts.Length - 1]));
                parent = criteria.UniqueResult<DatabaseArticle>();

                if (parent == null)
                    throw new ArgumentOutOfRangeException();
            }
        }

        int INntpArticle.Bytes
        {
            get { return bytes; }
        }

        int INntpArticle.Lines
        {
            get { return lines; }
        }

        string INntpArticle.Newsgroups
        {
            get
            {
                StringBuilder result = new StringBuilder();

                foreach (INntpGroup group in groups)
                    result.AppendFormat("{0},", group.Name);

                result.Length = result.Length - 1;
                return result.ToString();
            }

            set
            {
                groups.Clear();

                string[] names = value.Split(',');

                foreach (string name in names)
                {
                    ICriteria criteria = session.CreateCriteria(typeof(DatabaseGroup));
                    criteria.Add(Expression.Eq("Name", name));
                    groups.Add(criteria.UniqueResult<DatabaseGroup>());
                }
            }
        }

        IDictionary<string, string> INntpArticle.Headers
        {
            get { return headers; }
        }

        string INntpArticle.Body
        {
            get
            {
                foreach (string body in bodies)
                    return body;

                return "";
            }
            set
            {
                bodies.Clear();

                if (value != "")
                    bodies.Add(value);

                bytes = value.Length;
                lines = -1;

                for (int index = 0; index != -1; index = value.IndexOf("\0xD\0xA", index))
                    lines++;
            }
        }
    }
}
