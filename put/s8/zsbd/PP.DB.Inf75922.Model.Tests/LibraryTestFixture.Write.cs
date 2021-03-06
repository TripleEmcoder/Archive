﻿using System;
using System.Collections.Generic;
using System.Linq;
using NHibernate;
using NHibernate.Criterion;
using NHibernate.Transform;
using NUnit.Framework;

namespace PP.DB.Inf75922.Model.Tests
{
    public partial class LibraryTestFixture
    {
        [Test]
        public void TestRegisterUserWithNonExistingPesel()
        {
            library.RegisterUser("Jan", "Kowalski", "0");

            string info = library.UserInfo("0");
            Assert.AreEqual("Jan Kowalski", info);
        }

        [Test]
        public void TestRegisterUserWithExistingPesel()
        {
            library.RegisterUser("Jan", "Kowalski", "0");

            string info = library.UserInfo("0");
            Assert.AreEqual("Jan Kowalski", info);

            Assert.Throws(typeof(LibraryException), () => library.RegisterUser("Jan", "Kowalski", "0"));
        }

        [Test]
        public void TestRegisterUserWithNullPesel()
        {
            Assert.Throws(typeof(ArgumentNullException), () => library.RegisterUser("Jan", "Kowalski", null));
        }

        [Test]
        public void TestRegisterUserWithNullName()
        {
            Assert.Throws(typeof(ArgumentNullException), () => library.RegisterUser(null, "Kowalski", "0"));
        }

        [Test]
        public void TestRegisterUserWithNullSurname()
        {
            Assert.Throws(typeof(ArgumentNullException), () => library.RegisterUser("Jan", null, "0"));
        }

        [Test]
        public void TestUnRegisterExistingWithoutRentedBooksUser()
        {
            string beforeInfo = library.UserInfo("3");
            Assert.AreEqual("Dawid Morzyński", beforeInfo);

            library.UnRegisterUser("3");

            string afterInfo = library.UserInfo("3");
            Assert.IsNull(afterInfo);
        }

        [Test]
        public void TestUnRegisterExistingWithRentedBooksUser()
        {
            string beforeInfo = library.UserInfo("1");
            Assert.AreEqual("Kamil Serwus", beforeInfo);

            Assert.Throws(typeof(LibraryException), () => library.UnRegisterUser("1"));
        }

        [Test]
        public void TestUnRegisterNonExistingUser()
        {
            string beforeInfo = library.UserInfo("0");
            Assert.AreEqual(null, beforeInfo);

            Assert.Throws(typeof(LibraryException), () => library.UnRegisterUser("0"));
        }

        [Test]
        public void TestUnRegisterUserWithNullPesel()
        {
            Assert.Throws(typeof(ArgumentNullException), () => library.UnRegisterUser(null));
        }

        [Test]
        public void TestAddNewBook()
        {
            string title = "Pan Taduesz";

            int beforeCount = library.Copies(title).Count;
            Assert.AreEqual(0, beforeCount);

            library.AddBook(title);

            int afterCount = library.Copies(title).Count;
            Assert.AreEqual(1, afterCount);
        }

        [Test]
        public void TestAddExistingBook()
        {
            string title = "Ania z zielonej bazy";

            int beforeCount = library.Copies(title).Count;
            Assert.Greater(beforeCount, 0);

            library.AddBook(title);

            int afterCount = library.Copies(title).Count;
            Assert.AreEqual(beforeCount + 1, afterCount);
        }

        [Test]
        public void TestAddBookWithNullTitle()
        {
            Assert.Throws(typeof(ArgumentNullException), () => library.AddBook(null));
        }

        [Test]
        public void TestRentExistingAvailableBookToExistingUser()
        {
            int rentedId = library.RentBook("Ogniem i mieczem", "1");
            string rentedTitle = library.BookTitle(rentedId);
            Assert.AreEqual("Ogniem i mieczem", rentedTitle);
            string rentedPesel = library.WhoRented(rentedId);
            Assert.AreEqual("1", rentedPesel);
        }

        [Test]
        public void TestRentExistingAvailableBookToNonExistingUser()
        {
            Assert.Throws(typeof(LibraryException), () => library.RentBook("Ogniem i mieczem", "[nieistniejący pesel]"));
        }

        [Test]
        public void TestRentExistingNotAvailableBookToExistingUser()
        {
            Assert.Throws(typeof(LibraryException), () => library.RentBook("Ania z zielonej bazy", "1"));
        }

        [Test]
        public void TestRentExistingNotAvailableBookToNonExistingUser()
        {
            Assert.Throws(typeof(LibraryException), () => library.RentBook("Ania z zielonej bazy", "[nieistniejący pesel]"));
        }

        [Test]
        public void TestRentNonExistingBookToExistingUser()
        {
            Assert.Throws(typeof(LibraryException), () => library.RentBook("[nieistniejący tytuł]", "1"));
        }

        [Test]
        public void TestRentNonExistingBookToNonExistingUser()
        {
            Assert.Throws(typeof(LibraryException), () => library.RentBook("[nieistniejący tytuł]", "[nieistniejący pesel]"));
        }

        [Test]
        public void TestRentBookWithNullTitle()
        {
            Assert.Throws(typeof(ArgumentNullException), () => library.RentBook(null, "[dowolny pesel]"));
        }

        [Test]
        public void TestRentBookWithNullPesel()
        {
            Assert.Throws(typeof(ArgumentNullException), () => library.RentBook("[dowolny tytuł]", null));
        }

        [Test]
        public void TestReturnExistingRentedBook()
        {
            int[] ids = library.Copies("Władca pierścienia").ToArray();
            Assert.AreEqual(1, ids.Length);

            string beforePesel = library.WhoRented(ids[0]);
            Assert.AreEqual("1", beforePesel);

            library.ReturnBook(ids[0]);

            string afterPesel = library.WhoRented(ids[0]);
            Assert.IsNull(afterPesel);
        }

        [Test]
        public void TestReturnExistingNotRentedBook()
        {
            int[] ids = library.Copies("Ogniem i mieczem").ToArray();
            Assert.AreEqual(1, ids.Length);

            string pesel = library.WhoRented(ids[0]);
            Assert.IsNull(pesel);

            Assert.Throws(typeof(LibraryException), () => library.ReturnBook(ids[0]));
        }

        [Test]
        public void TestReturnNonExistingBook()
        {
            Assert.Throws(typeof(LibraryException), () => library.ReturnBook(0));
        }
    }
}
