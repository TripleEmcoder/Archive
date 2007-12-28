using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public abstract class Evaluator
    {
        public abstract string Name
        {
            get;
        }

        public abstract int Run(Board board, Player player);
    }
}
