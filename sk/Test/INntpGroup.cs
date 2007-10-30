using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    interface INntpGroup : IDisposable
    {
        string Name { get; }
        int Count { get; }
        int Low { get; }
        int High { get; }

        INntpArticle GetArticle(int number);
        INntpArticle[] GetArticles(int low, int high);
    }
}
