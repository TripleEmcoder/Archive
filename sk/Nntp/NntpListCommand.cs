using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("LIST")]
    public class NntpListCommand : NntpCommand
    {
        public NntpListCommand(string name, string parameters)
            : base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("215 List of newsgroups follows");

            foreach (INntpGroup group in session.Repository.GetGroups())
                session.Connection.SendLine("{0} {1} {2} {3}",
                    group.Name, group.High, group.Low, "y");

            session.Connection.SendLine(".");
        }
    }
}
