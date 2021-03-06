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

        public override string ToString()
        {
            if (moves.Count == 0)
                return "";

            return String.Format("{0} ({1})",
                moves[0],
                moves.Count
            );
        }
    }
}
