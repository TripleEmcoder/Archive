using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Bridge;
using Types;

namespace Visualizer
{
    public partial class Spectrogram : UserControl
    {
        private double[] prefft;
        private Complex[][] postfft;

        public Spectrogram(double[] values)
        {
            InitializeComponent();

            prefft = values;

            int size = 512;
            int step = 500;
            int count = (values.Length - size) / step;

            postfft = new Complex[count][];

            for (int i = 0; i < count; i++)
            {
                double[] _values = new double[size];
                Array.Copy(values, i * step, _values, 0, size);

                FastFourierTransform fft = new FastFourierTransform(512);
                postfft[i] = fft.Calculate(_values);
            }

            int height = 100;
            int width = 300;

            Bitmap bitmap = new Bitmap(width, height);

            for (int x = 0; x < width; x++)
                for (int i = 0; i < size; i++)
                {
                    Complex c = postfft[(int)(1.0 * x / width * count)][i];

                    if (double.IsNaN(c.Real) || double.IsNaN(c.Imaginary))
                        continue;

                    int a = (int)c.Modulus * 255;
                    int y = (int)c.Argument * height;

                    bitmap.SetPixel(x, y, Color.FromArgb(a, a, a));
                }


            pictureBox1.Image = bitmap;
        }
    }
}
