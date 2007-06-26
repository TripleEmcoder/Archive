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
        public MainForm()
        {
            InitializeComponent();
        }

        private Board board;
        private Player player;
        private Evaluator evaluator;
        private Algorithm algorithm;

        private void RestartGame()
        {
            board = new Board(4, 4);
            player = Player.White;
            evaluator = new LineEvaluator();
            algorithm = new NegMaxAlgorithm();

            UpdateMoves();

            transistionListBox.Items.Clear();
        }

        private void UpdateControls()
        {
            boardControl.Update(board);
            moveListBox_SelectedIndexChanged(null, EventArgs.Empty);
            backButton.Enabled = transistionListBox.Items.Count > 0;
            label4.Text = evaluator.Run(board, Player.White).ToString();
            label5.Text = evaluator.Run(board, Player.Black).ToString();
            label6.Text = algorithm.Run(evaluator, board, player, 3).ToString();
        }

        private void UpdateMoves()
        {
            player = BackendHelper.SwapPlayer(player);
            label1.Text = player.ToString();

            moveListBox.Items.Clear();

            foreach (Move move in board.GetPossibleMoves(player))
                moveListBox.Items.Add(move);

            UpdateControls();
        }

        private void PerformMove(Move move)
        {
            transistionListBox.Items.Add(board.PerformMove(move));

            UpdateMoves();
        }

        private void newButton_Click(object sender, EventArgs e)
        {
            ConfigurationForm configuration = new ConfigurationForm();
            
            if (configuration.ShowDialog() == DialogResult.OK)
                RestartGame();
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
    }
}