using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

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

        public PlayerConfigurationControl White
        {
            get { return playerConfigurationControl1; }
        }

        public PlayerConfigurationControl Black
        {
            get { return playerConfigurationControl2; }
        }
    }
}