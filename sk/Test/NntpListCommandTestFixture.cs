using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;

namespace Test
{
    [TestFixture]
    public class NntpListCommandTestFixture : NntpCommandTestFixture
    {
        [Test]
        public void TestByMessageId()
        {
            connection.LineSent += AssertResponseCode(215);
            connection.ReceiveLine("LIST");
        }
    }
}
