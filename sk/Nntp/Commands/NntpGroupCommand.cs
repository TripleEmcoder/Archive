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

        public NntpGroupCommand(string name, string parameters)
            : base(name)
        {
            _group = parameters;
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateTransaction())
            {
                INntpGroup group = session.Repository.GetGroup(_group);

                if (group == null)
                {
                    session.Connection.SendLine("411 No such newsgroup");
                    return;
                }

                session.Context[typeof(INntpGroup)] = _group;
                session.Context[typeof(INntpArticle)] = group.Low;

                session.Connection.SendLine("211 {0} {1} {2} {3}",
                    group.Count, group.Low, group.High, group.Name);
            }
        }
    }
}
