using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Logic
{
    public class Game
    {
        private readonly int gameId;
        private readonly string gameTitle;
        private readonly int maxPlayerCount;
        private readonly int winningFieldCount;
        private readonly Dictionary<string, Player> players;
        private readonly List<Move> moves;
        private readonly Player[,] fields;
        private readonly Queue<Player> queue;

        private int playerId;

        public Game(int gameId, string gameTitle, int maxPlayerCount, int winningFieldCount, int boardWidth, int boardHeight)
        {
            this.gameId = gameId;
            this.gameTitle = gameTitle;
            this.maxPlayerCount = maxPlayerCount;
            this.winningFieldCount = winningFieldCount;
            players = new Dictionary<string, Player>(maxPlayerCount);
            moves = new List<Move>(boardWidth * boardHeight);
            fields = new Player[boardWidth, boardHeight];
            queue = new Queue<Player>(maxPlayerCount);

            playerId = 0;
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

        public bool IsFull
        {
            get { return players.Count == maxPlayerCount; }
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
        }

        public bool CanJoin(string userNick)
        {
            return !players.ContainsKey(userNick);
        }

        public void JoinPlayer(string userNick)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            lock (players)
            {
                EnsurePlayerJoinable(userNick);
                players[userNick] = new Player(playerId++);
                queue.Enqueue(players[userNick]);
            }
        }

        public void ExitPlayer(string userNick)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            lock (players)
            {
                EnsurePlayerJoined(userNick);
                players.Remove(userNick);
            }
        }

        private Player GetPlayer(string userNick)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            lock (players)
            {
                EnsurePlayerJoined(userNick);
                players[userNick].Touch();
                return players[userNick];
            }
        }

        public IEnumerable<Move> GetMoves(int firstIndex)
        {
            for (int index = firstIndex; index < moves.Count; index++)
                yield return moves[index];
        }

        public bool MakeMove(string userNick, int x, int y, TimeSpan timeout)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            Player player = GetPlayer(userNick);

            Monitor.Enter(queue);

            try
            {
                while (queue.Peek() != player)
                    if (!Monitor.Wait(queue, timeout))
                        return false;

                EnsureMovePossible(x, y);
                fields[x, y] = player;
                moves.Add(new Move(userNick, x, y));

                queue.Dequeue();
                queue.Enqueue(player);
                Monitor.Pulse(queue);
            }
            finally
            {
                Monitor.Exit(queue);
            }

            return true;
        }

        public void WaitMove(string userNick)
        {
            if (string.IsNullOrEmpty(userNick))
                throw new ArgumentNullException(userNick);

            lock (players)
            {
                EnsurePlayerJoined(userNick);
                players[userNick].Touch();

                lock (fields)
                {

                }
            }
        }
    }
}
