using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("OVER")]
    [NntpCommandName("XOVER")]
    class NntpOverCommand : NntpCommand
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
            INntpGroup group = session.Get<INntpGroup>();
            session.Connection.SendLine("224 Overview information follows (multi-line)");

            foreach (INntpArticle article in group.GetArticles(low, high))
                session.Connection.SendLine("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}\t{7}",
                        article.Number, article.Subject, article.From, article.Date,
                        article.MessageID, article.References, article.Bytes, article.Lines);

            session.Connection.SendLine(".");
        }
    }
}