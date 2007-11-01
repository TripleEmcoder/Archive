using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;

namespace Test
{
    [TestFixture]
    public class NntpGroupCommandTestFixture : NntpCommandTestFixture
    {
        [Test]
        public void TestByName()
        {
            connection.LineSent += AssertResponseCode(211);
            connection.ReceiveLine("GROUP {0}", existant);
        }

        [Test]
        public void TestByNonexistantName()
        {
            connection.LineSent += AssertResponseCode(411);
            connection.ReceiveLine("GROUP {0}", nonexistant);
        }
    }
}
