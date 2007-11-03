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

        string INntpArticle.MessageID
        {
            get { return id; }
        }

        string INntpArticle.Subject
        {
            get { return id; }
            set { }
        }

        string INntpArticle.From
        {
            get { return id; }
            set { }
        }

        string INntpArticle.Date
        {
            get { return id; }
            set { }
        }

        string INntpArticle.References
        {
            get { return id; }
            set { }
        }

        int INntpArticle.Bytes
        {
            get { return 0; }
        }

        int INntpArticle.Lines
        {
            get { return 0; }
        }

        string INntpArticle.Newsgroups
        {
            get { return ""; }
            set { }
        }
        
        IDictionary<string, string> INntpArticle.Headers
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        string INntpArticle.Body
        {
            get { return id; }
            set { }
        }
    }
}
