//Marcin Mikołajczak 75922
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using MPI;
using Environment = MPI.Environment;

namespace DolevSpanningTree
{
    class Program
    {
        static void Main(string[] args)
        {
            using (new Environment(ref args))
            {
                var random = new Random(int.Parse(args[0]));

                var processCount = Communicator.world.Size;
                var currentProcess = Communicator.world.Rank;

                //Console.WriteLine("Started process {0} of {1}.", currentProcess, processCount);

                var lastSend = new Dictionary<int, int>();
                Action<int, int> write = (process, distance) =>
                    {
                        if (!lastSend.ContainsKey(process) || lastSend[process] != distance)
                        {
                            lastSend[process] = distance;
                            Console.WriteLine("{0}: send({1}, {2})", currentProcess, process, distance);
                            Communicator.world.Send(distance, process, 0);
                        }
                    };

                var lastReceive = new Dictionary<int, int>();
                Func<int, int> read = process =>
                    {
                        lock (lastReceive)
                        {
                            if (!lastReceive.ContainsKey(process))
                                lastReceive[process] = random.Next();

                            return lastReceive[process];
                        }
                    };

                Action<int> start = process =>
                    {
                        Action receiver = () =>
                            {
                                while (true)
                                {
                                    var distance = Communicator.world.Receive<int>(process, 0);

                                    lock (lastReceive)
                                        if (!lastReceive.ContainsKey(process) || lastReceive[process] != distance)
                                        {
                                            lastReceive[process] = distance;
                                            Console.WriteLine("{0}: receive({1}, {2})", currentProcess, process, distance);
                                        }
                                }
                            };

                        new Thread(() => receiver()).Start();
                    };

                Func<int> randomLinkCount = () => random.Next((processCount - 1) / 2, processCount * (processCount - 1) / 4);

                #region Losowanie grafu

                Func<int> randomProcess = () => random.Next(0, processCount - 1);
                var order = Enumerable.Range(0, processCount).OrderBy(process => random.Next()).ToArray();
                var connectedLinks = order.Take(processCount - 1).Zip(order.Skip(1), (from, to) => new { From = from, To = to });
                var randomLinks = Enumerable.Range(1, randomLinkCount()).Select(i => new { From = randomProcess(), To = randomProcess() }).Where(link => link.From != link.To).ToArray();
                var allLinks = connectedLinks.Concat(randomLinks);
                var links = allLinks.Concat(allLinks.Select(link => new { From = link.To, To = link.From })).Distinct();
                var neighbors = links.Where(link => link.From == currentProcess).Select(link => link.To);

                #endregion

                var rootProcess = randomProcess();

                #region Wypisanie grafu

                if (currentProcess == rootProcess)
                    foreach (var link in links.OrderBy(link => link.From).ThenBy(link => link.To))
                        Console.WriteLine("{0}: {1} -> {2}", currentProcess, link.From, link.To);

                #endregion

                #region Wypisanie sąsiadów

                foreach (var neighbor in neighbors.OrderBy(process => process))
                    Console.WriteLine("{0}: {1}", currentProcess, neighbor);

                #endregion

                if (currentProcess == rootProcess)
                {
                    while (true)
                    {
                        foreach (var neighbor in neighbors)
                            write(neighbor, 0);

                        Thread.Sleep(500);
                    }
                }
                else
                {
                    foreach (var neighbor in neighbors)
                        start(neighbor);

                    int parentProcess = randomProcess();
                    int parentDistance = random.Next();
                    Console.WriteLine("{0}: parent = {1}, distance = {2}", currentProcess, parentProcess, parentDistance);

                    while (true)
                    {
                        var pairs = neighbors.Select(process => new { Process = process, Distance = read(process) }).ToArray();
                        var minDistance = pairs.Select(pair => pair.Distance).Min();
                        var minProcess = pairs.Where(pair => pair.Distance == minDistance).Select(pair => pair.Process).First();

                        if (parentProcess != minProcess || parentDistance != minDistance)
                        {
                            parentProcess = minProcess;
                            parentDistance = minDistance;
                            Console.WriteLine("{0}: * parent = {1}, distance = {2}", currentProcess, minProcess, minDistance);
                        }

                        foreach (var neighbor in neighbors)
                            write(neighbor, minDistance + 1);

                        Thread.Sleep(500);
                    }
                }
            }
        }
    }
}
