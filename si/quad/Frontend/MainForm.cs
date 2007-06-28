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
        private RulesForm rules;

        public MainForm()
        {
            InitializeComponent();

            configuration = new ConfigurationForm();
            rules = new RulesForm();
        }

        private Board board;
        private Player player;

        private void RestartGame()
        {
            board = new Board(configuration.Dimension, configuration.Count);
            player = Player.White;

            boardControl.Dimension = configuration.Dimension;

            UpdateMoves();

            transistionListBox.Items.Clear();
        }

        private void UpdateControls()
        {
            boardControl.Update(board, player);
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
            label6.Text = board.Befores[player].ToString();

            moveListBox.Items.Clear();

            foreach (Move move in board.GetPossibleMoves(player))
                moveListBox.Items.Add(move);

            UpdateControls();
        }

        private void PerformMove(Move move)
        {
            transistionListBox.Items.Add(board.PerformMove(move));

            if (board.Winner == player)
            {
                moveListBox.Items.Clear();

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
            bool enabled = timer1.Enabled;
            timer1.Enabled = false;
            backgroundWorker1.CancelAsync();

            if (configuration.ShowDialog() == DialogResult.OK)
            {
                RestartGame();
                timer1.Enabled = true;
            }
            else
            {
                timer1.Enabled = enabled;
            }
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
            if (transistionListBox.SelectedItem == null)
            {
                MessageBox.Show("Proszê wybraæ ostatni poprawny ruch!");
                return;
            }

            for (int index = transistionListBox.Items.Count - 1; index > transistionListBox.SelectedIndex; index--)
            {
                Transition transition = (Transition)transistionListBox.Items[index];
                board.ReverseTransition(transition);
                transistionListBox.Items.RemoveAt(index);
            }

            player = ((Transition)transistionListBox.SelectedItem).Moves[0].Player;

            UpdateMoves();
        }

        private void boardControl_PlaceClick(object sender, PlaceEventArgs e)
        {
            foreach (object item in moveListBox.Items)
            {
                Move move = (Move)item;

                if (boardControl.Highlight == null && move.Source == null && move.Destination.Equals(e.Place))
                {
                    //Debug.WriteLine(String.Format("{0} is a possible drop.", e.Place));
                    boardControl.Highlight = move;
                    PerformMove(move);
                    break;
                }

                //if (boardControl.Highlight == null && move.Source != null && move.Source.Equals(e.Place))
                if (move.Source != null && move.Source.Equals(e.Place))
                {
                    //Debug.WriteLine(String.Format("{0} starts a possible move.", e.Place));
                    boardControl.Highlight = new Move(player, e.Place, null);
                    break;
                }

                if (boardControl.Highlight != null && boardControl.Highlight.Source.Equals(move.Source)
                    && move.Destination != null && move.Destination.Equals(e.Place))
                {
                    //Debug.WriteLine(String.Format("{0} ends a possible move.", e.Place));
                    boardControl.Highlight = null;
                    PerformMove(move);
                    break;
                }
            }
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void MainForm_Shown(object sender, EventArgs e)
        {
            newButton_Click(newButton, EventArgs.Empty);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            rules.Show();
            rules.Focus();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            using (AuthorsForm authors = new AuthorsForm())
                authors.ShowDialog();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            PlayerConfigurationControl current = configuration.GetPlayer(player);
            
            if (current.PlayerType == PlayerType.Computer && !backgroundWorker1.IsBusy)
                backgroundWorker1.RunWorkerAsync();
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            PlayerConfigurationControl current = configuration.GetPlayer(player);

            current.Algorithm.Hits = 0;
            Result result = current.Algorithm.Run(current.Evaluator, board, player, current.Depth);
            Debug.WriteLine(result);
            Debug.WriteLine(current.Algorithm.Hits);

            e.Result = result;
        }

        private void backgroundWorker1_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (!e.Cancelled)
                PerformMove(((Result)e.Result).Move);
        }
    }
}
