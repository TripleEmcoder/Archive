using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp.Storage.Memory
{
    public class MemoryGroup : INntpGroup
    {
        private string name;
        private Dictionary<int, INntpArticle> articles;

        public MemoryGroup(string name, IEnumerable<INntpArticle> articles)
        {
            this.name = name;
            this.articles = new Dictionary<int, INntpArticle>();

            List<INntpArticle> _articles = new List<INntpArticle>(articles);

            foreach (INntpArticle article in _articles)
                this.articles[_articles.IndexOf(article) + 1] = article;
        }

        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public string Name
        {
            get { return name; }
        }

        public int Count
        {
            get { return articles.Count; }
        }

        public int Low
        {
            get
            {
                int low = int.MaxValue;

                foreach (int number in articles.Keys)
                    low = Math.Min(low, number);

                return low;
            }
        }

        public int High
        {
            get
            {
                int high = int.MinValue;

                foreach (int number in articles.Keys)
                    high = Math.Max(high, number);

                return high;
            }
        }

        public INntpArticle GetArticle(int number)
        {
            if (!articles.ContainsKey(number))
                return null;

            return articles[number];
        }

        public IEnumerable<KeyValuePair<int, INntpArticle>> GetArticles(int low, int high)
        {
            foreach (KeyValuePair<int, INntpArticle> pair in articles)
                if (low <= pair.Key && pair.Key <= high)
                    yield return pair;
        }
    }
}
