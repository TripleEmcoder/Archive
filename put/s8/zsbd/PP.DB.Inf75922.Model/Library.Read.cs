using System;
using System.Collections.Generic;
using NHibernate;
using NHibernate.Criterion;

namespace PP.DB.Inf75922.Model
{
    public partial class Library
    {
        /// <summary>
        /// Zwraca listę numerów PESEL wszystkich użytkowników zarejestrowanych w bibliotece.
        /// </summary>
        /// <returns>lista numerów PESEL zarejestrowanych użytkowników</returns>
        public IList<string> RegisteredUsers()
        {
            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<User>()
                    .SetProjection(Projections.Distinct(Projections.Property("Pesel")))
                    .List<string>();
            }
        }

        /// <summary>
        /// Zwraca skonkatenowane imię i nazwisko użytkownika o podanym numerze PESEL.
        /// </summary>
        /// <param name="pesel">numer PESEL użytkownika</param>
        /// <returns>skonkatenowane imię i nazwisko zarejestrowanego użytkownika lub wartość null jeżeli użytkownik nie jest zarejestrowany</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany numer PESEL użytkownika ma wartość null
        /// </exception>
        public string UserInfo(string pesel)
        {
            if (pesel == null)
                throw new ArgumentNullException("pesel");

            using (ISession session = factory.OpenSession())
            {
                User user = session.Get<User>(pesel);

                if (user == null)
                    return null;

                return string.Format("{0} {1}", user.Name, user.Surname);
            }
        }

        /// <summary>
        /// Zwraca listę wszystkich unikalnych tytułów książek w bibliotece.
        /// </summary>
        /// <returns>lista unikalnych tytułów książek w bibliotece</returns>
        public IList<string> Titles()
        {
            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<Book>()
                    .SetProjection(Projections.Distinct(Projections.Property("Title")))
                    .List<string>();
            }
        }

        /// <summary>
        /// Zwraca listę identyfikatorów wszystkich egzemplarzy książki o podanym tytule.
        /// </summary>
        /// <param name="title">tytuł książki</param>
        /// <returns>lista identyfikatorów istniejących egzemplarzy książki
        /// (w szczególnym przypadku pusta, jeżeli książki nie ma w ogóle w bibliotece)</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany tytuł książki ma wartość null
        /// </exception>
        public IList<int> Copies(string title)
        {
            if (title == null)
                throw new ArgumentNullException("title");

            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<Book>()
                    .Add(Restrictions.Eq("Title", title))
                    .SetProjection(Projections.Distinct(Projections.Property("Id")))
                    .List<int>();
            }
        }

        /// <summary>
        /// Zwraca tytuł egzemplarza książki o podanym identyfikatorze.
        /// </summary>
        /// <param name="bookId">identyfikator egzemplarza książki</param>
        /// <returns>tytuł egzemplarza książki o podanego identyfikatorze lub null jeżeli egzemplarz nie istnieje</returns>
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

        /// <summary>
        /// Sprawdza, czy w bibliotece znajduje się niewypożyczony egzemplarz książki o podanym tytule.
        /// </summary>
        /// <param name="title">tytuł książki</param>
        /// <returns>true jeżeli istnieje niewypożyczony egzemplarz, false w przeciwnym wypadku</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany tytuł książki ma wartość null
        /// </exception>
        public bool IsBookAvailable(string title)
        {
            if (title == null)
                throw new ArgumentNullException("title");

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

        /// <summary>
        /// Zwraca listę identyfikatorów egzemplarzy książek wypożyczonych przez użytkownika podanym numerze PESEL.
        /// </summary>
        /// <param name="pesel">numer PESEL użytkownika</param>
        /// <returns>lista identyfikatorów egzemplarzy książek wypożyczonych przez użytkownika podanym numerze PESEL
        /// (w szczególnym przypadku pusta, jeżeli użytkownik nie jest zarejestrowany)</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli numer PESEL użytkownika ma wartość null
        /// </exception>
        public IList<int> RentedBooks(string pesel)
        {
            if (pesel == null)
                throw new ArgumentNullException("pesel");

            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<Book>()
                    .CreateCriteria("Users")
                    .Add(Restrictions.Eq("Pesel", pesel))
                    .SetProjection(Projections.Property("Id"))
                    .List<int>();
            } 
        }

        /// <summary>
        /// Zwraca numer PESEL użytkownika, który wypożyczył egzemplarz książki o podanym identyfikatorze.
        /// </summary>
        /// <param name="bookId">identyfikator egzemplarza książki</param>
        /// <returns>numer PESEL wypożyczającego użytkownika lub wartość null jeżeli egzemplarz książki nie jest wypożyczony lub nie istnieje</returns>
        public string WhoRented(int bookId)
        {
            using (ISession session = factory.OpenSession())
            {
                return session.CreateCriteria<User>()
                    .CreateCriteria("Books")
                    .Add(Restrictions.Eq("Id", bookId))
                    .SetProjection(Projections.Property("Pesel"))
                    .UniqueResult<string>();
            }
        }
    }
}
