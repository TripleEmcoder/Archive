using System;
using System.Collections.Generic;
using System.Text;

namespace Nntp
{
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true, Inherited = false)]
    internal class NntpCapabilityNameAttribute : Attribute
    {
        private string name;

        public NntpCapabilityNameAttribute(string name)
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
