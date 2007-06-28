using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

using Quad.Backend;
using System.Reflection;

namespace Quad.Frontend
{
    public partial class BoardControl : UserControl
    {
        private int dimension;
        private Move highlight;
        private Algorithm alg;
        private Evaluator eval;

        public BoardControl()
        {
            InitializeComponent();
            alg = new AlfaBetaFSTTAlgorithm();
            eval = new TestEvaluatorDef(); 
        }

        public int Dimension
        {
            get { return dimension; }
            set
            {
                //dataGridView1.ColumnCount = value;
                //for (int column = dimension; column < value; column++)
                dataGridView1.ColumnCount = 0;
                for (int column = 0; column < value; column++)
                {
                    //dataGridView1.Columns.Add(new DataGridViewImageColumn());
                    dataGridView1.Columns.Add(new DataGridViewTextBoxColumn());
                    dataGridView1.Columns[column].HeaderCell.Value = BackendHelper.ColumnToString(column);
                    dataGridView1.Columns[column].Width = 40;
                }

                //dataGridView1.RowCount = value;
                //for (int row = dimension; row < value; row++)
                dataGridView1.RowCount = 0;
                for (int row = 0; row < value; row++)
                {
                    dataGridView1.Rows.Add(new DataGridViewRow());
                    dataGridView1.Rows[row].HeaderCell.Value = BackendHelper.RowToString(row);
                    dataGridView1.Rows[row].Height = 40;
                }

                dimension = value;
            }
        }

        private DataGridViewCell GetCell(Place place)
        {
            return dataGridView1.Rows[place.Row].Cells[place.Column];
        }

        public void Update(Board board, Player player)
        {
            foreach (Place place in BackendHelper.GetAllPlaces(dimension))
            {
                DataGridViewCell cell = GetCell(place);
                cell.Style.Font = new Font(dataGridView1.DefaultCellStyle.Font, FontStyle.Bold);

                switch (board.GetPlayer(place))
                {
                    //case Player.None:
                    //    cell.Value = " ";
                    //    break;

                    case Player.White:
                        cell.Value = "W";
                        break;

                    case Player.Black:
                        cell.Value = "B";
                        break;
                }

                //GetCell(place).Value = FrontendHelper.Images[board.GetPlayer(place)];
            }

            //foreach (Move move in board.GetPossibleMovesSorted(player))
            //{
            //    Transition transition = board.PerformMove(move);

            //    Result candidate = alg.Run(eval, board, BackendHelper.SwapPlayer(player), 2);

            //    DataGridViewCell cell = GetCell(move.Destination);

            //    cell.Value = -candidate.Value;
            //    cell.Style.Font = new Font(dataGridView1.DefaultCellStyle.Font, FontStyle.Regular);

            //    board.ReverseTransition(transition);
            //}
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
