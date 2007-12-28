using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp
{
    [NntpCommandName("NEWGROUPS")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("READER")]
    public class NntpNewgroupsCommand : NntpCommand
    {
        public NntpNewgroupsCommand(string name)
            :base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("231 List of new newsgroups follows");
            session.Connection.SendLine(".");
        }
    }
}
