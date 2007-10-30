using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("POST")]
    class NntpPostCommand : NntpCommand
    {
        public NntpPostCommand(string name, string parameters)
            : base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("340 Send article to be posted");
        }
    }
}
