using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Point
    {
        private int column;
        private int row;

        public Point(int column, int row)
        {
            this.column = column;
            this.row = row;
        }

        public int Column
        {
            get { return column; }
            set { column = value; }
        }

        public int Row
        {
            get { return row; }
            set { row = value; }
        }

        public override string ToString()
        {
            return String.Format("{0}{1}",
                Helper.ColumnToString(column),
                Helper.RowToString(row));
        }

        public static Point operator +(Point point1, Point point2)
        {
            return new Point(
                point1.Column + point2.Column,
                point1.Row + point2.Row
            );
        }
    }
}
