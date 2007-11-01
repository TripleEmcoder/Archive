using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("GROUP")]
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
            using (INntpTransaction transacion = session.Repository.CreateTransaction())
            {
                INntpGroup group = session.Repository.GetGroup(_group);
                session.Context[typeof(INntpGroup)] = _group;

                session.Connection.SendLine("211 {0} {1} {2} {3}",
                    group.Count, group.Low, group.High, group.Name);
            }
        }
    }
}
