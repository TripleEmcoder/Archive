using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("GROUP")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("READER")]
    public class NntpGroupCommand : NntpCommand
    {
        private string _group;

        public NntpGroupCommand(string name)
            : base(name)
        {
        }

        public override void Parse(string line)
        {
            if (line == "")
                throw new ArgumentException("No group name specified");

            _group = line;
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateConnection())
            {
                INntpGroup group;

                if (!GetGroupByName(connection, session, _group, out group))
                    return;

                session.Connection.SendLine("211 {0} {1} {2} {3}",
                    group.Count, group.Low, group.High, group.Name);
            }
        }
    }
}
