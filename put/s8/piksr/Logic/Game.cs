using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace Logic
{
    public class Game
    {
        private readonly string gameTitle;
        private readonly int maxPlayerCount;
        private readonly int winningFieldCount;
        private readonly Dictionary<string, DateTime> players;
        private readonly List<Move> moves;
        private readonly string[,] fields;
        private readonly Queue<string> queue;
        private readonly object guard;

        private string winner;
        private int eventCount;
        private int nextEvent;

        public Game(string gameTitle, int maxPlayerCount, int winningFieldCount, int boardWidth, int boardHeight)
        {
            this.gameTitle = gameTitle;
            this.maxPlayerCount = maxPlayerCount;
            this.winningFieldCount = winningFieldCount;
            players = new Dictionary<string, DateTime>(maxPlayerCount);
            moves = new List<Move>(boardWidth * boardHeight);
            fields = new string[boardWidth, boardHeight];
            queue = new Queue<string>(maxPlayerCount);
            guard = new object();
        }

        public string Title
        {
            get { return gameTitle; }
        }

        public int BoardWidth
        {
            get { return fields.GetLength(0); }
        }

        public int BoardHeight
        {
            get { return fields.GetLength(1); }
        }

        public int PlayerCount
        {
            get { return players.Count; }
        }

        public int MaxPlayerCount
        {
            get { return maxPlayerCount; }
        }

        public string Winner
        {
            get { return winner; }
        }

        public int NextEvent
        {
            get { return nextEvent; }
        }

        private void EnsurePlayerNotJoined(string userNick)
        {
            if (players.ContainsKey(userNick))
                throw new InvalidOperationException("User already joined the game.");
        }

        private void EnsurePlayerJoined(string userNick)
        {
            if (!players.ContainsKey(userNick))
                throw new InvalidOperationException("User never joined the game.");
        }

        private void EnsurePlayerJoinable(string userNick)
        {
            EnsurePlayerNotJoined(userNick);

            if (players.Count == maxPlayerCount)
                throw new InvalidOperationException("Maximum number of players reached.");
        }

        private void EnsureMovePossible(int x, int y)
        {
            if (fields[x, y] != null)
                throw new InvalidOperationException("Field is not available for move.");

            if (winner != null)
                throw new InvalidOperationException("Game is finished.");
        }

        public bool CanJoin(string userNick)
        {
            return !players.ContainsKey(userNick);
        }

        public void JoinPlayer(string userNick)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            Monitor.Enter(guard);

            try
            {
                EnsurePlayerJoinable(userNick);
                players[userNick] = DateTime.Now;
                queue.Enqueue(userNick);
                
                eventCount++;
                nextEvent++;
                Monitor.PulseAll(guard);
            }
            finally
            {
                Monitor.Exit(guard);
            }
        }

        public void ExitPlayer(string userNick)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            Monitor.Enter(guard);

            try
            {
                EnsurePlayerJoined(userNick);
                players.Remove(userNick);
                
                eventCount++;
                nextEvent++;
                Monitor.PulseAll(guard);
            }
            finally
            {
                Monitor.Exit(guard);
            }
        }

        public bool AllowMove(string userNick)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            if (players.Count < maxPlayerCount)
                return false;

            if (winner != null)
                return false;

            Monitor.Enter(guard);

            try
            {
                return players.ContainsKey(userNick) && queue.Peek() == userNick;
            }
            finally
            {
                Monitor.Exit(guard);
            }
        }

        public bool MakeMove(string userNick, int x, int y, TimeSpan timeout)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            Monitor.Enter(queue);

            try
            {
                while (queue.Peek() != userNick)
                    if (!Monitor.Wait(queue, timeout))
                        return false;

                Monitor.Enter(guard);

                try
                {
                    EnsureMovePossible(x, y);
                    fields[x, y] = userNick;

                    moves.Add(new Move(userNick, x, y));
                    nextEvent++;
                    Monitor.PulseAll(guard);

                    queue.Dequeue();
                    queue.Enqueue(userNick);
                    CheckWinner(userNick);
                }
                finally
                {
                    Monitor.Exit(guard);
                }
            }
            finally
            {
                Monitor.Exit(queue);
            }

            return true;
        }

        public Event WaitEvent(string userNick, int firstEvent, TimeSpan timeout)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            Monitor.Enter(guard);

            try
            {
                if (firstEvent == nextEvent)
                    Monitor.Wait(guard, timeout);

                return new Event
                           {
                               PlayerCount = PlayerCount,
                               Winner = Winner,
                               RecentMoves = moves.Skip(firstEvent - eventCount).ToArray(),
                               AllowMove = AllowMove(userNick),
                               NextEvent = nextEvent
                           };
            }
            finally
            {
                Monitor.Exit(guard);
            }
        }

        private void CheckWinner(string userNick)
        {
            for (int x = 0; x < fields.GetLength(0); x++)
                for (int y = 0; y < fields.GetLength(1); y++)
                {
                    if (FindWinnerHorizontal(userNick, x, y)
                        || FindWinnerVertical(userNick, x, y)
                        || FindWinnerDiagonal1(userNick, x, y)
                        || FindWinnerDiagonal2(userNick, x, y))
                    {
                        winner = userNick;
                        return;
                    }
                }
        }

        private bool FindWinnerHorizontal(string userNick, int x, int y)
        {
            if (x <= fields.GetLength(0) - winningFieldCount)
            {
                for (int x2 = x; x2 < x + winningFieldCount; x2++)
                {
                    if (fields[x2, y] != userNick)
                        return false;
                }

                return true;
            }

            return false;
        }

        private bool FindWinnerVertical(string userNick, int x, int y)
        {
            if (y <= fields.GetLength(1) - winningFieldCount)
            {
                for (int y2 = y; y2 < y + winningFieldCount; y2++)
                {
                    if (fields[x, y2] != userNick)
                        return false;
                }

                return true;
            }

            return false;
        }

        private bool FindWinnerDiagonal1(string userNick, int x, int y)
        {
            if (x <= fields.GetLength(0) - winningFieldCount && y <= fields.GetLength(1) - winningFieldCount)
            {
                for (int x2 = x, y2 = y; x2 < x + winningFieldCount && y2 < y + winningFieldCount; x2++, y2++)
                {
                    if (fields[x2, y2] != userNick)
                        return false;
                }

                return true;
            }

            return false;
        }

        private bool FindWinnerDiagonal2(string userNick, int x, int y)
        {
            if (x <= fields.GetLength(0) - winningFieldCount && y >= winningFieldCount - 1)
            {
                for (int x2 = x, y2 = y; x2 < x + winningFieldCount && y2 >= y - winningFieldCount + 1; x2++, y2--)
                {
                    if (fields[x2, y2] != userNick)
                        return false;
                }

                return true;
            }

            return false;
        }
    }
}
