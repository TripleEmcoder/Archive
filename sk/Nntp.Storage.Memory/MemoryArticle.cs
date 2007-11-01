using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage.Memory
{
    public class MemoryArticle : INntpArticle
    {
        private string id;

        public MemoryArticle(string id)
        {
            this.id = id;    
        }

        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public string MessageID
        {
            get { return id; }
        }

        public string Subject
        {
            get { return id; }
            set { }
        }

        public string From
        {
            get { return id; }
            set { }
        }

        public string Date
        {
            get { return id; }
            set { }
        }

        public string References
        {
            get { return id; }
            set { }
        }

        public int Bytes
        {
            get { return 0; }
        }

        public int Lines
        {
            get { return 0; }
        }

        public string Newsgroups
        {
            get { return ""; }
            set { }
        }

        public string Body
        {
            get { return id; }
            set { }
        }
    }
}
