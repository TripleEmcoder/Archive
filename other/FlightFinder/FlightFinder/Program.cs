using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using Db4objects.Db4o;
using Db4objects.Db4o.Linq;
using OpenQA.Selenium;
using OpenQA.Selenium.Firefox;
using OpenQA.Selenium.Remote;
using QuickGraph;
using QuickGraph.Algorithms;

namespace FlightFinder
{
    class FromPicker
    {
        private readonly IWebElement open;
        private readonly IWebElement airports;
        private readonly IWebElement close;

        public FromPicker(RemoteWebDriver driver)
        {
            open = driver.FindElement(By.CssSelector("#fromDD"));
            airports = driver.FindElement(By.CssSelector("#fromRoutes"));
            close = airports.FindElement(By.CssSelector(".closePopup"));
        }

        public IEnumerable<string> GetAirportCodes()
        {
            open.Click();

            foreach (var airport in airports.FindElements(By.CssSelector("a.outRoute")))
                yield return airport.GetAttribute("title");

            open.Click();
            close.Click();
        }

        public void PickAirportByCode(string code)
        {
            open.Click();
            airports.FindElement(By.XPath(string.Format(".//a[@title='{0}']", code))).Click();
        }
    }

    class ToPicker
    {
        private readonly IWebElement open;
        private readonly IWebElement airports;
        private readonly IWebElement close;

        public ToPicker(RemoteWebDriver driver)
        {
            open = driver.FindElement(By.CssSelector("#toDD"));
            airports = driver.FindElement(By.CssSelector("#toRoutes"));
            close = driver.FindElement(By.CssSelector("#body_bookingFormTab1"));
        }

        public IEnumerable<string> GetAirportCodes()
        {
            open.Click();

            foreach (var airport in airports.FindElements(By.CssSelector("a.outRoute")))
                yield return airport.GetAttribute("title");

            close.Click();
        }

        public void PickAirportByCode(string code)
        {
            open.Click();
            airports.FindElement(By.XPath(string.Format(".//a[@title='{0}']", code))).Click();
        }
    }

    class Route : Edge<string>
    {
        public Route(string source, string target)
            : base(source, target)
        {
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            using (var cache = Db4oEmbedded.OpenFile("cache.db4o"))
            {
                if (!cache.AsQueryable<Route>().Any())
                {
                    using (var driver = new FirefoxDriver())
                    {
                        driver.Url = "http://www.ryanair.com/en";
                        var fromPicker = new FromPicker(driver);
                        var toPicker = new ToPicker(driver);

                        foreach (var fromCode in fromPicker.GetAirportCodes().ToArray())
                        {
                            fromPicker.PickAirportByCode(fromCode);

                            foreach (var toCode in toPicker.GetAirportCodes().ToArray())
                            {
                                var route = new Route(fromCode, toCode);
                                Console.WriteLine(route);
                                cache.Store(route);
                            }
                        }
                    }
                }

                var graph = new BidirectionalGraph<string, Edge<string>>();
                var airports = new[] {"POZ", "WRO", "BZG"};
                var fromSuffix = "-FROM";
                var toSuffix = "-IN";

                var allRoutes = cache.AsQueryable<Route>().ToArray();

                var fromRoutes = allRoutes
                    .Where(route => airports.Contains(route.Source))
                    .Select(route => new Route(route.Source + fromSuffix, route.Target));

                var toRoutes = allRoutes
                    .Where(route => airports.Contains(route.Target))
                    .Select(route => new Route(route.Source, route.Target + toSuffix));

                var otherRoutes = allRoutes
                    .Where(route => !airports.Contains(route.Source))
                    .Where(route => !airports.Contains(route.Target));

                foreach (var routes in new[] { fromRoutes, toRoutes, otherRoutes })
                    graph.AddVerticesAndEdgeRange(routes);

                foreach (var fromAirport in airports)
                    foreach (var toAirport in airports)
                        foreach (var path in graph.RankedShortestPathHoffmanPavley(edge => 1, fromAirport + fromSuffix, toAirport + toSuffix, 10))
                            Console.WriteLine(string.Join(", ", path));
            }
        }
    }
}
