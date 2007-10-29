using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("LIST")]
    class NntpListCommand : ILineCommand
    {
        public NntpListCommand(string command, string parameters)
        {
        }

        public bool IsComplete
        {
            get { return true; }
        }

        public void Parse(string line)
        {
            throw new NotSupportedException();
        }

        public void Execute(ILineConnection connection)
        {
            connection.SendLine("215 list of newsgroups follows");
            connection.SendLine("projekty.sk.test");
            connection.SendLine(".");
        }
    }
}
