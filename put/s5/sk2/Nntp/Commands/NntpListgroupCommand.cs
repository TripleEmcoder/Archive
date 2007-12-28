using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("LISTGROUP")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("READER")]
    public class NntpListgroupCommand : NntpCommand
    {
        private string _group;
        private int low;
        private int high;

        public NntpListgroupCommand(string name)
            : base(name)
        {
        }

        public override void Parse(string line)
        {
            string[] parts = line.Split(' ');

            if (parts.Length >= 1 && parts[0] != "")
                _group = parts[0];

            if (parts.Length == 2)
                ParseRange(parts[1], out low, out high);
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateConnection())
            {
                INntpGroup group;

                if (_group == null)
                {
                    if (!GetGroupByCurrentName(connection, session, out group))
                        return;
                }
                else
                {
                    if (!GetGroupByName(connection, session, _group, out group))
                        return;
                }

                if (low == 0)
                    low = group.Low;

                if (high == 0)
                    high = group.High;

                session.Context[typeof(INntpArticle)] = low; //???

                session.Connection.SendLine("211 {0} {1} {2} {3}",
                    group.Count, group.Low, group.High, group.Name);

                foreach (KeyValuePair<int, INntpArticle> pair in group.GetArticles(low, high))
                    session.Connection.SendLine("{0}", pair.Key);

                session.Connection.SendLine(".");
            }
        }
    }
}