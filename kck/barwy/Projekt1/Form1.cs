using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Projekt1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private Color GetColor(int i)
        {
            int s = i / 256;
            int j = i % 256;

            switch (s)
            {
                case 0:
                    return Color.FromArgb(255, j, 0);

                case 1:
                    return Color.FromArgb(255 - j, 255, 0);

                case 2:
                    return Color.FromArgb(0, 255, j);

                case 3:
                    return Color.FromArgb(0, 255 - j, 255);

                default:
                    return Color.Black;
            }
        }

        public static Color GetColorFromAhsb(int a, float h, float s, float b)
        {
            if (0 == s)
            {
                return Color.FromArgb(a, Convert.ToInt32(b * 255),
                  Convert.ToInt32(b * 255), Convert.ToInt32(b * 255));
            }

            float fMax, fMid, fMin;
            int iSextant, iMax, iMid, iMin;

            if (0.5 < b)
            {
                fMax = b - (b * s) + s;
                fMin = b + (b * s) - s;
            }
            else
            {
                fMax = b + (b * s);
                fMin = b - (b * s);
            }

            iSextant = (int)Math.Floor(h / 60f);
            if (300f <= h)
            {
                h -= 360f;
            }
            h /= 60f;
            h -= 2f * (float)Math.Floor(((iSextant + 1f) % 6f) / 2f);
            if (0 == iSextant % 2)
            {
                fMid = h * (fMax - fMin) + fMin;
            }
            else
            {
                fMid = fMin - h * (fMax - fMin);
            }

            iMax = Convert.ToInt32(fMax * 255);
            iMid = Convert.ToInt32(fMid * 255);
            iMin = Convert.ToInt32(fMin * 255);

            switch (iSextant)
            {
                case 1:
                    return Color.FromArgb(a, iMid, iMax, iMin);
                case 2:
                    return Color.FromArgb(a, iMin, iMax, iMid);
                case 3:
                    return Color.FromArgb(a, iMin, iMid, iMax);
                case 4:
                    return Color.FromArgb(a, iMid, iMin, iMax);
                case 5:
                    return Color.FromArgb(a, iMax, iMin, iMid);
                default:
                    return Color.FromArgb(a, iMax, iMid, iMin);
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            int max = 200;

            for (int i = 0; i <= max; i++)
            {
                Pen p = new Pen(GetColor(i*1023/max));
                g.DrawLine(p, i, 0, i, 100);
            }

            for (int i = 0; i <= max; i++)
            {
                Pen p = new Pen(GetColorFromAhsb(255, 1.0f*i*240/max, 1, 0.5f));
                g.DrawLine(p, i, 110, i, 210);
            }
        }

        private void Form1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (0 <= e.X && e.X <= 1023 && 0 <= e.Y && e.Y <= 100)
            {
                Color c = GetColor(e.X);
                label1.Text = string.Format("R: {0}\nG: {1}\nB: {2}", c.R, c.G, c.B);
                label2.Text = string.Format("H: {0}\nS: {1}\nB: {2}", c.GetHue(), c.GetSaturation(), c.GetBrightness());
            }
        }
    }
}
