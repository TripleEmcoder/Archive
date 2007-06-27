using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    class Transposition
    {
        private Result bestMove; 
        private EvaluationBound bound;
        private int depth;
        
        public Transposition(Result bestMove, EvaluationBound bound, int depth)
        {
            this.bestMove = bestMove; 
            this.bound = bound;
            this.depth = depth;
        }

        public int Depth
        {
            get { return depth; }
        }

        public EvaluationBound Bound
        {
            get { return bound; }
        }

        public Result BestMove
        {
            get { return bestMove; }
        }
    }
}
