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
            userNick = Session.SessionID;    
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

        public ActionResult CreateGame(string gameTitle)
        {
            gameTitle = Transcode(gameTitle);
            manager.CreateGame(gameTitle);

            return Json(new
                            {
                                Title = gameTitle
                            });
        }

        public ActionResult JoinGame(string gameTitle)
        {
            gameTitle = Transcode(gameTitle);
            Game game = manager.GetGame(gameTitle);
            game.JoinGame(userNick);

            return Json(new object
                            {
                                game.PlayerCount;
                            });
        }

        public ActionResult ExitGame(string id)
        {
           
        }

       
        public ActionResult MakeMove(string id, int x, int y)
        {
        }

        public ActionResult WaitMove(string id)
        {
        }

        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            return View();
        }
    }
}
