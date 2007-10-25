using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using System.IO;

namespace Projekt2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Framstick framstick;

        private void button1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
                using (Stream stream = openFileDialog1.OpenFile())
                using (StreamReader reader = new StreamReader(stream))
                {
                    framstick = new Framstick();
                    framstick.Load(reader);
                    Invalidate();
                }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            if (framstick != null)
                framstick.Paint(e.Graphics);
        }
    }
}