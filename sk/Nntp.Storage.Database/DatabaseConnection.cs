using System;
using System.Collections.Generic;
using System.Text;

using NHibernate;
using NHibernate.Cfg;
using NHibernate.Expression;

namespace Nntp.Storage.Database
{
    public class DatabaseConnection : INntpConnection
    {
        private static ISessionFactory factory;

        static DatabaseConnection()
        {
            Configuration configuration = new Configuration();
            configuration.Configure();

            factory = configuration.BuildSessionFactory();
        }

        private ITransaction transaction;
        private ISession session;

        public DatabaseConnection()
        {
            session = factory.OpenSession();
        }

        public void Dispose()
        {
            session.Dispose();
        }

        INntpArticle INntpConnection.GetArticle(string id)
        {
            ICriteria criteria = session.CreateCriteria(typeof(INntpArticle));
            criteria.Add(Expression.Eq("MessageID", id));
            return criteria.UniqueResult<INntpArticle>();
        }

        INntpGroup INntpConnection.GetGroup(string name)
        {
            ICriteria criteria = session.CreateCriteria(typeof(INntpGroup));
            criteria.Add(Expression.Eq("Name", name));
            return criteria.UniqueResult<INntpGroup>();
        }

        IEnumerable<INntpGroup> INntpConnection.GetGroups()
        {
            ICriteria criteria = session.CreateCriteria(typeof(INntpGroup));
            return criteria.List<INntpGroup>();
        }

        INntpArticle INntpConnection.CreateArticle()
        {
            transaction = session.BeginTransaction();
            DatabaseArticle article = new DatabaseArticle();
            session.Save(article);
            return article;
        }

        void INntpConnection.PostArticle(INntpArticle article)
        {
            session.Save(article);
            transaction.Commit();
        }
    }
}
