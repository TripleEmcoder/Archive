using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Projekt3
{
    public partial class Form1 : Form
    {
        double max = 1;
        double step = 0.001;

        public Form1()
        {
            InitializeComponent();

            pictureBox1.Image = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics graphics = Graphics.FromImage(pictureBox1.Image);

            for (int i = 0; i <= pictureBox1.Width; i++)
            {
                Pen pen = new Pen(GetColor(i * max / pictureBox1.Width));
                graphics.DrawLine(pen, i, 0, i, pictureBox1.Height);
            }
        }

        private Color GetColor(double h)
        {
            //int s = i / 256;
            //int j = i % 256;

            //switch (s)
            //{
            //    case 0:
            //        return Color.FromArgb(255, j, 0);

            //    case 1:
            //        return Color.FromArgb(255 - j, 255, 0);

            //    case 2:
            //        return Color.FromArgb(0, 255, j);

            //    case 3:
            //        return Color.FromArgb(0, 255 - j, 255);

            //    default:
            //        return Color.Black;
            //}

            return ColorHandler.HSVtoColor(h, 1, 1);
        }

        private char RandomLetter()
        {
            Random random = new Random();
            return (char)('A' + random.Next(0, 'Z' - 'A'));
        }

        double back;
        double front;

        private void UpdateControls()
        {
            BackColor = GetColor(back);
            label1.ForeColor = GetColor(front);
            progressBar1.Maximum = (int)Math.Round(max * progressBar1.Width);
            progressBar1.Value = (int)Math.Round(back * progressBar1.Width);
            toolStripLabel1.Text = timer1.Enabled.ToString();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            back = front = 0;

            timer1.Enabled = true;
            label1.Text = "" + RandomLetter();

            UpdateControls();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            front += step;

            if (front > max)
                timer1.Enabled = false;

            UpdateControls();
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            timer1.Enabled = false;

            if (e.KeyChar == label1.Text.ToLower()[0])
            {
                listBox1.Items.Add(new KeyValuePair<double, double>(back, front - back));
                back = front;


                label1.Text = "" + RandomLetter();
                timer1.Enabled = true;

                UpdateControls();
            }
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            UpdateControls();
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            StringBuilder builder = new StringBuilder();

            foreach (KeyValuePair<double, double> var in listBox1.Items)
                builder.AppendLine(var.Key + ";" + var.Value);

            Clipboard.SetText(builder.ToString());
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            ((Bitmap)pictureBox1.Image).Save("E:\\temp.png");
        }
    }
}