using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp
{
    [NntpCommandName("DATE")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("READER")]
    public class NntpDateCommand : NntpCommand
    {
        public NntpDateCommand(string name, string parameters)
            :base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("111 {0}", 
                DateTime.Now.ToUniversalTime().ToString("yyyyMMddHHmmss"));
        }
    }
}
