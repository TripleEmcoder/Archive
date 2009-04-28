using System;

namespace Logic
{
    public class Player
    {
        private readonly int playerId;
        private DateTime lastActivity;

        public Player(int playerId)
        {
            this.playerId = playerId;
            lastActivity = DateTime.Now;
        }

        public void Touch()
        {
            lastActivity = DateTime.Now;
        }
    }
}