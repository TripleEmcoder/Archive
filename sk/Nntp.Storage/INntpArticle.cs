using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage
{
    public interface INntpArticle : IDisposable
    {
        string MessageID { get;}
        string Subject { get; }
        string From { get;}
        string Date { get;}
        string References { get; }
        int Bytes { get;}
        int Lines { get;}
        //string Newsgroups { get; }
        string Body { get; }
    }
}
