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
            int step = 512;
            int count = (values.Length - size) / step;

            postfft = new Complex[count][];

            double maxAmplitude = double.MinValue;
            for (int i = 0; i < count; i++)
            {
                double[] _values = new double[size];
                Array.Copy(values, i * step, _values, 0, size);

                FastFourierTransform fft = new FastFourierTransform(512);
                postfft[i] = fft.Calculate(_values);
                for (int j = 0; j < step; j++)
                {
                    Complex c = postfft[i][j];
                    if (double.IsNaN(c.Real) || double.IsNaN(c.Imaginary)
                       || Math.Abs(c.Real) > 1000 || Math.Abs(c.Imaginary) > 1000)
                        continue;
                    maxAmplitude = Math.Max(maxAmplitude, c.Modulus);
                }
            }

            int height = 100;
            int width = 300;

            Bitmap bitmap = new Bitmap(width, height);

            for (int x = 0; x < width; x++)
                for (int y = 0; y < height; y++)
                {
                    int _x = (int)(1.0 * x / width * count);
                    int _y = (int)(1.0 * y / height * size);
                    
                    Complex c = postfft[_x][_y];

                    if (double.IsNaN(c.Real) || double.IsNaN(c.Imaginary)
                        || Math.Abs(c.Real) > 1000 || Math.Abs(c.Imaginary) > 1000)
                        continue;

                    float a = (float)(c.Modulus / maxAmplitude * 360);
                    bitmap.SetPixel(x, y, HtoRGB(a));
                }


            pictureBox1.Image = bitmap;
        }


        public static Color HSVtoRGB(float h, float s, float v)
        {
            // HSV contains values scaled as in the color wheel:
            // that is, all from 0 to 255. 

            // for ( this code to work, HSV.Hue needs
            // to be scaled from 0 to 360 (it//s the angle of the selected
            // point within the circle). HSV.Saturation and HSV.value must be 
            // scaled to be between 0 and 1.


            float r = 0;
            float g = 0;
            float b = 0;

            // Scale Hue to be between 0 and 360. Saturation
            // and value scale to be between 0 and 1.
            //h = ((float)sh / 255 * 360) % 360;


            if (s == 0)
            {
                // If s is 0, all colors are the same.
                // This is some flavor of gray.
                r = v;
                g = v;
                b = v;
            }
            else
            {
                float p;
                float q;
                float t;

                float fractionalSector;
                int sectorNumber;
                float sectorPos;

                // The color wheel consists of 6 sectors.
                // Figure out which sector you//re in.
                sectorPos = h / 60;
                sectorNumber = (int)(Math.Floor(sectorPos));

                // get the fractional part of the sector.
                // That is, how many degrees into the sector
                // are you?
                fractionalSector = sectorPos - sectorNumber;

                // Calculate values for the three axes
                // of the color. 
                p = v * (1 - s);
                q = v * (1 - (s * fractionalSector));
                t = v * (1 - (s * (1 - fractionalSector)));

                // Assign the fractional colors to r, g, and b
                // based on the sector the angle is in.
                switch (sectorNumber)
                {
                    case 0:
                        r = v;
                        g = t;
                        b = p;
                        break;

                    case 1:
                        r = q;
                        g = v;
                        b = p;
                        break;

                    case 2:
                        r = p;
                        g = v;
                        b = t;
                        break;

                    case 3:
                        r = p;
                        g = q;
                        b = v;
                        break;

                    case 4:
                        r = t;
                        g = p;
                        b = v;
                        break;

                    case 5:
                        r = v;
                        g = p;
                        b = q;
                        break;
                }
            }
            // return an RGB structure, with values scaled
            // to be between 0 and 255.
            return Color.FromArgb((int)(r * 255), (int)(g * 255), (int)(b * 255));
        }

        public static Color HtoRGB(float h)
        {
            return HSVtoRGB(h, 1, (float)0.6);
        }        
    }
}
