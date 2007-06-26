using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Quad.Backend;
using System.Threading;
using System.Diagnostics;

namespace Quad.Frontend
{
    public partial class MainForm : Form
    {
        private ConfigurationForm configuration;

        public MainForm()
        {
            InitializeComponent();
        
            configuration = new ConfigurationForm();
        }

        private Board board;
        private Player player;

        private void RestartGame()
        {
            board = new Board(configuration.Dimension, configuration.Count);
            player = Player.White;

            UpdateMoves();

            transistionListBox.Items.Clear();
            boardControl.Dimension = configuration.Dimension;
        }

        private void UpdateControls()
        {
            boardControl.Update(board);
            moveListBox_SelectedIndexChanged(null, EventArgs.Empty);

            PlayerConfigurationControl current = configuration.GetPlayer(player);
            bool human = current.PlayerType == PlayerType.Human;

            boardControl.Enabled = human;
            moveListBox.Enabled = human;
            transistionListBox.Enabled = human;
            backButton.Enabled = human && transistionListBox.Items.Count > 0;
        }

        private void UpdateMoves()
        {
            player = BackendHelper.SwapPlayer(player);
            label1.Text = BackendHelper.PlayerToString(player);

            foreach (Move move in board.GetPossibleMoves(player))
                moveListBox.Items.Add(move);

            UpdateControls();
        }

        private void PerformMove(Move move)
        {
            transistionListBox.Items.Add(board.PerformMove(move));
            moveListBox.Items.Clear();

            if (board.Winner == player)
            {
                boardControl.Enabled = false;
                moveListBox.Enabled = false;
                transistionListBox.Enabled = false;
                backButton.Enabled = false;
                timer1.Enabled = false;

                UpdateControls();

                MessageBox.Show("Wygra³ " + BackendHelper.PlayerToString(player));
            }
            else
            {
                UpdateMoves();
            }
        }

        private void newButton_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;

            if (configuration.ShowDialog() == DialogResult.OK)
                RestartGame();

            timer1.Enabled = true;
        }

        private void moveListBox_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            PerformMove((Move)moveListBox.SelectedItem);
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

            UpdateMoves();
        }

        private void boardControl_PlaceClick(object sender, PlaceEventArgs e)
        {
            foreach (object item in moveListBox.Items)
            {
                Move move = (Move)item;

                if (boardControl.Highlight == null && move.Source == null && move.Destination.Equals(e.Place))
                {
                    Debug.WriteLine(String.Format("{0} is a possible drop.", e.Place));
                    boardControl.Highlight = move;
                    PerformMove(move);
                    break;
                }

                //if (boardControl.Highlight == null && move.Source != null && move.Source.Equals(e.Place))
                if (move.Source != null && move.Source.Equals(e.Place))
                {
                    Debug.WriteLine(String.Format("{0} starts a possible move.", e.Place));
                    boardControl.Highlight = new Move(player, e.Place, null);
                    break;
                }

                if (boardControl.Highlight != null && boardControl.Highlight.Source.Equals(move.Source) 
                    && move.Destination != null && move.Destination.Equals(e.Place))
                {
                    Debug.WriteLine(String.Format("{0} ends a possible move.", e.Place));
                    boardControl.Highlight = null;
                    PerformMove(move);
                    break;
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            PlayerConfigurationControl current = configuration.GetPlayer(player);

            if (current.PlayerType == PlayerType.Computer)
                PerformMove(current.Algorithm.Run(current.Evaluator, board, player, 2).Move);
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}