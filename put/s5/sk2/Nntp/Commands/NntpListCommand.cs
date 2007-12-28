using System;
using System.Collections.Generic;
using System.Text;

using Nntp.Storage;

namespace Nntp
{
    public abstract class NntpListCommandVariant : NntpCommand
    {
        public NntpListCommandVariant(string name)
            : base("LIST " + name)
        {
        }
    }

    public class NntpListActiveCommandVariant : NntpListCommandVariant
    {
        public NntpListActiveCommandVariant()
            : base("ACTIVE")
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

    public class NntpListNewsgroupsCommandVariant : NntpListCommandVariant
    {
        public NntpListNewsgroupsCommandVariant()
            : base("NEWSGROUPS")
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
                    session.Connection.SendLine("{0}\t{1}",
                        group.Name, group.Description);

                session.Connection.SendLine(".");
            }
        }
    }

    public class NntpListOverviewCommandVariant : NntpListCommandVariant
    {
        public NntpListOverviewCommandVariant()
            : base("OVERVIEW.FMT")
        {
        }

        public override void Execute(NntpSession session)
        {
            session.Connection.SendLine("215 Order of fields in the overview database follows");
            session.Connection.SendLine("Subject:");
            session.Connection.SendLine("From:");
            session.Connection.SendLine("Date:");
            session.Connection.SendLine("Message-ID:");
            session.Connection.SendLine("References:");
            session.Connection.SendLine(":bytes");
            session.Connection.SendLine(":lines");
            session.Connection.SendLine(".");
        }
    }

    [NntpCommandName("LIST")]
    [NntpCapabilityName("VERSION 2")]
    [NntpCapabilityName("READER")]
    [NntpCapabilityName("LIST ACTIVE NEWSGROUPS OVERVIEW.FMT")]
    public class NntpListCommand : NntpCommand
    {
        private static Dictionary<string, Type> variants;

        static NntpListCommand()
        {
            variants = new Dictionary<string, Type>();

            variants[""] = typeof(NntpListActiveCommandVariant);
            variants["ACTIVE"] = typeof(NntpListActiveCommandVariant);
            variants["NEWSGROUPS"] = typeof(NntpListNewsgroupsCommandVariant);
            variants["OVERVIEW.FMT"] = typeof(NntpListOverviewCommandVariant);
        }

        private NntpListCommandVariant variant;

        public NntpListCommand(string name)
            : base(name)
        {
        }

        public override void Parse(string line)
        {
            string name = "";

            if (line != "")
                name = line.Split(new char[] { ' ' }, 1)[0].ToUpper();

            if (!variants.ContainsKey(name))
                throw new ArgumentOutOfRangeException("Unsupported command variant");

            variant = (NntpListCommandVariant)variants[name].GetConstructor(
                new Type[] { }).Invoke(new object[] { });

        }

        public override void Execute(NntpSession session)
        {
            variant.Execute(session);
        }
    }
}
