using System.Linq;
using NUnit.Framework;

namespace PP.DB.Inf75922.Model.Tests
{
    public partial class LibraryTestFixture
    {
        [Test]
        public void TestRegisteredUsers()
        {
            string[] users = library.RegisteredUsers().ToArray();
            Assert.AreEqual(3, users.Length);
            Assert.Contains("1", users);
            Assert.Contains("2", users);
            Assert.Contains("3", users);
        }

        [Test]
        public void TestExistingUserInfo()
        {
            string info = library.UserInfo("1");
            Assert.AreEqual("Kamil Serwus", info);
        }

        [Test]
        public void TestNonExistingUserInfo()
        {
            string info = library.UserInfo("[nieistniejący pesel]");
            Assert.IsNull(info);
        }

        [Test]
        public void TestTitles()
        {
            string[] titles = library.Titles().ToArray();
            Assert.AreEqual(3, titles.Length);
            Assert.Contains("Ania z zielonej bazy", titles);
            Assert.Contains("Ogniem i mieczem", titles);
            Assert.Contains("Władca pierścienia", titles);
        }

        [Test]
        public void TestTwoCopies()
        {
            int[] ids = library.Copies("Ania z zielonej bazy").ToArray();
            Assert.AreEqual(2, ids.Length);

            string title1 = library.BookTitle(ids[0]);
            Assert.AreEqual("Ania z zielonej bazy", title1);
            
            string title2 = library.BookTitle(ids[1]);
            Assert.AreEqual("Ania z zielonej bazy", title2);
        }

        [Test]
        public void TestZeroCopies()
        {
            int[] ids = library.Copies("[nieistniejący tytuł]").ToArray();
            Assert.AreEqual(0, ids.Length);
        }    

        [Test]
        public void TestExistingBookTitle()
        {
            string title = library.BookTitle(2);
            Assert.AreEqual("Ania z zielonej bazy", title);
        }

        [Test]
        public void TestNonExistingBookTitle()
        {
            string title = library.BookTitle(0);
            Assert.IsNull(title);
        }

        [Test]
        public void TestIsExistingBookAvailable()
        {
            bool available = library.IsBookAvailable("Ogniem i mieczem");
            Assert.IsTrue(available);
        }

        [Test]
        public void TestIsExistingBookNotAvailable()
        {
            bool available = library.IsBookAvailable("Ania z zielonej bazy");
            Assert.IsFalse(available);
        }

        [Test]
        public void TestIsNonExistingBookAvailable()
        {
            bool available = library.IsBookAvailable("[nieistniejący tytuł]");
            Assert.IsFalse(available);
        }

        [Test]
        public void TestRentedBooksForUserWithBooks()
        {
            int[] ids = library.RentedBooks("1").ToArray();
            Assert.AreEqual(2, ids.Length);

            string title1 = library.BookTitle(ids[0]);
            Assert.AreEqual("Ania z zielonej bazy", title1);

            string title2 = library.BookTitle(ids[1]);
            Assert.AreEqual("Władca pierścienia", title2);
        }

        [Test]
        public void TestRentedBooksForUserWithoutBooks()
        {
            int[] ids = library.RentedBooks("3").ToArray();
            Assert.AreEqual(0, ids.Length);
        }

        [Test]
        public void TestWhoRentedExistingRentedBook()
        {
            int[] ids = library.Copies("Władca pierścienia").ToArray();
            Assert.AreEqual(1, ids.Length);

            string pesel = library.WhoRented(ids[0]);
            Assert.AreEqual("1", pesel);
        }

        [Test]
        public void TestWhoRentedExistingNotRentedBook()
        {
            int[] ids = library.Copies("Ogniem i mieczem").ToArray();
            Assert.AreEqual(1, ids.Length);

            string pesel = library.WhoRented(ids[0]);
            Assert.IsNull(pesel);
        }

        [Test]
        public void TestWhoRentedNonExistingBook()
        {
            string pesel = library.WhoRented(0);
            Assert.IsNull(pesel);
        }
    }
}