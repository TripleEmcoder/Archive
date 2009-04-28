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
            fields = new Player[boardWidth, boardHeight];
            queue = new Queue<Player>(maxPlayerCount);

            playerId = 0;
        }

        public string Title
        {
            get { return gameTitle; }
        }

        public bool IsFull
        {
            get { return players.Count == maxPlayerCount; }
        }

        private void EnsureNotJoined(string userNick)
        {
            if (players.ContainsKey(userNick))
                throw new InvalidOperationException("User already joined the game.");
        }

        private void EnsureJoined(string userNick)
        {
            if (!players.ContainsKey(userNick))
                throw new InvalidOperationException("User never joined the game.");
        }

        private void EnsureJoinable(string userNick)
        {
            EnsureNotJoined(userNick);

            if (players.Count == maxPlayerCount)
                throw new InvalidOperationException("Maximum number of players reached.");
        }

        private void EnsureFree(int x, int y)
        {
            if (fields[x, y] != null)
                throw new InvalidOperationException("Field is not available for move.");
        }

        public bool CanJoin(string userNick)
        {
            return !players.ContainsKey(userNick);
        }

        public void Join(string userNick)
        {
            lock (players)
            {
                EnsureJoinable(userNick);
                players[userNick] = new Player(playerId++);
                queue.Enqueue(players[userNick]);
            }
        }

        public void Exit(string userNick)
        {
            lock (players)
            {
                EnsureJoined(userNick);
                players.Remove(userNick);
            }
        }

        public Player Get(string userNick)
        {
            lock (players)
            {
                EnsureJoined(userNick);
                players[userNick].Touch();
                return players[userNick];
            }
        }

        public bool Move(string userNick, int x, int y, TimeSpan timeout)
        {
            Player player = Get(userNick);

            Monitor.Enter(queue);

            try
            {
                while (queue.Peek() != player)
                    if (!Monitor.Wait(queue, timeout))
                        return false;

                EnsureFree(x, y);
                fields[x, y] = player;

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

        public void Wait(string userNick)
        {
            lock (players)
            {
                EnsureJoined(userNick);
                players[userNick].Touch();

                lock (fields)
                {

                }
            }
        }
    }
}
