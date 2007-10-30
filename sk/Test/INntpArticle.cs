using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    interface INntpArticle : IDisposable
    {
        int Number { get; }
        string Subject { get; }
        string From { get;}
        string Date { get;}
        string MessageID { get;}
        string References { get;}
        int Bytes { get;}
        int Lines { get;}
        string Body { get; }
    }
}
