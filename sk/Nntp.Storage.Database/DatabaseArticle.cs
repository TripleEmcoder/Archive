using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage.Database
{
    public class DatabaseArticle : DatabaseEntity, INntpArticle
    {
        private int id;
        private string messageID;
        private string subject;
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
            get { return messageID; }
        }

        public string Date
        {
            get { return messageID; }
        }

        public string References
        {
            get { return messageID; }
        }

        public int Bytes
        {
            get { return 0; }
        }

        public int Lines
        {
            get { return 0; }
        }

        public string Body
        {
            get { return messageID; }
        }
    }
}
