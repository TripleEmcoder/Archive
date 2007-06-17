using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

using Quad.Backend;

namespace Quad.Frontend
{
    public partial class BoardControl : UserControl
    {
        private int dimension;
        private Move highlight;

        public BoardControl()
        {
            InitializeComponent();
        }

        public int Dimension
        {
            get { return dimension; }
            set
            {
                dataGridView1.ColumnCount = value;
                for (int column = dimension; column < value; column++)
                {
                    dataGridView1.Columns[column].HeaderCell.Value = Helper.ColumnToString(column);
                    dataGridView1.Columns[column].Width = 20;
                }

                dataGridView1.RowCount = value;
                for (int row = dimension; row < value; row++)
                {
                    dataGridView1.Rows[row].HeaderCell.Value = Helper.RowToString(row);
                    dataGridView1.Rows[row].Height = 20;
                }

                dimension = value;
            }
        }

        private DataGridViewCell GetCell(Place place)
        {
            return dataGridView1.Rows[place.Row].Cells[place.Column];
        }

        public void Update(Board board)
        {
            foreach (Place place in Helper.GetAllPlaces(dimension))
            {
                DataGridViewCell cell = GetCell(place);

                switch (board.GetPlayer(place))
                {
                    case Player.None:
                        cell.Value = " ";
                        break;

                    case Player.White:
                        cell.Value = "W";
                        break;

                    case Player.Black:
                        cell.Value = "B";
                        break;
                }
            }
        }

        public Move Highlight
        {
            get { return highlight; }
            set
            {
                if (highlight != null)
                {
                    if (highlight.Source != null)
                        GetCell(highlight.Source).Style.BackColor = Color.White;

                    if (highlight.Destination != null)
                        GetCell(highlight.Destination).Style.BackColor = Color.White;
                }

                highlight = value;

                if (highlight != null)
                {
                    if (highlight.Source != null)
                        GetCell(highlight.Source).Style.BackColor = Color.LightPink;

                    if (highlight.Destination != null)
                        GetCell(highlight.Destination).Style.BackColor = Color.LightGreen;
                }
            }
        }
    }
}
