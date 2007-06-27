using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

namespace Quad.Backend
{
    class TranspositionTable
    {
        private Hashtable table;
        
        public TranspositionTable()
        {
            this.table = new Hashtable();
        }

        public void Save(Board board, Result move, int alpha, int beta, int depth)
        {
            EvaluationBound bound;
            if (move.Value <= alpha)
                bound = EvaluationBound.Upper;
            else if (move.Value >= beta)
                bound = EvaluationBound.Lower;
            else
                bound = EvaluationBound.Accurate;

            table[board.Clone()] = new Transposition(move, bound, depth);
        }

        public Transposition Lookup(Board board)
        {
            return (Transposition)table[board];
        }
    }
}
