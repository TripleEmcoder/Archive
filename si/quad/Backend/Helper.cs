using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public static class Helper
    {
        private static Dictionary<Direction, Place> vectors;

        static Helper()
        {
            vectors = new Dictionary<Direction, Place>();
            vectors[Direction.North] = new Place(0, 1);
            vectors[Direction.South] = new Place(0, -1);
            vectors[Direction.East] = new Place(1, 0);
            vectors[Direction.West] = new Place(-1, 0);
        }

        public static Dictionary<Direction, Place> Vectors
        {
            get { return vectors; }
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
            List<Place> places = new List<Place>();

            for (int column = 0; column < dimension; column++)
                for (int row = 0; row < dimension; row++)
                    places.Add(new Place(column, row));

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
    }
}
