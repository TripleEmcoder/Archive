using System.Collections.Generic;

namespace PP.DB.Inf75922.Model
{
    public interface ILibrary 
    {
        /// <summary>
        /// Metoda sprawdza, czy jest w bazie danych egzemplarz książki o podanym
        /// tytule, który jest nie wypożyczony.
        /// </summary>
        /// <param name="title">Tytuł książki</param>
        /// <returns>jeśli jest taki egzemplarz, false, jeśli nie ma</returns>
        bool IsBookAvailable(string title);

        /// <summary>
        /// Wypożycza książkę o zadanym tytule użytkownikowi o zadanym numerze pesel.
        /// </summary>
        /// <param name="title">Tytuł książki</param>
        /// <param name="pesel">Pesel użytkownika</param>
        /// <returns>Unikalny identyfikator egzemplarza</returns>
        /// <exception cref="LibraryException">
        /// LibraryException jeśli nie ma wolnej książki o tym tytule, bądź użytkownik
        /// o zadanym numerze pesel jest niezarejestrowany.
        /// </exception>
        int RentBook(string title, string pesel);

        /// <summary>
        /// Zwraca do biblioteki książkę o zadanym unikalnym identyfikatorze.
        /// </summary>
        /// <param name="bookId">unikaly identyfikator książki</param>
        /// <exception cref="LibraryException">
        /// jeżeli książka nie została wypożyczona, bądź w ogóle nie istnieje.
        /// </exception>
        void ReturnBook(int bookId);

        /// <summary>
        /// Zwraca wektor obiektów typu Integer, przechowujących unikalne 
        /// identyfikatory wszystkich egzemplarzy książki o zadanym tytule.
        /// </summary>
        /// <param name="title">tytuł książki</param>
        /// <returns>wektor identyfikatorów</returns>
        IList<int> Copies(string title);
      
        /// <summary>
        /// Zwraca PESEL użytkownika, który wypożyczył książkę o zadanym
        /// unikalnym identyfikatorze.
        /// </summary>
        /// <param name="bookId">identyfikator książki</param>
        /// <returns>pesel użytkownika</returns>
        string WhoRented(int bookId);

        /// <summary>
        /// Zwraca wektor numerów PESEl wszystkich użytkowników zarejestrowanych
        /// w bibliotece.
        /// </summary>
        /// <returns></returns>
        IList<string> RegisteredUsers();
	
        /// <summary>
        /// Zwraca skonkatenowane imię i nazwisko użytkownika biblioteki o 
        /// zadanym numerze pesel.
        /// </summary>
        /// <param name="pesel"></param>
        /// <returns></returns>
        string UserInfo(string pesel);
	
        /// <summary>
        /// Zwraca wektor wszystkich unikalnych tytułów książek w bibliotece.
        /// </summary>
        /// <returns></returns>
        IList<string> Titles();

        /// <summary>
        /// Rejestruje użytkownika w bibliotece.
        /// </summary>
        /// <param name="name">imie</param>
        /// <param name="surname">nazwisko</param>
        /// <param name="pesel">pesel użytkownika</param>
        /// <exception cref="LibraryException">
        /// Jeżeli PESEL nie jest unikalny
        /// </exception>
        void RegisterUser(string name, string surname, string pesel);

        /// <summary>
        /// Wyrejestrowuje użytkownika z biblioteki. Jest to możliwe jedynie w sytuacji, gdy
        /// użytkownik zwrocił wszystkie wypożyczone książki.
        /// </summary>
        /// <param name="pesel"></param>
        /// <exception cref="LibraryException">
        /// Jeżeli użytkownik posiadał ksiązki
        /// </exception>
        void UnRegisterUser(string pesel);

        /// <summary>
        /// Dodaje książkę o zadanym tytule do bazy danych. Metoda powinna
        /// sama wygenerować unikalny identyfikator dla tej książki. 
        /// </summary>
        /// <param name="title">tytuł książki.</param>
        void AddBook(string title);

        /// <summary>
        /// Zwraca tytuł książki o zadanym unikalnym identyfikatorze.
        /// </summary>
        /// <param name="bookId"></param>
        /// <returns></returns>
        string BookTitle(int bookId);
	
        /// <summary>
        /// Zwraca wektor unikalnych identyfikatorów wszystkich książek wypożyczonych przez użytkownika o
        /// zadanym identyfikatorze pesel.
        /// </summary>
        /// <param name="pesel"></param>
        /// <returns></returns>
        IList<int> RentedBooks(string pesel);
    }
}