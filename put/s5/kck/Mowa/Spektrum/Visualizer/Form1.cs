using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using System.Diagnostics;
using System.IO;

using Bridge;

namespace Visualizer
{
    public partial class Form1 : Form
    {
        private Spectrogram[] spectrograms;

        public Form1()
        {
            InitializeComponent();

            toolStripComboBox1.SelectedIndex = 0;
            toolStripComboBox2.SelectedIndex = 0;
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
                LoadFile(openFileDialog1.FileName);
        }

        private void LoadFile(string name)
        {
            Text = openFileDialog1.FileName;

            using (SoundFile file = new SoundFile(name))
            {
                int size = int.Parse(toolStripComboBox1.Text);
                int count = int.Parse(toolStripComboBox2.Text);

                CreateControls(file.Channels, size, count);

                toolStripStatusLabel1.Text = string.Format(
                    "{0} Hz, {1} channel(s), {2} frames, {3}",
                    file.Samplerate, file.Channels, file.Frames,
                    TimeSpan.FromSeconds(1.0 * file.Frames / file.Samplerate));

                AddMixed(file.Channels, file.ReadDouble(file.Frames), size);
            }
        }

        private void AddMixed(int channels, double[] mixed, int size)
        {
            for (int channel = 0; channel < channels; channel++)
            {
                double[] split = new double[mixed.Length / channels];

                for (int frame = 0; frame < mixed.Length / channels; frame++)
                    split[frame] = mixed[frame * channels + channel];

                AddSplit(channel, split, size);
            }
        }

        private void AddSplit(int channel, double[] split, int size)
        {
            for (int offset = 0; offset <= split.Length - size; offset += size)
            {
                double[] window = new double[size];
                Array.Copy(split, offset, window, 0, size);
                spectrograms[channel].AddSamples(window);
            }
        }

        private void CreateControls(int channels, int size, int count)
        {
            foreach (Control control in panel1.Controls)
                control.Dispose();

            panel1.Controls.Clear();

            spectrograms = new Spectrogram[channels];

            for (int channel = 0; channel < channels; channel++)
            {
                Splitter splitter = new Splitter();
                splitter.Dock = DockStyle.Top;
                panel1.Controls.Add(splitter);

                Spectrogram spectrogram = new Spectrogram(size, count);
                spectrogram.Dock = DockStyle.Top;
                panel1.Controls.Add(spectrogram);

                spectrograms[channel] = spectrogram;
            }

            Panel fill = new Panel();
            fill.Dock = DockStyle.Fill;
        }

        private void toolStripComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (File.Exists(Text))
                LoadFile(Text);
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {

        }
    }
}