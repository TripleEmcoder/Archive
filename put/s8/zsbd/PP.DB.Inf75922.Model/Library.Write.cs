using System;
using System.Diagnostics;
using NHibernate;
using NHibernate.Criterion;

namespace PP.DB.Inf75922.Model
{
    public partial class Library
    {
        public void RegisterUser(string name, string surname, string pesel)
        {
            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                if (session.Get<User>(pesel) != null)
                    throw new LibraryException("User with given PESEL already exists");

                User user = new User();
                user.Pesel = pesel;
                user.Name = name;
                user.Surname = surname;

                session.Save(user);
                transaction.Commit();
            }
        }

        public void UnRegisterUser(string pesel)
        {
            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                throw new NotImplementedException();
            }
        }

        public void AddBook(string title)
        {
            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                Book book = new Book();
                book.Title = title;
                session.Save(book);
                transaction.Commit();
            }
        }

        public int RentBook(string title, string pesel)
        {
            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                Book book = session.CreateCriteria<Book>()
                    .Add(Restrictions.Eq("Title", title))
                    .Add(Restrictions.IsEmpty("Users"))
                    .SetMaxResults(1)
                    .UniqueResult<Book>();

                User user = session.Get<User>(pesel);

                book.Users.Add(user);
                transaction.Commit();

                return book.Id;
            } 
        }

        public void ReturnBook(int bookId)
        {
            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                Book book = session.Get<Book>(bookId);

                if (book == null)
                    throw new LibraryException("No book with given id");

                Debug.Assert(book.Users.Count == 1);
                book.Users.Clear();
                transaction.Commit();
            } 
        }
    }
}
