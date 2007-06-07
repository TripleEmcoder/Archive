using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Quad.Backend;

namespace Quad.Frontend
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private Board board;

        private void button1_Click(object sender, EventArgs e)
        {
            board = new Board(4, 4);
            button2_Click(button2, EventArgs.Empty);
            boardControl1.Update(board);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            foreach (Move move in board.GetPossibleMoves(Player.White))
                listBox1.Items.Add(move);
        }

        private void listBox1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            board.PerformMove(Player.White, (Move)listBox1.SelectedItem);
            button2_Click(button2, EventArgs.Empty);
            boardControl1.Update(board);
        }
    }
}