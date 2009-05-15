using System;
using NHibernate;

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
                throw new NotImplementedException();
            } 
        }

        public void ReturnBook(int bookId)
        {
            using (ISession session = factory.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                throw new NotImplementedException();
            } 
        }
    }
}
