using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

using System.Globalization;

namespace Visualizer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int n, m;
        float T;
        float[,] r, rk, t, tk;

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Dictionary<string, float> variables = new Dictionary<string, float>();

                using (Stream stream = openFileDialog1.OpenFile())
                using (StreamReader reader = new StreamReader(stream))
                {
                    reader.ReadLine();

                    while (!reader.EndOfStream)
                    {
                        string[] parts = reader.ReadLine().Split(';');

                        if (parts.Length < 2)
                            continue;

                        variables[parts[0]] = float.Parse(parts[1], CultureInfo.InvariantCulture);
                    }
                }

                string format = "{0}_{1}_{2}";

                n = 8;
                m = (int)variables["m"];
                T = variables["T"];

                r = new float[n, m];
                rk = new float[n, m];
                t = new float[n, m];
                tk = new float[n, m];

                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                    {
                        r[i, j] = variables[string.Format(format, "r", i, j)];
                        rk[i, j] = variables[string.Format(format, "rk", i, j)];
                        t[i, j] = variables[string.Format(format, "t", i, j)];
                        tk[i, j] = variables[string.Format(format, "tk", i, j)];
                    }
            }
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            float scale = 0.01F;
            int size = 15;
            int margin = 30;

            int width = (int)(T * scale) + 2 * margin;
            int height = n * m * size + (n + 1) * margin;

            Bitmap bitmap = new Bitmap(width, height);
            Graphics graphics = Graphics.FromImage(bitmap);
            graphics.FillRectangle(Brushes.White, 0, 0, width, height);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    int  top = margin + i * margin + (i * m + j) * size;
                    
                    graphics.DrawRectangle(Pens.Black,
                        margin,
                        top,
                        T * scale,
                        size);

                    graphics.FillRectangle(Brushes.Red,
                        margin + r[i, j] * scale,
                        top,
                        (rk[i, j] - r[i, j]) * scale,
                        size);

                    graphics.FillRectangle(Brushes.Green,
                        margin + t[i, j] * scale,
                        top,
                        (tk[i, j] - t[i, j]) * scale,
                        size);
                }

            if (pictureBox1.Image != null)
                pictureBox1.Image.Dispose();

            pictureBox1.Image = bitmap;
        }
    }
}