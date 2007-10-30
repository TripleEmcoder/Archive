using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("MODE")]
    class NntpModeCommand : NntpCommand
    {
        public NntpModeCommand(string name, string parameters)
            :base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("200 Reader mode, posting permitted");
        }
    }
}
