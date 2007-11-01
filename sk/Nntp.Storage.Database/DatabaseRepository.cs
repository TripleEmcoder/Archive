using System;
using System.Collections.Generic;
using System.Text;

using System.Collections.ObjectModel;

using NHibernate;
using NHibernate.Cfg;
using NHibernate.Expression;

namespace Nntp.Storage.Database
{
    public class DatabaseRepository : INntpRepository
    {
        private static ISessionFactory factory;

        static DatabaseRepository()
        {
            Configuration configuration = new Configuration();
            configuration.Configure();

            factory = configuration.BuildSessionFactory();
        }

        private DatabaseConnection connection;
        private ITransaction transaction;

        public DatabaseRepository()
        {
        }

        public void Dispose()
        {
        }

        public INntpConnection CreateTransaction()
        {
            connection = new DatabaseConnection(factory);
            return connection;
        }

        public INntpArticle GetArticle(string id)
        {
            ICriteria criteria = connection.Session.CreateCriteria(typeof(INntpArticle));
            criteria.Add(Expression.Eq("MessageID", id));
            return criteria.UniqueResult<INntpArticle>();
        }

        public INntpGroup GetGroup(string name)
        {
            ICriteria criteria = connection.Session.CreateCriteria(typeof(INntpGroup));
            criteria.Add(Expression.Eq("Name", name));
            return criteria.UniqueResult<INntpGroup>();
        }

        public IEnumerable<INntpGroup> GetGroups()
        {
            return connection.Session.CreateQuery("from Groups").List<INntpGroup>();
        }

        public INntpArticle CreateArticle()
        {
            transaction = connection.Session.BeginTransaction();
            DatabaseArticle article = new DatabaseArticle();
            connection.Session.Save(article);
            return article;
        }

        public void PostArticle(INntpArticle article)
        {
            connection.Session.Save(article);
            transaction.Commit();
        }
    }
}
