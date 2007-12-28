using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public abstract class Algorithm
    {
        protected int hits;
        protected int total;
        protected int done;

        public int Hits
        {
            get { return hits; }
        }

        public int Total
        {
            get { return total; }
        }

        public int Done
        {
            get { return done; }
        }

        public abstract string Name
        {
            get;
        }

        public abstract Result Run(Evaluator evaluator, Board board, Player player, int depth);
    }
}
