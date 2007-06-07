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
        private Player player;

        private void button1_Click(object sender, EventArgs e)
        {
            board = new Board(4, 4);
            player = Player.White;

            button2_Click(null, EventArgs.Empty);
            boardControl1.Update(board);
        }

        private void button2_Click(object sender, EventArgs e)
        {

            switch (player)
            {
                case Player.White:
                    player = Player.Black;
                    break;

                case Player.Black:
                    player = Player.White;
                    break;
            }

            label1.Text = player.ToString();

            listBox1.Items.Clear();

            foreach (Move move in board.GetPossibleMoves(player))
                listBox1.Items.Add(move);
        }

        private void listBox1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            board.PerformMove(player, (Move)listBox1.SelectedItem);
            button2_Click(null, EventArgs.Empty);
            boardControl1.Update(board);
        }
    }
}