using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public static class Helper
    {  
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
    }
}
