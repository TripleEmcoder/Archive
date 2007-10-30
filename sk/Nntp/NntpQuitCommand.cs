using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("QUIT")]
    public class NntpQuitCommand : NntpCommand
    {
        public NntpQuitCommand(string name, string parameters)
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
