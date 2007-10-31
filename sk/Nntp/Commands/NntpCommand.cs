using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp
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

        public virtual bool IsComplete
        {
            get { return true; }
        }

        public virtual void Parse(string line)
        {
            throw new NotSupportedException();
        }

        public abstract void Execute(NntpSession session);
    }
}
