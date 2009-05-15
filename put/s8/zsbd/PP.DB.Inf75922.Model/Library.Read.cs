using System;
using System.Collections.Generic;
using NHibernate;
using NHibernate.Criterion;

namespace PP.DB.Inf75922.Model
{
    public partial class Library
    {
        public IList<string> RegisteredUsers()
        {
            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<User>()
                    .SetProjection(Projections.Distinct(Projections.Property("Pesel")))
                    .List<string>();
            }
        }

        public string UserInfo(string pesel)
        {
            using (ISession session = factory.OpenSession())
            {
                User user = session.Get<User>(pesel);

                if (user == null)
                    return null;

                return string.Format("{0} {1}", user.Name, user.Surname);
            }
        }

        public IList<string> Titles()
        {
            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<Book>()
                    .SetProjection(Projections.Distinct(Projections.Property("Title")))
                    .List<string>();
            }
        }

        public IList<int> Copies(string title)
        {
            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<Book>()
                    .Add(Restrictions.Eq("Title", title))
                    .SetProjection(Projections.Distinct(Projections.Property("Id")))
                    .List<int>();
            }
        }

        public string BookTitle(int bookId)
        {
            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<Book>()
                    .Add(Restrictions.Eq("Id", bookId))
                    .SetProjection(Projections.Distinct(Projections.Property("Title")))
                    .UniqueResult<string>();
            }
        }

        public bool IsBookAvailable(string title)
        {
            using (ISession session = factory.OpenSession())
            {
                int count = session.CreateCriteria<Book>()
                    .Add(Restrictions.Eq("Title", title))
                    .Add(Restrictions.IsEmpty("Users"))
                    .SetProjection(Projections.RowCount())
                    .UniqueResult<int>();

                return count > 0;
            } 
        }

        public IList<int> RentedBooks(string pesel)
        {
            throw new NotImplementedException();
        }

        public string WhoRented(int bookId)
        {
            throw new NotImplementedException();
        }
    }
}
