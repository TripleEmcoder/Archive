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
            if (pesel == null)
                throw new ArgumentNullException("pesel");

            if (name == null)
                throw new ArgumentNullException("name");

            if (surname == null)
                throw new ArgumentNullException("surname");

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
                User user = session.Get<User>(pesel);

                if (user == null)
                    throw new LibraryException("User with given PESEL does not exist");

                if (user.Books.Count > 0)
                    throw new LibraryException("User with given PESEL has rented books");

                session.Delete(user);
                transaction.Commit();
            }
        }

        public void AddBook(string title)
        {
            if (title == null)
                throw new ArgumentNullException("title");

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
            if (title == null)
                throw new ArgumentNullException("title");

            if (pesel == null)
                throw new ArgumentNullException("pesel");

            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                Book book = session.CreateCriteria<Book>()
                    .Add(Restrictions.Eq("Title", title))
                    .Add(Restrictions.IsEmpty("Users"))
                    .SetMaxResults(1)
                    .UniqueResult<Book>();

                if (book == null)
                    throw new LibraryException("Book with given title is not available");

                User user = session.Get<User>(pesel);

                if (user == null)
                    throw new LibraryException("User with given PESEL does not exist");

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
                    throw new LibraryException("Book with given id does not exist");

                if (book.Users.Count == 0)
                    throw new LibraryException("Book with given id is not rented");

                Debug.Assert(book.Users.Count == 1);
                book.Users.Clear();
                transaction.Commit();
            } 
        }
    }
}
