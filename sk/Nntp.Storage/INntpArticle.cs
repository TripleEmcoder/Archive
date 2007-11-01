using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage
{
    public interface INntpArticle : IDisposable
    {
        string MessageID { get;}
        string Subject { get; set; }
        string From { get; set; }
        string Date { get; set; }
        string References { get; set; }
        int Bytes { get; }
        int Lines { get; }
        string Newsgroups { get; set;}
        string Body { get; set; }
    }
}
