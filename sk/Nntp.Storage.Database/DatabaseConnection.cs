using System;
using System.Collections.Generic;
using System.Text;

using NHibernate;

namespace Nntp.Storage.Database
{
    public class DatabaseConnection : INntpConnection
    {
        private ISession session;

        public DatabaseConnection(ISessionFactory factory)
        {
            session = factory.OpenSession();
        }

        public void Dispose()
        {
            session.Dispose();
        }

        internal ISession Session
        {
            get { return session; }
        }
    }
}
