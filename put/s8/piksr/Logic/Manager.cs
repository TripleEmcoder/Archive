﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Logic
{
    public class Manager
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

        public Game CreateGame(string gameTitle, int maxPlayerCount, int winningFieldCount, int boardWidth, int boardHeight)
        {
            if (string.IsNullOrEmpty(gameTitle))
                throw new ArgumentNullException(gameTitle);

            lock (games)
            {
                EnsureGameNotExists(gameTitle);
                games[gameTitle] = new Game(gameTitle, maxPlayerCount, winningFieldCount, boardWidth, boardHeight);
                return games[gameTitle];
            }
        }

        public Game GetGame(string gameTitle)
        {
            if (string.IsNullOrEmpty(gameTitle))
                throw new ArgumentNullException(gameTitle);

            lock (games)
            {
                EnsureGameExists(gameTitle);
                return games[gameTitle];
            }
        }

        public IEnumerable<Game> GetGames()
        {
            return games.Values;
        }
    }
}
