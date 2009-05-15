using System;
using NHibernate;
using NHibernate.ByteCode.Castle;
using NHibernate.Cfg;

namespace PP.DB.Inf75922.Model
{
    public partial class Library : ILibrary
    {
        private static readonly ISessionFactory factory;

        static Library()
        {
            Configuration configuration = new Configuration();
            configuration.Configure(typeof(Library).Assembly, "PP.DB.Inf75922.Model.Library.cfg.xml");
            factory = configuration.BuildSessionFactory();

            Type type = typeof(ProxyFactoryFactory);
        }
    }
}
