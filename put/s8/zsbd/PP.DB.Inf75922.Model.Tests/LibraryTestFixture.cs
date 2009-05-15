using System.Collections.Generic;
using NHibernate;
using NHibernate.Cfg;
using NUnit.Framework;

namespace PP.DB.Inf75922.Model.Tests
{
    [TestFixture]
    public partial class LibraryTestFixture
    {
        private ISessionFactory factory;
        private ILibrary library;

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

                var dawid = new User
                {
                    Name = "Dawid",
                    Surname = "Morzyński",
                    Pesel = "3",
                };

                session.Save(kamil);
                session.Save(marcin);
                session.Save(dawid);

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

                session.Save(ania1);
                session.Save(ania2);
                session.Save(miecz);
                session.Save(wladca);

                ania1.Users.Add(kamil);
                wladca.Users.Add(kamil);
                ania2.Users.Add(marcin);

                transaction.Commit();
            }

            library = new Library();
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
