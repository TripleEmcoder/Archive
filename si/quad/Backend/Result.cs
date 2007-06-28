using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Result
    {
        public Move move;
        public int value1;

        public Result(Move move, int value)
        {
            this.move = move;
            this.value1 = value;
        }

        public Move Move
        {
            get { return move; }
            set { move = value; }
        }

        public int Value
        {
            get { return value1; }
            set { value1 = value; }
        }

        public override string ToString()
        {
            return String.Format("{0} ({1})",
                move,
                value1);
        }
    }
}
