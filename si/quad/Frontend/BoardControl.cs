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
                    dataGridView1.Columns[column].HeaderCell.Value = BackendHelper.ColumnToString(column);
                    dataGridView1.Columns[column].Width = 20;
                }

                dataGridView1.RowCount = value;
                for (int row = dimension; row < value; row++)
                {
                    dataGridView1.Rows[row].HeaderCell.Value = BackendHelper.RowToString(row);
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
            foreach (Place place in BackendHelper.GetAllPlaces(dimension))
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

        private void SetBackColor(DataGridViewCell cell, Color color)
        {
            cell.Style.BackColor = color;
            cell.Style.SelectionBackColor = color;
        }

        public Move Highlight
        {
            get { return highlight; }
            set
            {
                if (highlight != null)
                {
                    if (highlight.Source != null)
                        SetBackColor(GetCell(highlight.Source), Color.White);

                    if (highlight.Destination != null)
                        SetBackColor(GetCell(highlight.Destination), Color.White);
                }

                highlight = value;

                if (highlight != null)
                {
                    if (highlight.Source != null)
                        SetBackColor(GetCell(highlight.Source), Color.LightPink);

                    if (highlight.Destination != null)
                        SetBackColor(GetCell(highlight.Destination), Color.LightGreen);
                }
            }
        }
        
        public event EventHandler<PlaceEventArgs> PlaceClick;

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (PlaceClick != null)
                PlaceClick(this, new PlaceEventArgs(new Place(e.ColumnIndex, e.RowIndex)));
        }
    }
}
