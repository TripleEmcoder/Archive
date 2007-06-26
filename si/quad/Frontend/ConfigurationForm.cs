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
    public partial class ConfigurationForm : Form
    {
        public ConfigurationForm()
        {
            InitializeComponent();
        }

        public int Dimension
        {
            get { return int.Parse(textBox1.Text); }
        }

        public int Count
        {
            get { return int.Parse(textBox2.Text); }
        }

        public PlayerConfigurationControl GetPlayer(Player player)
        {
            switch (player)
            {
                case Player.White:
                    return playerConfigurationControl1;

                case Player.Black:
                    return playerConfigurationControl2;

                default:
                    return null;
            }
        }
   }
}