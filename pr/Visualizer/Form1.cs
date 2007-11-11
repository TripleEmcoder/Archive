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

                        variables[parts[0]] = float.Parse(parts[1]);
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
            float scale = 0.03F;
            int size = 20;
            int margin = 30;
            int title = 50;

            int width = (int)(T * scale) + 2 * margin + title;
            int height = n * m * size + (n + 1) * margin;

            Bitmap bitmap = new Bitmap(width, height);
            Graphics graphics = Graphics.FromImage(bitmap);
            graphics.FillRectangle(Brushes.White, 0, 0, width, height);

            int left = margin + title;

            for (int i = 0; i < n; i++)
            {
                int top = margin + i * margin + i * m * size;

                Font font = new Font(FontFamily.GenericSansSerif, 20);
                DrawStringCentered(graphics, font, i.ToString(), margin, top, title, m * size);

                for (int j = 0; j < m; j++)
                {
                    int _top = top + j * size;                    

                    graphics.DrawRectangle(Pens.Black, left, _top, T * scale, size);

                    if (rk[i, j] - r[i, j] > 0)
                        DrawCommunication(graphics, j.ToString(),
                            left + r[i, j] * scale, _top, (rk[i, j] - r[i, j]) * scale, size);

                    if (tk[i, j] - t[i, j] > 0)
                        DrawComputation(graphics, j.ToString(),
                            left + t[i, j] * scale, _top, (tk[i, j] - t[i, j]) * scale, size);
                }
            }

            if (pictureBox1.Image != null)
                pictureBox1.Image.Dispose();

            pictureBox1.Image = bitmap;
        }

        private void DrawGrid(Graphics graphics)
        {

        }

        private void DrawCommunication(Graphics graphics, string text, float x, int y, float width, float height)
        {
            DrawBlock(graphics, Brushes.Red, text, x, y, width, height);
        }

        private void DrawComputation(Graphics graphics, string text, float x, int y, float width, float height)
        {
            DrawBlock(graphics, Brushes.Green, text, x, y, width, height);
        }

        private void DrawBlock(Graphics graphics, Brush brush, string text, float x, int y, float width, float height)
        {
            graphics.FillRectangle(brush, x, y, width, height);
            graphics.DrawRectangle(Pens.Black, x, y, width, height);

            DrawStringCentered(graphics, Font, text, x, y, width, height);
        }

        private static void DrawStringCentered(Graphics graphics, Font font, string text, float x, int y, float width, float height)
        {
            SizeF size = graphics.MeasureString(text, font);

            graphics.DrawString(text, font, Brushes.Black,
                x + width / 2 - size.Width / 2, y + height / 2 - size.Height / 2);
        }
    }
}