using System;
using System.Diagnostics;
using NHibernate;
using NHibernate.Criterion;

namespace PP.DB.Inf75922.Model
{
    public partial class Library
    {
        /// <summary>
        /// Rejestruje użytkownika o podanych personaliach w bibliotece.
        /// </summary>
        /// <param name="name">imię rejestrowanego użytkownika</param>
        /// <param name="surname">nazwisko rejestrowanego użytkownika</param>
        /// <param name="pesel">numer PESEL rejestrowanego użytkownika</param>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podane imię, nazwisko lub numer PESEL rejestrowanego użytkownika ma wartość null
        /// </exception>
        /// <exception cref="LibraryException">
        /// jeżeli numer PESEL rejestrowanego użytkownika pokrywa się z numerem PESEL istniejącego użytkownika
        /// </exception>
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

        /// <summary>
        /// Wyrejestrowuje użytkownika o podanym numerze PESEL z biblioteki.
        /// </summary>
        /// <param name="pesel">numer PESEL wyrejestrowywanego użytkownika</param>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany numer PESEL wyrejestrowywanego użytkownika ma wartość null
        /// </exception>
        /// <exception cref="LibraryException">
        /// jeżeli użytkownik o podanym numerze PESEL nie istnieje lub posiada wypożyczone książki
        /// </exception>
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

        /// <summary>
        /// Dodaje do biblioteki egzemplarz książki o podanym tytule.
        /// </summary>
        /// <param name="title">tytuł książki dla dodawanego egzemplarza</param>
        /// <returns>identyfikator dodanego egzemplarza książki</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany tytuł książki ma wartość null
        /// </exception>
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

        /// <summary>
        /// Wypożycza książkę o podanym tytule użytkownikowi o podanym numerze PESEL.
        /// </summary>
        /// <param name="title">tytuł wypożyczanej książki</param>
        /// <param name="pesel">numer PESEL wypożyczającego użytkownika</param>
        /// <returns>identyfikator wypożyczonego egzemplarza książki</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany tytuł wypożyczanej książki lub podany numer PESEL wypożyczającego użytkownika ma wartość null
        /// </exception>
        /// <exception cref="LibraryException">
        /// jeżeli nie ma niewypożyczonego egzemplarza książki o podanym tytule lub użytkownik o podanym numerze PESEL nie jest zarejestrowany
        /// </exception>
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

        /// <summary>
        /// Zwraca do biblioteki egzemplarz książki o podanym identyfikatorze.
        /// </summary>
        /// <param name="bookId">identyfikator zwracanego egzemplarza książki</param>
        /// <exception cref="LibraryException">
        /// jeżeli egzemplarz książki o podanym identyfikatorze nie istnieje lub nie jest wypożyczony
        /// </exception>
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
