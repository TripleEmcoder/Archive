using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    class NntpCommandNameAttribute : Attribute
    {
        private string name;

        public NntpCommandNameAttribute(string name)
        {
            this.name = name;
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }
	
    }
}
