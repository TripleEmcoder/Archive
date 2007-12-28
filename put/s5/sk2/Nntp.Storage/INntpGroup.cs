using System;
using System.Collections.Generic;
using System.Text;

using System.Collections.ObjectModel;

namespace Nntp.Storage
{
    public interface INntpGroup : IDisposable
    {
        string Name { get; }
        string Description { get; }
        int Count { get; }
        int Low { get; }
        int High { get; }

        INntpArticle GetArticle(int number);
        KeyValuePair<int, INntpArticle> GetNextArticle(int number);
        KeyValuePair<int, INntpArticle> GetLastArticle(int number);
        IEnumerable<KeyValuePair<int, INntpArticle>> GetArticles(int low, int high);
    }
}
