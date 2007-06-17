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
            Move move = (Move)listBox1.SelectedItem;
            Transition transition = board.PerformMove(player, move);
            listBox2.Items.Add(player.ToString() + ": " + transition.ToString());
            button2_Click(null, EventArgs.Empty);
            boardControl1.Update(board);
            listBox1_SelectedIndexChanged(null, EventArgs.Empty);
            label4.Text = board.GetValue(Player.White).ToString();
            label5.Text = board.GetValue(Player.Black).ToString();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            boardControl1.Highlight = (Move)listBox1.SelectedItem;
        }
    }
}