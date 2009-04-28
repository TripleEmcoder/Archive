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
        private readonly int maxPlayerCount;
        private readonly int winningFieldCount;
        private readonly Dictionary<string, Player> players;
        private readonly Player[,] fields;
        private readonly Queue<Player> queue;

        private int playerId;

        public Game(int gameId, int maxPlayerCount, int winningFieldCount, int boardWidth, int boardHeight)
        {
            this.gameId = gameId;
            this.maxPlayerCount = maxPlayerCount;
            this.winningFieldCount = winningFieldCount;
            players = new Dictionary<string, Player>(maxPlayerCount);
            fields = new Player[boardWidth,boardHeight];
            queue = new Queue<Player>(maxPlayerCount);

            playerId = 0;
        }

        private void EnsureGameNotJoined(string userNick)
        {
            if (!players.ContainsKey(userNick))
                throw new InvalidOperationException("User already joined the game.");
        }

        private void EnsureGameJoined(string userNick)
        {
            if (!players.ContainsKey(userNick))
                throw new InvalidOperationException("User never joined the game.");
        }

        private void EnsureGameJoinable(string userNick)
        {
            EnsureGameNotJoined(userNick);

            if (players.Count == maxPlayerCount)
                throw new InvalidOperationException("Maximum number of players reached.");
        }

        private void EnsureFieldEmpty(int x, int y)
        {
            if (fields[x, y] != null)
                throw new InvalidOperationException("Field is not available for move.");
        }

        public void JoinGame(string userNick)
        {
            lock (players)
            {
                EnsureGameJoinable(userNick);
                players[userNick] = new Player(playerId++);
                queue.Enqueue(players[userNick]);
            }
        }

        public void ExitGame(string userNick)
        {
            lock (players)
            {
                EnsureGameJoined(userNick);
                players.Remove(userNick);
            }
        }

        private Player GetPlayer(string userNick)
        {
            lock (players)
            {
                EnsureGameJoined(userNick);
                players[userNick].Touch();
                return players[userNick];
            }
        }

        public bool MakeMove(string userNick, int x, int y, TimeSpan timeout)
        {
            Player player = GetPlayer(userNick);

            Monitor.Enter(queue);

            try
            {
                while (queue.Peek() != player)
                    if (!Monitor.Wait(queue, timeout))
                        return false;

                EnsureFieldEmpty(x, y);
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

        public void WaitMove(string userNick)
        {
            lock (players)
            {
                EnsureGameJoined(userNick);
                players[userNick].Touch();

                lock (fields)
                {

                }
            } 
        }
    }
}
