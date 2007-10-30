using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;
using NUnit.Framework.SyntaxHelpers;

namespace Test
{
    [TestFixture]
    public class NntpArticleCommandTestFixture : NntpCommandTestFixture
    {
        #region TestByMessageId*

        [Test]
        public void TestByMessageId()
        {
            connection.LineSent += AssertResponseCode(220);
            connection.ReceiveLine("ARTICLE <test1>");
        }

        [Test]
        public void TestByMessageIdThatDoesntExist()
        {
            connection.LineSent += AssertResponseCode(430);
            connection.ReceiveLine("ARTICLE <test2>");
        }

        #endregion

        #region TestByArticleNumer*

        [Test]
        public void TestByArticleNumber()
        {
            connection.ReceiveLine("GROUP test");

            connection.LineSent += AssertResponseCode(220);
            connection.ReceiveLine("ARTICLE 1");
        }

        [Test]
        public void TestByArticleNumberThatDoesntExist()
        {
            connection.ReceiveLine("GROUP test");

            connection.LineSent += AssertResponseCode(423);
            connection.ReceiveLine("ARTICLE 2");
        }

        [Test]
        public void TestByArticleNumberWithNoGroup()
        {
            connection.LineSent += AssertResponseCode(412);
            connection.ReceiveLine("ARTICLE 1");
            connection.ReceiveLine("ARTICLE 2");
        }

        #endregion

        #region TestByCurrentArticleNumer*

        [Test]
        public void TestByCurrentArticleNumber()
        {
            connection.ReceiveLine("GROUP test");

            connection.LineSent += AssertResponseCode(220);
            connection.ReceiveLine("ARTICLE");
        }

        [Test]
        public void TestCurrentWithNoGroup()
        {
            connection.LineSent += AssertResponseCode(412);
            connection.ReceiveLine("ARTICLE");
        }

        #endregion
    }
}
