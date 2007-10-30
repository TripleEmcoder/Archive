using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    public abstract class NntpCommand
    {
        private string name;

        public NntpCommand(string name)
        {
            this.name = name;
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }
	
        public override string ToString()
        {
            return name;
        }

        public bool IsComplete
        {
            get { return true; }
        }

        public void Parse(string line)
        {
            throw new NotSupportedException();
        }

        public abstract void Execute(NntpSession session);
    }
}
