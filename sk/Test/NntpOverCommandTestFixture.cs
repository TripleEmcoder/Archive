using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;
using NUnit.Framework.SyntaxHelpers;

namespace Test
{
    [TestFixture]
    public class NntpOverCommandTestFixture : NntpCommandTestFixture
    {
        [Test]
        public void TestByMessageId()
        {
            connection.LineSent += AssertResponseCode(224);
            connection.ReceiveLine("OVER <{0}>", existant);
        }

        [Test]
        public void TestByNonexistantMessageID()
        {
            connection.LineSent += AssertResponseCode(430);
            connection.ReceiveLine("OVER <{0}>", nonexistant);
        }

        [Test]
        public void TestByArticleNumberRange()
        {
            connection.ReceiveLine("GROUP {0}", existant);

            connection.LineSent += AssertResponseCode(224);
            connection.ReceiveLine("OVER 1-2");
        }

        [Test]
        public void TestByArticleNumberRangeWithNoGroup()
        {
            connection.LineSent += AssertResponseCode(412);
            connection.ReceiveLine("OVER 1-2");
            connection.ReceiveLine("OVER 2-2");
        }

        [Test]
        public void TestByEmptyArticleNumberRange()
        {
            connection.ReceiveLine("GROUP {0}", existant);

            connection.LineSent += AssertResponseCode(423);
            connection.ReceiveLine("OVER 2-2");
        }

        [Test]
        public void TestByCurrentArticleNumber()
        {
            connection.ReceiveLine("GROUP {0}", existant);

            connection.LineSent += AssertResponseCode(224);
            connection.ReceiveLine("OVER");
        }

        [Test]
        public void TestByCurrentArticleNumberWithNoGroup()
        {
            connection.LineSent += AssertResponseCode(412);
            connection.ReceiveLine("OVER");
        }
    }
}
