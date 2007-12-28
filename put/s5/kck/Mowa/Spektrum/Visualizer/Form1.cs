using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Bridge;

namespace Visualizer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
                Text = openFileDialog1.FileName;
                using (SoundFile file = new SoundFile(openFileDialog1.FileName))
                {
                    foreach (Control control in flowLayoutPanel1.Controls)
                        control.Dispose();

                    flowLayoutPanel1.Controls.Clear();

                    toolStripStatusLabel1.Text = string.Format(
                        "{0} Hz, {1} channel(s), {2} frames, {3}",
                        file.Samplerate, file.Channels, file.Frames,
                        TimeSpan.FromSeconds(1.0 * file.Frames / file.Samplerate));

                    double[] mixed = file.ReadDouble(file.Frames);

                    for (int channel = 0; channel < file.Channels; channel++)
                    {
                        double[] split = new double[file.Frames];

                        for (int frame = 0; frame < file.Frames; frame++)
                            split[frame] = mixed[frame * file.Channels + channel];

                        flowLayoutPanel1.Controls.Add(new Spectrogram(split));
                    }
                }
        }
    }
}