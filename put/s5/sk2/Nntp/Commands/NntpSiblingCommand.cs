using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("NEXT")]
    [NntpCommandName("LAST")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("READER")]
    public class NntpSiblingCommand : NntpCommand
    {
        public NntpSiblingCommand(string name)
            : base(name)
        {
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateConnection())
            {
                INntpGroup group;

                if (!GetGroupByCurrentName(connection, session, out group))
                    return;

                KeyValuePair<int, INntpArticle> pair;

                if (!GetArticleByCurrentNumber(connection, session, out pair))
                    return;

                if (name == "NEXT")
                {
                    pair = group.GetNextArticle(pair.Key);

                    if (pair.Value == null)
                    {
                        session.Connection.SendLine("421 No next article in this group");
                        return;
                    }
                }

                if (name == "LAST")
                {
                    pair = group.GetLastArticle(pair.Key);

                    if (pair.Value == null)
                    {
                        session.Connection.SendLine("422 No previous article in this group");
                        return;
                    }
                }
                
                session.Context[typeof(INntpArticle)] = pair.Key;

                session.Connection.SendLine("223 {0} {1}", pair.Key, pair.Value.MessageID);
            }
        }
    }
}