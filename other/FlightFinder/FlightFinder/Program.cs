using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using Db4objects.Db4o;
using Db4objects.Db4o.Linq;
using OpenQA.Selenium;
using OpenQA.Selenium.Firefox;
using OpenQA.Selenium.Remote;
using OpenQA.Selenium.Support.UI;
using QuickGraph;
using QuickGraph.Algorithms;

namespace FlightFinder
{
    class Search
    {
        private readonly RemoteWebDriver driver;
        private readonly IWebElement accept;
        private readonly IWebElement search;

        public Search(RemoteWebDriver driver)
        {
            this.driver = driver;
            accept = driver.FindElement(By.CssSelector("#termsAccept"));
            search = driver.FindElement(By.CssSelector(".bookFlightButton"));
        }

        public void Submit()
        {
            accept.Click();
            driver.ExecuteScript("window.confirm = function(text) { return  true; }");
            search.Click();
            driver.ExecuteScript("window.confirm = null");
        }
    }

    class Picker
    {
        private readonly IWebElement openAirports;
        private readonly IWebElement airports;
        private readonly IWebElement closeAirports;
        private readonly IWebElement openCalendar;
        private readonly IWebElement calendar;

        public Picker(IWebElement openAirports, IWebElement airports, IWebElement closeAirports, IWebElement openCalendar, IWebElement calendar)
        {
            this.openAirports = openAirports;
            this.airports = airports;
            this.closeAirports = closeAirports;
            this.openCalendar = openCalendar;
            this.calendar = calendar;
        }

        public IEnumerable<string> GetAirportCodes()
        {
            openAirports.Click();
            openAirports.Click();

            foreach (var airport in airports.FindElements(By.CssSelector("a.outRoute")))
                yield return airport.GetAttribute("title");

            closeAirports.Click();
        }

        public void PickAirportByCode(string code)
        {
            openAirports.Click();
            openAirports.Click();
            airports.FindElement(By.XPath(string.Format(".//a[@title='{0}']", code))).Click();
        }

        public void PickWhen(DateTime when)
        {
            openCalendar.Click();
            new SelectElement(calendar.FindElement(By.CssSelector(".ui-datepicker-year"))).SelectByValue(when.Year.ToString());
            new SelectElement(calendar.FindElement(By.CssSelector(".ui-datepicker-month"))).SelectByValue((when.Month - 1).ToString());
            var group = calendar.FindElement(By.CssSelector(".ui-datepicker-group-first"));
            group.FindElement(By.XPath(string.Format(".//a[text()='{0}']", when.Day))).Click();
        }
    }

    class FromPicker : Picker
    {
        public FromPicker(RemoteWebDriver driver)
            : base(
            driver.FindElement(By.CssSelector("#fromDD")),
            driver.FindElement(By.CssSelector("#fromRoutes")),
            driver.FindElement(By.CssSelector("#fromRoutes .closePopup")),
            driver.FindElement(By.CssSelector("#departureInput")),
            driver.FindElement(By.CssSelector("#ui-datepicker-div")))
        {
        }
    }

    class ToPicker : Picker
    {
        public ToPicker(RemoteWebDriver driver)
            : base(
            driver.FindElement(By.CssSelector("#toDD")),
            driver.FindElement(By.CssSelector("#toRoutes")),
            driver.FindElement(By.CssSelector("#body_bookingFormTab1")),
            driver.FindElement(By.CssSelector("#arrivalInput")),
            driver.FindElement(By.CssSelector("#ui-datepicker-div")))
        {
        }
    }

    class Planner
    {
        private readonly Func<IWebElement> table;
        private readonly Func<IWebElement> next;

        public Planner(Func<IWebElement> table, Func<IWebElement> next)
        {
            this.table = table;
            this.next = next;
        }

        public IEnumerable<FlightTag> GetInfos()
        {
            foreach (var cell in table().FindElements(By.XPath(".//th[count(.//b)=2]")))
            {
                var cellParts = cell.Text.Split(new[] { "\r\n" }, StringSplitOptions.None);
                var whenParts = cellParts[0].Split(new[] { ',', ' ' }, StringSplitOptions.RemoveEmptyEntries);
                var when = whenParts[0] + ", " + whenParts[2] + " " + whenParts[1] + ", 20" + whenParts[3];
                var priceParts = cellParts[2].Split(new[] { " " }, StringSplitOptions.None);
                yield return new FlightTag(DateTime.Parse(when), double.Parse(priceParts[0]) * GetCurrencyRatio(priceParts[1]));
            }

        }

        private static double GetCurrencyRatio(string currency)
        {
            switch (currency)
            {
                case "PLN":
                    return 1.0;
                case "EUR":
                    return 3.9;
                case "GBP":
                    return 4.4;
                case "NOK":
                    return 0.5;
            }

            throw new NotSupportedException(currency);
        }

        public void ShowNextWeek()
        {
            next().Click();
        }
    }

    class FromPlanner : Planner
    {
        public FromPlanner(RemoteWebDriver driver)
            : base(
            () => driver.FindElement(By.CssSelector("#ttable1")),
            () => driver.FindElement(By.CssSelector("#AvailabilityInputFRSelectView_LinkButtonNextWeek1")))
        {
        }

        public static bool Exists(RemoteWebDriver driver)
        {
            return driver.FindElements(By.CssSelector("#ttable1")).Any();
        }
    }

    class ToPlanner : Planner
    {
        public ToPlanner(RemoteWebDriver driver)
            : base(
            () => driver.FindElement(By.CssSelector("#ttable2")),
            () => driver.FindElement(By.CssSelector("#AvailabilityInputFRSelectView_LinkButtonNextWeek2")))
        {
        }

        public static bool Exists(RemoteWebDriver driver)
        {
            return driver.FindElements(By.CssSelector("#ttable2")).Any();
        }
    }

    class Route : Edge<string>
    {
        public Route(string source, string target)
            : base(source, target)
        {
        }
    }

    class FlightTag
    {
        private readonly DateTime when;
        private readonly double price;

        public FlightTag(DateTime when, double price)
        {
            this.when = when;
            this.price = price;
        }

        public DateTime When
        {
            get { return when; }
        }

        public double Price
        {
            get { return price; }
        }

        public override string ToString()
        {
            return string.Format("{0}, {1}", when, price);
        }
    }

    class Flight : TaggedEdge<string, FlightTag>
    {
        public Flight(string source, string target, FlightTag tag)
            : base(source, target, tag)
        {
        }

        public Flight(string source, string target, DateTime when, double price)
            : base(source, target, new FlightTag(when, price))
        {
        }

        public override string ToString()
        {
            return string.Format("{0} ({1})", base.ToString(), Tag);
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
                        LoadRoutes(cache, driver);

                    cache.Commit();
                }

                var localAirports = new[] { "POZ", "WRO", "BZG" };
                var extraAirports = new[] { "NRN", "RYG" };
                var airports = localAirports.Concat(extraAirports);
                var from = "_FROM";
                var to = "_TO";
                var when = new DateTime(2011, 06, 2);
                var weeks = 4;

                var allRoutes = cache.AsQueryable<Route>().ToArray();
                var fromRoutes = allRoutes.Where(route => airports.Contains(route.Source)).ToArray();
                var toRoutes = allRoutes.Where(route => airports.Contains(route.Target)).ToArray();

                //using (var driver = new FirefoxDriver())
                //{
                //    foreach (var routes in new[] { fromRoutes, toRoutes })
                //        foreach (var route in routes)
                //        {
                //            if (IsIgnoredRoute(route))
                //                continue;

                //            var flights = cache.AsQueryable<Flight>()
                //                .Where(flight => flight.Source == route.Source && flight.Target == route.Target);

                //            if (!flights.Any())
                //            {
                //                LoadFlights(cache, route, driver, when, weeks);
                //                cache.Commit();
                //            }
                //        }
                //}

                var allFlights = cache.AsQueryable<Flight>().ToArray();
                var fromFlights = allFlights.Where(flight => fromRoutes.Any(route => flight.Source == route.Source && flight.Target == route.Target));
                var toFlights = allFlights.Where(flight => toRoutes.Any(route => flight.Source == route.Source && flight.Target == route.Target));

                foreach (var g in allFlights
                    .GroupBy(f => f.Source + "-" + f.Target, f => f.Tag.Price)
                    .OrderByDescending(g => g.Min()/g.Count()))
                {
                    
                    Console.WriteLine(g.Key + " - " + g.Min() + " - " + g.Count());
                }

                var graph = new BidirectionalGraph<string, Edge<string>>();
                graph.AddVerticesAndEdgeRange(fromFlights);
                graph.AddVerticesAndEdgeRange(toFlights);
                graph.AddVerticesAndEdgeRange(allRoutes.Where(route => !fromRoutes.Contains(route) && !toRoutes.Contains(route)));
                graph.AddVerticesAndEdgeRange(localAirports.Select(airport => new Flight(from, airport, DateTime.MinValue, 0)));
                graph.AddVerticesAndEdgeRange(localAirports.Select(airport => new Flight(airport, to, DateTime.MaxValue, 0)));

                FindRoutes(graph, from, to);
            }
        }

        private static void FindRoutes(BidirectionalGraph<string, Edge<string>> graph, string from, string to)
        {
            var paths = graph
                .RankedShortestPathHoffmanPavley(GetEdgeWeight, from, to, 500)
                .Where(IsValidPath)
                .OrderByDescending(GetPathDuration);

            foreach (var path in paths)
                Console.WriteLine(string.Join(", ", path));
        }

        private static TimeSpan GetPathDuration(IEnumerable<Edge<string>> path)
        {
            var flights = path.OfType<Flight>()
                .Where(flight => flight.Tag.When > DateTime.MinValue)
                .Where(flight => flight.Tag.When < DateTime.MaxValue)
                .ToArray();

            if (!flights.Any())
                return TimeSpan.Zero;

            return flights.Last().Tag.When - flights.First().Tag.When;
        }

        private static double GetEdgeWeight(Edge<string> edge)
        {
            return edge is Flight ? (edge as Flight).Tag.Price : 100000;
        }

        private static bool IsIgnoredRoute(Route route)
        {
            if (route.Source == "WRO" && route.Target == "CIA")
                return true;

            if (route.Source == "CIA" && route.Target == "WRO")
                return true;

            if (route.Source == "AOC" || route.Target == "AOC")
                return true;

            if (route.Source == "TSF" || route.Target == "TSF")
                return true;

            if (route.Source == "VCE" || route.Target == "VCE")
                return true;

            return false;
        }

        private static bool IsValidPath(IEnumerable<Edge<string>> path)
        {
            var now = DateTime.MinValue;

            foreach (var edge in path)
            {
                if (edge is Flight)
                {
                    var flight = (edge as Flight);

                    if (now > flight.Tag.When)
                        return false;

                    now = flight.Tag.When;
                }
            }

            return true;
        }

        private static void LoadFlights(IEmbeddedObjectContainer cache, Route route, FirefoxDriver driver, DateTime when, int weeks)
        {
            var fromFlights = cache.AsQueryable<Flight>()
                .Where(flight => flight.Source == route.Source && flight.Target == route.Target);

            foreach (var flight in fromFlights)
                cache.Delete(flight);

            var toFlights = cache.AsQueryable<Flight>()
                .Where(flight => flight.Source == route.Target && flight.Target == route.Source);

            foreach (var flight in toFlights)
                cache.Delete(flight);

            driver.Url = "http://www.ryanair.com/en";
            driver.ExecuteScript("window.moveTo(0, 0); window.resizeTo(1280, 1024);");
            var fromPicker = new FromPicker(driver);
            var toPicker = new ToPicker(driver);
            var search = new Search(driver);

            fromPicker.PickAirportByCode(route.Source);
            toPicker.PickAirportByCode(route.Target);
            fromPicker.PickWhen(when);
            toPicker.PickWhen(when);
            search.Submit();

            var fromPlanner = new FromPlanner(driver);
            var toPlanner = new ToPlanner(driver);

            foreach (var week in Enumerable.Range(1, weeks))
            {
                if (FromPlanner.Exists(driver))
                    foreach (var info in fromPlanner.GetInfos())
                    {
                        var flight = new Flight(route.Source, route.Target, info);
                        Console.WriteLine(flight);
                        cache.Store(flight);
                    }

                if (ToPlanner.Exists(driver))
                    foreach (var info in toPlanner.GetInfos())
                    {
                        var flight = new Flight(route.Target, route.Source, info);
                        Console.WriteLine(flight);
                        cache.Store(flight);
                    }

                if (week < weeks && FromPlanner.Exists(driver) && ToPlanner.Exists(driver))
                {
                    toPlanner.ShowNextWeek();
                    fromPlanner.ShowNextWeek();
                }
            }
        }

        private static void LoadRoutes(IEmbeddedObjectContainer cache, FirefoxDriver driver)
        {
            foreach (var route in cache.AsQueryable<Route>())
                cache.Delete(route);

            driver.Url = "http://www.ryanair.com/en";
            driver.ExecuteScript("window.moveTo(0, 0); window.resizeTo(1280, 1024);");
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
}
