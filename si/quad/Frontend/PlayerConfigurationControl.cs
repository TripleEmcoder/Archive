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
    public partial class PlayerConfigurationControl : UserControl
    {
        public PlayerConfigurationControl()
        {
            InitializeComponent();
        }

        public Player Player
        {
            get { return BackendHelper.StringToPlayer(label1.Text); }
            set { label1.Text = BackendHelper.PlayerToString(value); }
        }

        public PlayerType PlayerType
        {
            get { return playerTypeSelectionControl1.PlayerType; }
            set { playerTypeSelectionControl1.PlayerType = value; }
        }

        public Evaluator Evaluator
        {
            get { return evaluatorSelectionControl1.Evaluator; }
        }

        public Algorithm Algorithm
        {
            get { return algorithmSelectionControl1.Algorithm; }
        }

        private void playerTypeSelectionControl1_PlayerTypeChanged(object sender, EventArgs e)
        {
            evaluatorSelectionControl1.Enabled = PlayerType == PlayerType.Computer;
            algorithmSelectionControl1.Enabled = PlayerType == PlayerType.Computer;
        }
    }
}
