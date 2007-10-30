using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("GROUP")]
    class NntpGroupCommand : NntpCommand
    {
        private string _group;

        public NntpGroupCommand(string name, string parameters)
            : base(name)
        {
            _group = parameters;
        }

        public override void Execute(NntpSession session)
        {
            INntpGroup group = session.Repository.GetGroup(_group);
            session.Save(group);

            session.Connection.SendLine("211 {0} {1} {2} {3}",
                group.Count, group.Low, group.High, group.Name);
        }
    }
}
