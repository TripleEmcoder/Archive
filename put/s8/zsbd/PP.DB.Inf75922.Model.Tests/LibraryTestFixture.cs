using NUnit.Framework;

namespace PP.DB.Inf75922.Model.Tests
{
    [TestFixture]
    public partial class LibraryTestFixture : TestFixture
    {
        private ILibrary library;

        [SetUp]
        public void LibrarySetUp()
        {
            DatabaseSetUp();
            library = new Library();
        }
    }
}
