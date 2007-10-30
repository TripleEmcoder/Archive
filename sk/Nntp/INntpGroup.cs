using System;
using System.Collections.Generic;
using System.Text;

using System.Collections.ObjectModel;

namespace Test
{
    public interface INntpGroup : IDisposable
    {
        string Name { get; }
        int Count { get; }
        int Low { get; }
        int High { get; }

        INntpArticle GetArticle(int number);
        ReadOnlyCollection<KeyValuePair<int, INntpArticle>> GetArticles(int low, int high);
    }
}
