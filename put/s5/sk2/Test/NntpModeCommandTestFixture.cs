using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;

namespace Test
{
    [TestFixture]
    public class NntpModeCommandTestFixture : NntpCommandTestFixture
    {
        [Test]
        public void TestReader()
        {
            connection.LineSent += AssertResponseCode(200);
            connection.ReceiveLine("MODE READER");
        }
    }
}
