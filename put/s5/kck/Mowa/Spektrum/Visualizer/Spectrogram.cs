using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Bridge;
using Types;
using System.Diagnostics;

namespace Visualizer
{
    public partial class Spectrogram : UserControl
    {
        private int size;
        private int count;
        
        private FastFourierTransform fft;
        private Complex[][] data;

        private int index;
        
        public Spectrogram(int size, int count)
        {
            SetStyle(ControlStyles.UserPaint, true);
            SetStyle(ControlStyles.AllPaintingInWmPaint, true);
            SetStyle(ControlStyles.DoubleBuffer, true);

            InitializeComponent();
            
            this.size = size;
            this.count = count;
            
            fft = new FastFourierTransform(size);
            data = new Complex[count][];
            
            for (int i = 0; i < count; i++)
                data[i] = new Complex[size];

            index = 0;
        }

        public void AddSamples(double[] samples)
        {
            if (samples.Length != size)
                throw new ArgumentException();

            data[index] = fft.Calculate(samples);
            
            Invalidate();

            index = (index+1) % count;
        }

        private void Spectrogram_Paint(object sender, PaintEventArgs e)
        {
            double max = double.MinValue;

            for (int i = 0; i < count; i++)
                for (int j = 0; j < size / 2; j++)
                    max = Math.Max(max, data[i][j].Modulus);

            for (int x = e.ClipRectangle.Left; x <= e.ClipRectangle.Right ; x++)
                for (int y = e.ClipRectangle.Top; y < e.ClipRectangle.Bottom; y++)
                {
                    int i = (int)(1.0 * x / Width * count);
                    int j = (int)(1.0 * y / Height * size / 2);

                    using (Pen pen = new Pen(ColorHandler.HSVtoColor(data[i][j].Modulus / max, 1, 1)))
                        e.Graphics.DrawLine(pen, x, y, x+1, y+1);
                }
        }

        private void Spectrogram_Resize(object sender, EventArgs e)
        {
            Invalidate();
        }
    }
}
