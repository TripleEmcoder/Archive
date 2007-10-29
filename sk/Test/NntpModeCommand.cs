using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    [NntpCommandName("MODE")]
    class NntpModeCommand : ILineCommand
    {
        public NntpModeCommand(string command, string parameters)
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
            connection.SendLine("200 Reader mode, posting permitted");
        }
    }
}
