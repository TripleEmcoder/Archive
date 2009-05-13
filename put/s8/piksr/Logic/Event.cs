using System.Collections.Generic;

namespace Logic
{
    public class Event
    {
        public int PlayerCount;
        public string Winner;
        public bool AllowMove;
        public IEnumerable<Move> RecentMoves;
        public int NextEvent;
    }
}
