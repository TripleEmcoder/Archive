using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public static class BackendHelper
    {
        private static Dictionary<int, List<Place>> places;
        private static Dictionary<Direction, Place> vectors;
        public static List<Evaluator> evaluators;
        public static List<Algorithm> algorithms;

        static BackendHelper()
        {
            places = new Dictionary<int, List<Place>>();

            vectors = new Dictionary<Direction, Place>();
            vectors[Direction.North] = new Place(0, 1);
            vectors[Direction.South] = new Place(0, -1);
            vectors[Direction.East] = new Place(1, 0);
            vectors[Direction.West] = new Place(-1, 0);

            algorithms = new List<Algorithm>();
            algorithms.Add(new NegaScoutAlgorithm());
            algorithms.Add(new AlfaBetaAlgorithm());
            algorithms.Add(new AlfaBetaFSAlgorithm());
            algorithms.Add(new AlfaBetaFSTTAlgorithm());
            algorithms.Add(new NegMaxAlgorithm());            

            evaluators = new List<Evaluator>();
            evaluators.Add(new TestEvaluatorDef());
            evaluators.Add(new TestEvaluator());
            //evaluators.Add(new LineEvaluator());
        }

        public static Dictionary<Direction, Place> Vectors
        {
            get { return vectors; }
        }

        public static List<Algorithm> Algorithms
        {
            get { return algorithms; }
        }

        public static List<Evaluator> Evaluators
        {
            get { return evaluators; }
        }

        public static string ColumnToString(int column)
        {
            return ((char)('A' + column)).ToString();
        }

        public static string RowToString(int row)
        {
            return (row+1).ToString();
        }

        public static List<Place> GetAllPlaces(int dimension)
        {
            if (!places.ContainsKey(dimension))
            {
                List<Place> result = new List<Place>();

                for (int column = 0; column < dimension; column++)
                    for (int row = 0; row < dimension; row++)
                        result.Add(new Place(column, row));

                places[dimension] = result;
            }

            return places[dimension];
        }

        public static int DistanceToCenter(Place place, int dimension)
        {
            float center = (float)(dimension - 1) / 2.0f;
            return (int)Math.Floor(Math.Max(Math.Abs(place.Column - center), Math.Abs(place.Row - center)));
        }

        public class PlaceCenterComparer: IComparer<Place>
        {
            int dimension;

            public PlaceCenterComparer(int dimension)
            {
                this.dimension = dimension;
            }

            #region IComparer<Place> Members

            public int Compare(Place x, Place y)
            {
                return DistanceToCenter(x, dimension) - DistanceToCenter(y, dimension);
            }

            #endregion
        }

        public class MoveDestinationCenterComparer: IComparer<Move>
        {
            PlaceCenterComparer comp;
            
            public MoveDestinationCenterComparer(int dimension)
            {
                this.comp = new PlaceCenterComparer(dimension);
            }

            #region IComparer<Move> Members

            public int Compare(Move x, Move y)
            {
                return comp.Compare(x.Destination, y.Destination);
            }

            #endregion
        }
        
        public static List<Place> GetAllPlacesSorted(int dimension)
        {
            List<Place> places = GetAllPlaces(dimension);

            places.Sort(new PlaceCenterComparer(dimension));

            return places;
        }

        public static bool IsPlaceValid(Place place, int dimension)
        {
            if (place.Column < 0)
                return false;

            if (place.Row < 0)
                return false;

            if (place.Column >= dimension)
                return false;

            if (place.Row >= dimension)
                return false;

            return true;
        }

        public static Player SwapPlayer(Player player)
        {
            switch (player)
            {
                case Player.White:
                    return Player.Black;

                case Player.Black:
                    return Player.White;

                default:
                    throw new ArgumentException();
            }
        }

        public static string PlayerToString(Player player)
        {
            switch (player)
            {
                case Player.White:
                    return "Bia造";

                case Player.Black:
                    return "Czarny";

                default:
                    return "Brak";
            }
        }

        public static Player StringToPlayer(string player)
        {
            switch (player)
            {
                case "Bia造":
                    return Player.White;

                case "Czarny":
                    return Player.Black;

                default:
                    return Player.None;
            }
        }

        public static string PlayerTypeToString(PlayerType type)
        {
            switch (type)
            {
                case PlayerType.Human:
                    return "Cz這wiek";

                case PlayerType.Computer:
                    return "Komputer";

                default:
                    return "Brak";
            }
        }

        public static PlayerType StringToPlayerType(string type)
        {
            switch (type)
            {
                case "Cz這wiek":
                    return PlayerType.Human;

                case "Komputer":
                    return PlayerType.Computer;

                default:
                    return PlayerType.None;
            }
        }
    }
}
