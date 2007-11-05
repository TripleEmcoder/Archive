using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("LIST")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("LIST")]
    public class NntpListCommand : NntpCommand
    {
        public NntpListCommand(string name)
            : base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateConnection())
            {
                List<INntpGroup> groups =
                    new List<INntpGroup>(connection.GetGroups());

                session.Connection.SendLine("215 List of newsgroups follows");

                foreach (INntpGroup group in groups)
                    session.Connection.SendLine("{0} {1} {2} {3}",
                        group.Name, group.High, group.Low, "y");

                session.Connection.SendLine(".");
            }
        }
    }
}
