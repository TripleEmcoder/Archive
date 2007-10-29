using System;
using System.Collections.Generic;
using System.Text;

namespace Test
{
    interface ILineCommand
    {
        bool IsComplete
        {
            get;
        }

        void Parse(string line);
        void Execute(ILineConnection connection);
    }
}
