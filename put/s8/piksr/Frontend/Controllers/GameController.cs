using System;
using System.Linq;
using System.Text;
using System.Web.Mvc;
using Logic;

namespace Frontend.Controllers
{
    [HandleError]
    public class GameController : Controller
    {
        private static readonly Manager manager = new Manager();
        private static readonly TimeSpan timeout = TimeSpan.FromSeconds(10);

        static GameController()
        {
            //Game emptyGame = manager.CreateGame("emptyGame", 2, 3, 3, 3);

            //Game joinedGame = manager.CreateGame("joinedGame", 2, 3, 3, 3);
            //joinedGame.JoinPlayer("testUser");

            //Game joinedFullGame = manager.CreateGame("joinedFullGame", 2, 3, 3, 3);
            //joinedFullGame.JoinPlayer("testUser");
            //joinedFullGame.JoinPlayer("testUser1");

            //Game fullGame = manager.CreateGame("fullGame", 2, 3, 3, 3);
            //fullGame.JoinPlayer("testUser1");
            //fullGame.JoinPlayer("testUser2");
            //fullGame.MakeMove("testUser1", 0, 0, TimeSpan.Zero);
            //fullGame.MakeMove("testUser2", 0, 1, TimeSpan.Zero);
            //fullGame.MakeMove("testUser1", 0, 2, TimeSpan.Zero);
            //fullGame.MakeMove("testUser2", 1, 0, TimeSpan.Zero);
            //fullGame.MakeMove("testUser1", 1, 1, TimeSpan.Zero);
            //fullGame.MakeMove("testUser2", 1, 2, TimeSpan.Zero);
            //fullGame.MakeMove("testUser1", 2, 0, TimeSpan.Zero);
            //fullGame.MakeMove("testUser2", 2, 1, TimeSpan.Zero);
            //fullGame.MakeMove("testUser1", 2, 2, TimeSpan.Zero);
        }

        private string UserNick
        {
            get
            {
                Session["pin"] = "pin";
                return Session.SessionID;
            }
        }

        private string Transcode(string text)
        {
            //text = Encoding.ASCII.GetString(Encoding.ASCII.GetBytes(text));
            StringBuilder builder = new StringBuilder();

            foreach (char value in text)
            {
                if (char.IsLetterOrDigit(value))
                    builder.Append(value);
            }

            return builder.ToString();
        }

        public ActionResult Create(string gameTitle, int maxPlayerCount, int boardSize, int winningFieldCount)
        {
            gameTitle = Transcode(gameTitle);
            manager.CreateGame(gameTitle, maxPlayerCount, winningFieldCount, boardSize, boardSize);

            return RedirectToAction("Index");
        }

        public ActionResult Join(string gameTitle)
        {
            gameTitle = Transcode(gameTitle);
            Game game = manager.GetGame(gameTitle);
            game.JoinPlayer(UserNick);

            return RedirectToAction("Index");
        }

        public ActionResult Exit(string gameTitle)
        {
            gameTitle = Transcode(gameTitle);
            Game game = manager.GetGame(gameTitle);
            game.ExitPlayer(UserNick);

            return RedirectToAction("Index");
        }

        public ActionResult Index()
        {
            ViewData["userNick"] = UserNick;

            ViewData["games"] = from game in manager.GetGames()
                                orderby game.Title
                                select game;

            return View();
        }

        public ActionResult Watch(string gameTitle)
        {
            gameTitle = Transcode(gameTitle);
            ViewData["userNick"] = UserNick;
            ViewData["game"] = manager.GetGame(gameTitle);

            return View();
        }

        public ActionResult Play(string gameTitle)
        {
            gameTitle = Transcode(gameTitle);
            ViewData["userNick"] = UserNick;
            ViewData["game"] = manager.GetGame(gameTitle);

            return View("Watch");
        }

        public ActionResult Move(string gameTitle, int firstIndex, int x, int y)
        {
            gameTitle = Transcode(gameTitle);
            Game game = manager.GetGame(gameTitle);
            game.MakeMove(UserNick, x, y, TimeSpan.FromSeconds(10));

            return Info(game, firstIndex);
        }

        public ActionResult Wait(string gameTitle, int firstIndex)
        {
            gameTitle = Transcode(gameTitle);
            Game game = manager.GetGame(gameTitle);

            return Info(game, firstIndex);
        }

        private ActionResult Info(Game game, int firstIndex)
        {
            return Json(new
                            {
                                firstIndex,
                                moves = game.WaitMove(UserNick, firstIndex, timeout),
                                allowMove = game.AllowMove(UserNick),
                                playerCount = game.PlayerCount,
                                winner = game.Winner
                            });
        }

        public ActionResult About()
        {
            return View();
        }
    }
}
