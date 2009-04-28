using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web.Mvc;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Frontend;
using Frontend.Controllers;

namespace Frontend.Tests.Controllers
{
    [TestClass]
    public class GameControllerTest
    {
        [TestMethod]
        public void Index()
        {
            // Arrange
            GameController controller = new GameController();

            // Act
            ViewResult result = controller.Index() as ViewResult;

            // Assert
            ViewDataDictionary viewData = result.ViewData;
            Assert.AreEqual("Welcome to ASP.NET MVC!", viewData["Message"]);
        }

        [TestMethod]
        public void About()
        {
            // Arrange
            GameController controller = new GameController();

            // Act
            ViewResult result = controller.About() as ViewResult;

            // Assert
            Assert.IsNotNull(result);
        }
    }
}
