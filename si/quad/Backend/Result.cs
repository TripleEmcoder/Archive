using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Result
    {
        public Move move;
        public int value;

        public Result(Move move, int value)
        {
            this.move = move;
            this.value = value;
        }

        public Move Move
        {
            get { return move; }
        }

        public int Value
        {
            get { return value; }
        }

        public override string ToString()
        {
            return String.Format("{0} ({1})",
                move,
                value);
        }
    }
}
