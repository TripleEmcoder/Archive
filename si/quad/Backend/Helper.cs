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

        public static List<Point> GetAllPoints(int dimension)
        {
            List<Point> points = new List<Point>();

            for (int column = 0; column < dimension; column++)
                for (int row = 0; row < dimension; row++)
                    points.Add(new Point(column, row));

            return points;
        }

        public static bool IsPointValid(Point point, int dimension)
        {
            if (point.Column < 0)
                return false;

            if (point.Row < 0)
                return false;

            if (point.Column >= dimension)
                return false;

            if (point.Row >= dimension)
                return false;

            return true;
        }
    }
}
