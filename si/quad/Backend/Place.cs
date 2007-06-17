using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Place
    {
        private int column;
        private int row;

        public Place(int column, int row)
        {
            this.column = column;
            this.row = row;
        }

        public int Column
        {
            get { return column; }
        }

        public int Row
        {
            get { return row; }
        }

        public override bool Equals(object other)
        {
            Place place = other as Place;

            if (place == null)
                return base.Equals(other);

            return row == place.Row && column == place.Column;
        }

        public override string ToString()
        {
            return String.Format("{0}{1}",
                Helper.ColumnToString(column),
                Helper.RowToString(row));
        }

        public static Place operator +(Place place1, Place place2)
        {
            return new Place(
                place1.Column + place2.Column,
                place1.Row + place2.Row
            );
        }
    }
}
