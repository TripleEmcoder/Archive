using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    [NntpCommandName("OVER")]
    [NntpCommandName("XOVER")]
    public class NntpOverCommand : NntpCommand
    {
        private int low;
        private int high;

        public NntpOverCommand(string name, string parameters)
            : base(name)
        {
            try
            {
                string[] parts = parameters.Split(new char[] { '-' }, 2);

                low = high = int.Parse(parts[0]);

                if (parts.Length == 2)
                    high = (parts[0] == "") ? 0 : int.Parse(parts[1]);
            }
            catch (Exception exception)
            {
                throw new ArgumentException("Syntax error", exception);
            }
        }

        public override void Execute(NntpSession session)
        {
            using (INntpConnection connection = session.Repository.CreateTransaction())
            {
                if (!session.Context.ContainsKey(typeof(INntpGroup)))
                {
                    session.Connection.SendLine("412 No newsgroup selected");
                    return;
                }

                INntpGroup group = session.Repository.GetGroup(
                    (string)session.Context[typeof(INntpGroup)]);

                List<KeyValuePair<int, INntpArticle>> pairs =
                    new List<KeyValuePair<int, INntpArticle>>(group.GetArticles(low, high));

                session.Connection.SendLine("224 Overview information follows");

                foreach (KeyValuePair<int, INntpArticle> pair in pairs)
                    session.Connection.SendLine("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}\t{7}",
                            pair.Key, pair.Value.Subject, pair.Value.From, pair.Value.Date,
                            pair.Value.MessageID, pair.Value.References, pair.Value.Bytes, pair.Value.Lines);

                session.Connection.SendLine(".");
            }
        }
    }
}