using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Transition
    {
        private List<Move> moves;

        public Transition()
        {
            moves = new List<Move>();
        }

        public List<Move> Moves
        {
            get { return moves; }
        }
    }
}
