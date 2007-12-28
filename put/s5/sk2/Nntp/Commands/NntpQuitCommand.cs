using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp
{
    [NntpCommandName("QUIT")]
    [NntpCapabilityName("VERSION 2")]
    public class NntpQuitCommand : NntpCommand
    {
        public NntpQuitCommand(string name)
            : base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("205 Connection closing");
            session.Connection.Close();
        }
    }
}
