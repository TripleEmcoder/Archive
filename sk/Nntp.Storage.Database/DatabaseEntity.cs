using System;
using System.Collections.Generic;
using System.Text;

using NHibernate;
using NHibernate.Classic;

namespace Nntp.Storage.Database
{
    public class DatabaseEntity : ILifecycle
    {
        protected ISession session;

        public void OnLoad(ISession session, object id)
        {
            this.session = session;
        }

        public LifecycleVeto OnSave(ISession session)
        {
            this.session = session;
            return LifecycleVeto.NoVeto;
        }

        public LifecycleVeto OnUpdate(ISession session)
        {
            this.session = session;
            return LifecycleVeto.NoVeto;
        }

        public LifecycleVeto OnDelete(ISession session)
        {
            this.session = session;
            return LifecycleVeto.NoVeto;
        }
    }
}
