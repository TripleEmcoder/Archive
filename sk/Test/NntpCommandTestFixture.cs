using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;
using NUnit.Framework.SyntaxHelpers;

namespace Test
{
    [TestFixture]
    public class NntpCommandTestFixture
    {
        protected TestLineConnection connection;
        protected MemoryRepository repository;
        protected NntpSession session;

        [SetUp]
        public void SetUp()
        {
            connection = new TestLineConnection();

            List<INntpArticle> articles = new List<INntpArticle>();
            articles.Add(new MemoryArticle("test1"));

            List<INntpGroup> groups = new List<INntpGroup>();
            groups.Add(new MemoryGroup("test", articles.AsReadOnly()));

            repository = new MemoryRepository(articles.AsReadOnly(), groups.AsReadOnly());

            session = new NntpSession(connection, repository);
        }

        [TearDown]
        public void TearDown()
        {
            session.Dispose();
        }

        protected EventHandler<LineEventArgs> AssertResponseCode(int code)
        {
            return delegate(object sender, LineEventArgs e)
            {
                Assert.That(e.Line, Text.StartsWith(code.ToString()));
            };
        }
    }
}
