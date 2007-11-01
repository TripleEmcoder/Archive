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

        private DatabaseTransaction transaction;

        public DatabaseRepository()
        {
        }

        public void Dispose()
        {
        }

        public INntpTransaction CreateTransaction()
        {
            transaction = new DatabaseTransaction(factory);
            return transaction;
        }

        public INntpArticle GetArticle(string id)
        {
            ICriteria criteria = transaction.Session.CreateCriteria(typeof(INntpArticle));
            criteria.Add(Expression.Eq("MessageID", id));
            return criteria.UniqueResult<INntpArticle>();
        }

        public INntpGroup GetGroup(string name)
        {
            ICriteria criteria = transaction.Session.CreateCriteria(typeof(INntpGroup));
            criteria.Add(Expression.Eq("Name", name));
            return criteria.UniqueResult<INntpGroup>();
        }

        public IEnumerable<INntpGroup> GetGroups()
        {
            return transaction.Session.CreateQuery("from Groups").List<INntpGroup>();
        }
    }
}
