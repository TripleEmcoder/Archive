using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Logic
{
    public class Manager : IEnumerable<Game>
    {
        private readonly Dictionary<string, Game> games;
        private int gameId;

        public Manager()
        {
            games = new Dictionary<string, Game>();
            gameId = 0;
        }

        private void EnsureGameNotExists(string gameTitle)
        {
            if (games.ContainsKey(gameTitle))
                throw new InvalidOperationException("Game already exists.");
        }

        private void EnsureGameExists(string gameTitle)
        {
            if (!games.ContainsKey(gameTitle))
                throw new InvalidOperationException("No such game exists.");
        }

        public Game Create(string gameTitle, int maxPlayerCount, int winningFieldCount, int boardWidth, int boardHeight)
        {
            lock (games)
            {
                EnsureGameNotExists(gameTitle);
                games[gameTitle] = new Game(gameId++, gameTitle, maxPlayerCount, winningFieldCount, boardWidth, boardHeight);
                return games[gameTitle];
            }
        }

        public Game Get(string gameTitle)
        {
            lock (games)
            {
                EnsureGameExists(gameTitle);
                return games[gameTitle];
            }
        }

        public IEnumerator<Game> GetEnumerator()
        {
            return games.Values.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
