using PP.DB.Inf75922.Model;

namespace PP.DB.Inf75922.Runner
{
    class Program
    {
        static void Main(string[] args)
        {
            Library library = new Library();
            library.AddBook("Pan Tadeusz");
            library.RegisterUser("Marcin", "Mikołajczak", "86061701696");
        }
    }
}
