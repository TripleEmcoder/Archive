using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace Visualizer
{
    public partial class Form1 : Form
    {
        private Gantt gantt;
        
        public Form1()
        {
            InitializeComponent();

            gantt = new Gantt();
            resetButton.PerformClick();
        }

        private void loadButton_Click(object sender, EventArgs e)
        {
            if (inputOpenFileDialog.ShowDialog() == DialogResult.OK)
            {
                using (Stream stream = inputOpenFileDialog.OpenFile())
                    gantt.Load(stream);                
                
                refreshButton.PerformClick();
            }
        }

        private void refreshButton_Click(object sender, EventArgs e)
        {
            if (ganttPictureBox.Image != null)
                ganttPictureBox.Image.Dispose();

            ganttPictureBox.Image = gantt.Draw(
                float.Parse(scaleTextBox.Text),
                int.Parse(widthTextBox.Text),
                int.Parse(stepTextBox.Text));
        }

        private void resetButton_Click(object sender, EventArgs e)
        {
            scaleTextBox.Text = (0.03F).ToString();
            widthTextBox.Text = (34000).ToString();
            stepTextBox.Text = (1000).ToString();
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            if (ganttPictureBox.Image != null)
                if (outputSaveFileDialog.ShowDialog() == DialogResult.OK)
                    ((Bitmap)ganttPictureBox.Image).Save(outputSaveFileDialog.FileName);
        }
    }
}