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
        private string body;

        private ICollection<DatabaseGroup> groups;

        public DatabaseArticle()
        {
            groups = new HashedSet<DatabaseGroup>();
        }

        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        internal virtual int ID
        {
            get { return id; }
        }

        public string MessageID
        {
            get { return messageID; }
        }

        public string Subject
        {
            get { return subject; }
            set { subject = value; }
        }

        public string From
        {
            get { return from; }
            set { from = value; }
        }

        public string Date
        {
            get { return date.ToString(); }
            set { date = DateTime.Parse(value); }
        }

        public string References
        {
            get { return parent == null ? "" : "Xref: " + parent.ID; }
            set { }
        }

        public int Bytes
        {
            get { return bytes; }
        }

        public int Lines
        {
            get { return lines; }
        }

        internal virtual ICollection<DatabaseGroup> Groups
        {
            get { return groups; }
        }

        public string Newsgroups
        {
            get
            {
                StringBuilder result = new StringBuilder();

                foreach (DatabaseGroup group in groups)
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

        public string Body
        {
            get { return body; }
            set
            {
                body = value;
                bytes = body.Length;
                lines = -1;

                for (int index = 0; index != -1; index = body.IndexOf("\0xD\0xA", index))
                    lines++;
            }
        }

        public override LifecycleVeto OnSave(ISession session)
        {
            messageID = Guid.NewGuid().ToString();
            date = DateTime.Now;
            return base.OnSave(session);
        }
    }
}
