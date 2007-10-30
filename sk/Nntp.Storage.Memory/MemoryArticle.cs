using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    public class MemoryArticle : INntpArticle
    {
        private string id;

        public MemoryArticle(string id)
        {
            this.id = id;    
        }

        public string ID
        {
            get { return id; }
        }

        public string Subject
        {
            get { return id; }
        }

        public string From
        {
            get { return id; }
        }

        public string Date
        {
            get { return id; }
        }

        public string References
        {
            get { return id; }
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
            get { return id; }
        }

        public void Dispose()
        {
        }
    }
}
