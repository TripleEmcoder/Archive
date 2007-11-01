using System;
using System.Collections.Generic;
using System.Text;

using NUnit.Framework;
using NUnit.Framework.SyntaxHelpers;

namespace Test
{
    [TestFixture]
    public class NntpPostCommandTestFixture : NntpCommandTestFixture
    {
       /*
Initial responses
335 Send article to be transferred
435 Article not wanted
436 Transfer not possible; try again later
Subsequent responses
235 Article transferred OK
436 Transfer failed; try again later
437 Transfer rejected; do not retry
        */
    }
}
