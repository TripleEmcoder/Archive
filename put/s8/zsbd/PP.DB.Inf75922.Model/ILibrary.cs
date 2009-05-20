using System;
using System.Collections.Generic;

namespace PP.DB.Inf75922.Model
{
    public interface ILibrary 
    {
        /// <summary>
        /// Sprawdza, czy w bibliotece znajduje się niewypożyczony egzemplarz książki o podanym tytule.
        /// </summary>
        /// <param name="title">tytuł książki</param>
        /// <returns>true jeżeli istnieje niewypożyczony egzemplarz, false w przeciwnym wypadku</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany tytuł książki ma wartość null
        /// </exception>
        bool IsBookAvailable(string title);

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
        int RentBook(string title, string pesel);

        /// <summary>
        /// Zwraca do biblioteki egzemplarz książki o podanym identyfikatorze.
        /// </summary>
        /// <param name="bookId">identyfikator zwracanego egzemplarza książki</param>
        /// <exception cref="LibraryException">
        /// jeżeli egzemplarz książki o podanym identyfikatorze nie istnieje lub nie jest wypożyczony
        /// </exception>
        void ReturnBook(int bookId);

        /// <summary>
        /// Zwraca listę identyfikatorów wszystkich egzemplarzy książki o podanym tytule.
        /// </summary>
        /// <param name="title">tytuł książki</param>
        /// <returns>lista identyfikatorów istniejących egzemplarzy książki
        /// (w szczególnym przypadku pusta, jeżeli książki nie ma w ogóle w bibliotece)</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany tytuł książki ma wartość null
        /// </exception>
        IList<int> Copies(string title);
      
        /// <summary>
        /// Zwraca numer PESEL użytkownika, który wypożyczył egzemplarz książki o podanym identyfikatorze.
        /// </summary>
        /// <param name="bookId">identyfikator egzemplarza książki</param>
        /// <returns>numer PESEL wypożyczającego użytkownika lub wartość null jeżeli egzemplarz książki nie jest wypożyczony lub nie istnieje</returns>
        string WhoRented(int bookId);

        /// <summary>
        /// Zwraca listę numerów PESEL wszystkich użytkowników zarejestrowanych w bibliotece.
        /// </summary>
        /// <returns>lista numerów PESEL zarejestrowanych użytkowników</returns>
        IList<string> RegisteredUsers();
	
        /// <summary>
        /// Zwraca skonkatenowane imię i nazwisko użytkownika o podanym numerze PESEL.
        /// </summary>
        /// <param name="pesel">numer PESEL użytkownika</param>
        /// <returns>skonkatenowane imię i nazwisko zarejestrowanego użytkownika lub wartość null jeżeli użytkownik nie jest zarejestrowany</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany numer PESEL użytkownika ma wartość null
        /// </exception>
        string UserInfo(string pesel);
	
        /// <summary>
        /// Zwraca listę wszystkich unikalnych tytułów książek w bibliotece.
        /// </summary>
        /// <returns>lista unikalnych tytułów książek w bibliotece</returns>
        IList<string> Titles();

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
        void RegisterUser(string name, string surname, string pesel);

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
        void UnRegisterUser(string pesel);

        /// <summary>
        /// Dodaje do biblioteki egzemplarz książki o podanym tytule.
        /// </summary>
        /// <param name="title">tytuł książki dla dodawanego egzemplarza</param>
        /// <returns>identyfikator dodanego egzemplarza książki</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli podany tytuł książki ma wartość null
        /// </exception>
        void AddBook(string title);

        /// <summary>
        /// Zwraca tytuł egzemplarza książki o podanym identyfikatorze.
        /// </summary>
        /// <param name="bookId">identyfikator egzemplarza książki</param>
        /// <returns>tytuł egzemplarza książki o podanego identyfikatorze lub null jeżeli egzemplarz nie istnieje</returns>
        string BookTitle(int bookId);
	
        /// <summary>
        /// Zwraca listę identyfikatorów egzemplarzy książek wypożyczonych przez użytkownika podanym numerze PESEL.
        /// </summary>
        /// <param name="pesel">numer PESEL użytkownika</param>
        /// <returns>lista identyfikatorów egzemplarzy książek wypożyczonych przez użytkownika podanym numerze PESEL
        /// (w szczególnym przypadku pusta, jeżeli użytkownik nie jest zarejestrowany)</returns>
        /// <exception cref="ArgumentNullException">
        /// jeżeli numer PESEL użytkownika ma wartość null
        /// </exception>
        IList<int> RentedBooks(string pesel);
    }
}