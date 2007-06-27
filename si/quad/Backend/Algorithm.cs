using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public abstract class Algorithm
    {
        protected int hits;

        public int Hits
        {
            get { return hits; }
            set { hits = value; }
        }

        public abstract string Name
        {
            get;
        }

        public abstract Result Run(Evaluator evaluator, Board board, Player player, int depth);
    }
}
