using System.Collections.Generic;
using NHibernate;
using NHibernate.Cfg;
using NUnit.Framework;

namespace PP.DB.Inf75922.Model.Tests
{
    public class TestFixture
    {
        protected ISessionFactory factory;

        [SetUp]
        public void DatabaseSetUp()
        {
            Configuration configuration = new Configuration();
            configuration.Configure(typeof(Library).Assembly, "PP.DB.Inf75922.Model.Library.cfg.xml");

            factory = configuration.BuildSessionFactory();

            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                var kamil = new User
                                {
                                    Name = "Kamil",
                                    Surname = "Serwus",
                                    Pesel = "1",
                                };

                var marcin = new User
                                 {
                                     Name = "Marcin",
                                     Surname = "Mikolajczak",
                                     Pesel = "2",
                                 };

                var ania1 = new Book
                                {
                                    Title = "Ania z zielonej bazy",
                                };

                var ania2 = new Book
                                {
                                    Title = "Ania z zielonej bazy",
                                };

                var miecz = new Book
                                {
                                    Title = "Ogniem i mieczem",
                                };

                var wladca = new Book
                                  {
                                      Title = "Władca pierścienia",
                                  };

                session.Save(kamil);
                session.Save(marcin);
                session.Save(ania1);
                session.Save(ania2);
                session.Save(miecz);
                session.Save(wladca);

                if (kamil.Books == null)
                    kamil.Books = new List<Book>();

                kamil.Books.Add(ania1);
                kamil.Books.Add(wladca);
                session.Save(kamil);

                if (marcin.Books == null)
                    marcin.Books = new List<Book>();

                marcin.Books.Add(ania2);
                session.Save(marcin);

                transaction.Commit();
            }
        }

        [TearDown]
        public void DatabaseTearDown()
        {
            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                session.Delete("FROM User");
                session.Delete("FROM Book");

                transaction.Commit();
            }
        }
    }
}
