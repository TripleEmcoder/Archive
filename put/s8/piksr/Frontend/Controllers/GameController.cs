using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Web;
using System.Web.Mvc;
using Logic;

namespace Frontend.Controllers
{
    [HandleError]
    public class GameController : Controller
    {
        private static readonly Manager manager = new Manager();

        private string userNick;

        public GameController()
        {
            userNick = "testUser";
            
            Game emptyGame = manager.Create("emptyGame", 2, 3, 3, 3);

            Game joinedGame = manager.Create("joinedGame", 2, 3, 3, 3);
            joinedGame.Join("testUser");

            Game joinedFullGame = manager.Create("joinedFullGame", 2, 3, 3, 3);
            joinedFullGame.Join("testUser");
            joinedFullGame.Join("testUser1");

            Game fullGame = manager.Create("fullGame", 2, 3, 3, 3);
            fullGame.Join("testUser1");
            fullGame.Join("testUser2");
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

        public ActionResult Create(string gameTitle)
        {
            gameTitle = Transcode(gameTitle);
           // manager.Create(gameTitle);

            return Json(new
                            {
                                Title = gameTitle
                            });
        }

        public ActionResult Join(string gameTitle)
        {
            gameTitle = Transcode(gameTitle);
            Game game = manager.Get(gameTitle);
            game.Join(userNick);
            return View();
        }

        public ActionResult Exit(string id)
        {
            return View();
        }

       
        public ActionResult MakeMove(string id, int x, int y)
        {
            return View();
        }

        public ActionResult WaitMove(string id)
        {
            return View();
        }

        public ActionResult Index()
        {
            ViewData["userNick"] = userNick;
            
            ViewData["games"] = from game in manager
                                orderby game.Title
                                select game;

            return View();
        }

        public ActionResult About()
        {
            return View();
        }
    }
}
