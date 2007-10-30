using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    class NntpGroup : INntpGroup
    {
        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public string Name
        {
            get { return "projekty.sk.test"; }
        }

        public int Count
        {
            get { return 1234; }
        }

        public int Low
        {
            get {  return 3000234; }
        }

        public int High
        {
            get { return 3002322; }
        }

        public INntpArticle GetArticle(int number)
        {
            return new NntpArticle(number);
        }

        public INntpArticle[] GetArticles(int low, int high)
        {
            INntpArticle[] articles = new INntpArticle[high - low+1];

            for (int id = low; id <= high; id++)
                articles[id - low] = new NntpArticle(id);

            return articles;
        }
    }
}
