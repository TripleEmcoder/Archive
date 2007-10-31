using System;
using System.Collections.Generic;
using System.Text;

using System.Collections.ObjectModel;

using NHibernate;
using NHibernate.Expression;

namespace Nntp.Storage.Database
{
    public class DatabaseGroup : DatabaseEntity, INntpGroup
    {
        private int id;
        private string name;
        private int count;
        private int low;
        private int high;
        private ICollection<INntpArticle> articles;

        public DatabaseGroup()
        {
        }

        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        internal virtual int ID
        {
            get { return id; }
        }

        public virtual string Name
        {
            get { return name; }
            set { name = value; }
        }

        public int Count
        {
            get { return count; }
        }

        public int Low
        {
            get { return low; }
        }

        public int High
        {
            get { return high; }
        }

        public INntpArticle GetArticle(int number)
        {
            foreach (KeyValuePair<int, INntpArticle> pair in GetArticles(number, number))
                return pair.Value;

            return null;
        }

        public IEnumerable<KeyValuePair<int, INntpArticle>> GetArticles(int low, int high)
        {
            IQuery query = session.CreateFilter(articles,
                "WHERE :low <= this.ID AND this.ID <= :high");

            query.SetInt32("low", low);
            query.SetInt32("high", high);

            foreach (DatabaseArticle article in query.List<DatabaseArticle>())
                yield return new KeyValuePair<int, INntpArticle>(article.ID, article);
        }

    }
}
