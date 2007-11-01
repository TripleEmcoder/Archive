using System;
using System.Collections.Generic;
using System.Text;

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
        }

        public string From
        {
            get { return from; }
        }

        public string Date
        {
            get { return date.ToString(); }
        }

        public string References
        {
            get { return parent.MessageID; }
        }

        public int Bytes
        {
            get { return bytes; }
        }

        public int Lines
        {
            get { return lines; }
        }

        public string Body
        {
            get { return body; }
        }
    }
}
