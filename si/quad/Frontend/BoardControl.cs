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
        public BoardControl()
        {
            InitializeComponent();
        }

        private int dimension;

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

        public void Update(Board board)
        {
            for (int column = 0; column < dimension; column++)
                for (int row = 0; row < dimension; row++)
                    switch (board[column, row])
                    {
                        case Player.None:
                            dataGridView1.Rows[row].Cells[column].Value = "";
                            break;

                        case Player.White:
                            dataGridView1.Rows[row].Cells[column].Value = "O";
                            break;

                        case Player.Black:
                            dataGridView1.Rows[row].Cells[column].Value = "X";
                            break;
                    }
        }
    }
}
