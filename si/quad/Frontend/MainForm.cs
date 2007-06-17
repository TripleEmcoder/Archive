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
        private Algorithm algorithm;

        private void newButton_Click(object sender, EventArgs e)
        {
            board = new Board(4, 4);
            player = Player.White;
            algorithm = new NegMaxAlgorithm();

            UpdateMoves();

            transistionListBox.Items.Clear();
        }

        private void UpdateMoves()
        {
            player = Helper.SwapPlayer(player);
            label1.Text = player.ToString();

            moveListBox.Items.Clear();

            foreach (Move move in board.GetPossibleMoves(player))
                moveListBox.Items.Add(move);

            UpdateControls();
        }

        private void UpdateControls()
        {
            boardControl.Update(board);
            moveListBox_SelectedIndexChanged(null, EventArgs.Empty);
            backButton.Enabled = transistionListBox.Items.Count > 0;
            label4.Text = board.GetValue(Player.White).ToString();
            label5.Text = board.GetValue(Player.Black).ToString();
            label6.Text = algorithm.Run(player, board, 2).ToString();
        }

        private void moveListBox_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            Move move = (Move)moveListBox.SelectedItem;
            Transition transition = board.PerformMove(move);

            transistionListBox.Items.Add(transition);

            UpdateMoves();
        }

        private void moveListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            boardControl.Highlight = (Move)moveListBox.SelectedItem;
        }

        private void backButton_Click(object sender, EventArgs e)
        {
            Transition transition = (Transition)transistionListBox.Items[transistionListBox.Items.Count - 1];
            transistionListBox.Items.Remove(transition);
            board.ReverseTransition(transition);
            UpdateControls();
        }
    }
}