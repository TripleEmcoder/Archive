using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public abstract class Algorithm
    {
        public abstract Result Run(Player player, Board board, int depth);
    }
}
