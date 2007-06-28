using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

namespace Quad.Backend
{
    class TranspositionTable
    {
        //private Dictionary<int, Transposition> table;
        private Hashtable table;

        public TranspositionTable()
        {
            //this.table = new Dictionary<int, Transposition>();
            this.table = new Hashtable();
        }

        public void Save(Board board, Result result, int alpha, int beta, int depth)
        {
            if (result == null || result.Move == null)
                throw new ArgumentNullException();

            EvaluationBound bound;
            if (result.Value <= alpha)
                bound = EvaluationBound.Upper;
            else if (result.Value >= beta)
                bound = EvaluationBound.Lower;
            else
                bound = EvaluationBound.Accurate;

            //table[board.GetHashCode()] = new Transposition(move, bound, depth);
            table[board.ToString() + result.Move.Player]= new Transposition(result, bound, depth);
        }

        public Transposition Lookup(Board board, Player player)
        {
            //int key = board.GetHashCode();
            //if (table.ContainsKey(key))
            //    return (Transposition)table[key];
            //else
            //    return null;
            return (Transposition)table[board.ToString() + player];
        }
    }
}
