using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public abstract class Algorithm
    {
        public abstract Result Run(Evaluator evaluator, Board board, Player player, int depth);
    }
}
