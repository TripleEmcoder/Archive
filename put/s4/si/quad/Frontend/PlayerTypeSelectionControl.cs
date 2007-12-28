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
    public partial class PlayerTypeSelectionControl : UserControl
    {
        private PlayerType type;

        public PlayerTypeSelectionControl()
        {
            InitializeComponent();
        }

        public PlayerType PlayerType
        {
            get { return type; }

            set
            {
                humanRadioButton.Checked = value == PlayerType.Human;
                computerRadioButton.Checked = value == PlayerType.Computer;
                type = value;
            }
        }

        public event EventHandler<EventArgs> PlayerTypeChanged;

        private void humanRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (humanRadioButton.Checked)
            {
                type = PlayerType.Human;

                if (PlayerTypeChanged != null)
                    PlayerTypeChanged(this, EventArgs.Empty);
            }
        }

        private void computerRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (computerRadioButton.Checked)
            {
                type = PlayerType.Computer;
                
                if (PlayerTypeChanged != null)
                    PlayerTypeChanged(this, EventArgs.Empty);
            }
        }
    }
}
