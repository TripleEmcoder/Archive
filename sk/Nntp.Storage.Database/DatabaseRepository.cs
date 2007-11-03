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

        INntpConnection INntpRepository.CreateTransaction()
        {
            connection = new DatabaseConnection(factory);
            return connection;
        }

        INntpArticle INntpRepository.GetArticle(string id)
        {
            ICriteria criteria = connection.Session.CreateCriteria(typeof(INntpArticle));
            criteria.Add(Expression.Eq("MessageID", id));
            return criteria.UniqueResult<INntpArticle>();
        }

        INntpGroup INntpRepository.GetGroup(string name)
        {
            ICriteria criteria = connection.Session.CreateCriteria(typeof(INntpGroup));
            criteria.Add(Expression.Eq("Name", name));
            return criteria.UniqueResult<INntpGroup>();
        }

        IEnumerable<INntpGroup> INntpRepository.GetGroups()
        {
            ICriteria criteria = connection.Session.CreateCriteria(typeof(INntpGroup));
            return criteria.List<INntpGroup>();
        }

        INntpArticle INntpRepository.CreateArticle()
        {
            transaction = connection.Session.BeginTransaction();
            DatabaseArticle article = new DatabaseArticle();
            connection.Session.Save(article);
            return article;
        }

        void INntpRepository.PostArticle(INntpArticle article)
        {
            connection.Session.Save(article);
            transaction.Commit();
        }
    }
}
