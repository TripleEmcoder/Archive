using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;
using NUnit.Framework.SyntaxHelpers;

namespace Test
{
    [TestFixture]
    public class NntpQuitCommandTestFixture : NntpCommandTestFixture
    {
        [Test]
        public void Test()
        {
            connection.LineSent += AssertResponseCode(205);
            connection.ReceiveLine("QUIT");
        }
    }
}
