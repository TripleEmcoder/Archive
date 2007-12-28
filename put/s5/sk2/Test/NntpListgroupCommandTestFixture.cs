using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;
using NUnit.Framework.SyntaxHelpers;

namespace Test
{
    [TestFixture]
    public class NntpListgroupCommandTestFixture : NntpCommandTestFixture
    {
        [Test]
        public void TestByName()
        {
            connection.LineSent += AssertResponseCode(211);
            connection.ReceiveLine("LISTGROUP {0}", existant);
        }

        [Test]
        public void TestByNonexistantName()
        {
            connection.LineSent += AssertResponseCode(411);
            connection.ReceiveLine("LISTGROUP {0}", nonexistant);
        }

        [Test]
        public void TestByArticleNumberRange()
        {
            connection.LineSent += AssertResponseCode(211);
            connection.ReceiveLine("LISTGROUP {0} 1-2", existant);
            connection.ReceiveLine("LISTGROUP {0} 1-", existant);
        }

        [Test]
        public void TestByArticleNumberRangeWithNonexistantGroup()
        {
            connection.LineSent += AssertResponseCode(411);
            connection.ReceiveLine("LISTGROUP {0} 1-2", nonexistant);
            connection.ReceiveLine("LISTGROUP {0} 1-", nonexistant);
        }

        [Test]
        public void TestByCurrentGroupName()
        {
            connection.ReceiveLine("LISTGROUP {0}", existant);

            connection.LineSent += AssertResponseCode(211);
            connection.ReceiveLine("LISTGROUP");
        }

        [Test]
        public void TestByCurrentGroupNameWithNoGroup()
        {
            connection.LineSent += AssertResponseCode(412);
            connection.ReceiveLine("LISTGROUP");
        }
    }
}
