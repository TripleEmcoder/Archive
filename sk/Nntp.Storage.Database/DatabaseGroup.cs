using System;
using System.Collections.Generic;
using System.Text;

using Iesi.Collections.Generic;

using NHibernate;
using NHibernate.Expression;

namespace Nntp.Storage.Database
{
    public class DatabaseGroup : DatabaseEntity, INntpGroup
    {
        private int id;
        private string name;
        private string description;
        private int count;
        private int low;
        private int high;

        private ICollection<DatabaseArticle> articles;

        public DatabaseGroup()
        {
            articles = new HashedSet<DatabaseArticle>();
        }

        public void Dispose()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public virtual int ID
        {
            get { return id; }
        }

        string INntpGroup.Name
        {
            get { return name; }
        }

        string INntpGroup.Description
        {
            get { return description; }
        }

        int INntpGroup.Count
        {
            get { return count; }
        }

        int INntpGroup.Low
        {
            get { return low; }
        }

        int INntpGroup.High
        {
            get { return high; }
        }

        INntpArticle INntpGroup.GetArticle(int number)
        {
            IQuery query = session.CreateFilter(articles,
                "WHERE this.ID = :id");

            query.SetInt32("id", number);

            return query.UniqueResult<INntpArticle>();
        }

        KeyValuePair<int, INntpArticle> INntpGroup.GetNextArticle(int number)
        {
            IQuery query = session.CreateFilter(articles,
                "WHERE this.ID > :id ORDER BY this.ID");

            query.SetInt32("id", number);
            query.SetMaxResults(1);

            DatabaseArticle article = query.UniqueResult<DatabaseArticle>();
            return new KeyValuePair<int, INntpArticle>(article == null ? 0 : article.ID, article);
        }

        KeyValuePair<int, INntpArticle> INntpGroup.GetLastArticle(int number)
        {
            IQuery query = session.CreateFilter(articles,
                "WHERE this.ID < :id ORDER BY this.ID DESC");

            query.SetInt32("id", number);
            query.SetMaxResults(1);

            DatabaseArticle article = query.UniqueResult<DatabaseArticle>();
            return new KeyValuePair<int, INntpArticle>(article == null ? 0 : article.ID, article);
        }

        IEnumerable<KeyValuePair<int, INntpArticle>> INntpGroup.GetArticles(int low, int high)
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
