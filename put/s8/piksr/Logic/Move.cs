using System;

namespace Logic
{
    public class Move
    {
        private readonly DateTime when;
        private readonly string who;
        private readonly int x;
        private readonly int y;

        public Move(string who, int x, int y)
        {
            when = DateTime.Now;
            this.who = who;
            this.x = x;
            this.y = y;
        }

        public DateTime When
        {
            get { return when; }
        }

        public string Who
        {
            get { return who; }
        }

        public int X
        {
            get { return x; }
        }

        public int Y
        {
            get { return y; }
        }
    }
}