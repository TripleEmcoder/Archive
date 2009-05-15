using System;
using NUnit.Framework;

namespace PP.DB.Inf75922.Model.Tests
{
    public partial class LibraryTestFixture
    {
        [Test]
        public void TestRegisterUser()
        {
            library.RegisterUser("Jan", "Kowalski", "3");
            string info = library.UserInfo("3");
            Assert.AreEqual("Jan Kowalski", info);
        }

        [Test]
        [ExpectedException(typeof(LibraryException), ExpectedMessage = "Pesel is not unique")]
        public void TestRegisterDuplicateUser()
        {
            library.RegisterUser("Jan", "Kowalski", "3");
            string info = library.UserInfo("3");
            Assert.AreEqual("Jan Kowalski", info);
            library.RegisterUser("Jan", "Kowalski", "3");
        }

        [Test]
        public void TestUnRegisterUser()
        {
            string beforeInfo = library.UserInfo("3");
            Assert.AreEqual("Jan Kowalski", beforeInfo);
            library.UnRegisterUser("3");
            string afterInfo = library.UserInfo("3");
            Assert.IsNull(afterIfo);
        }

        [Test]
        public void TestAddBook()
        {
            string title = "Pan Taduesz";
            int beforeCount = library.Copies(title).Count;
            library.AddBook(title);
            int afterCount = library.Copies(title).Count;
            Assert.AreEqual(beforeCount + 1, afterCount);
        }      

        public int TestRentBook(string title, string pesel)
        {
            throw new NotImplementedException();
        }

        public void TestReturnBook(int bookId)
        {
            throw new NotImplementedException();
        }
    }
}
