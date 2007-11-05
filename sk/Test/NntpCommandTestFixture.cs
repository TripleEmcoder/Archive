using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;
using NUnit.Framework.SyntaxHelpers;

using Nntp;
using Nntp.Storage;
using Nntp.Storage.Memory;

namespace Test
{
    [TestFixture]
    public class NntpCommandTestFixture
    {
        protected TestLineConnection connection;
        protected MemoryRepository repository;
        protected NntpSession session;

        protected const string existant = "test1";
        protected const string nonexistant = "test2";

        [SetUp]
        public void SetUp()
        {
            connection = new TestLineConnection();

            List<INntpArticle> articles = new List<INntpArticle>();
            articles.Add(new MemoryArticle("<" + existant + ">"));

            List<INntpGroup> groups = new List<INntpGroup>();
            groups.Add(new MemoryGroup(existant, articles));

            repository = new MemoryRepository(articles, groups);
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
