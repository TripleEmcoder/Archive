using System;

namespace Logic
{
    public class Move
    {
        private readonly string userNick;
        private readonly int x;
        private readonly int y;

        public Move(string userNick, int x, int y)
        {
            this.userNick = userNick;
            this.x = x;
            this.y = y;
        }

        public string UserNick
        {
            get { return userNick; }
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