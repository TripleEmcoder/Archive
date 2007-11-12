using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

using System.Globalization;
using System.Drawing.Drawing2D;

namespace Visualizer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            resetButton.PerformClick();
        }

        float T;
        
        int m; //j

        int n; //i
        float[,] t, tk;
        
        int l; //k
        float[,] r, rk;         

        private void loadButton_Click(object sender, EventArgs e)
        {
            if (inputOpenFileDialog.ShowDialog() == DialogResult.OK)
            {
                Dictionary<string, float> variables = new Dictionary<string, float>();

                using (Stream stream = inputOpenFileDialog.OpenFile())
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

                string format = "{0}_{1:D2}_{2}";

                n = 8;
                l = 16;

                m = (int)variables["m"];
                T = variables["T"];

                t = new float[n, m];
                tk = new float[n, m];

                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                    {
                        t[i, j] = variables[string.Format(format, "t", i, j)];
                        tk[i, j] = variables[string.Format(format, "tk", i, j)];
                    }

                r = new float[l, m];
                rk = new float[l, m];
                
                for (int k = 0; k < l; k++)
                    for (int j = 0; j < m; j++)
                    {
                        r[k, j] = variables[string.Format(format, "r", k, j)];
                        rk[k, j] = variables[string.Format(format, "rk", k, j)];
                    }
                
                refreshButton.PerformClick();
            }
        }

        private void refreshButton_Click(object sender, EventArgs e)
        {
            //float scale = 1000 / T;
            float scale = float.Parse(scaleTextBox.Text);
            int size = 20;
            int margin = 40;
            int title = 40;

            //int width = (int)(T * scale) + 2 * margin + title;
            int width = int.Parse(widthTextBox.Text) + 2 * margin + title;
            int height = l * m * size + (l + 1) * margin;

            Bitmap bitmap = new Bitmap(width, height);
            Graphics graphics = Graphics.FromImage(bitmap);
            graphics.FillRectangle(Brushes.White, 0, 0, width, height);

            int x = margin + title;

            DrawGrid(graphics, x, 0, width, height - margin, scale, int.Parse(stepTextBox.Text));

            for (int i = 0; i < l; i++)
            {
                int y = margin + i * margin + i * m * size;

                Font font = new Font(FontFamily.GenericSansSerif, 20);
                DrawStringCentered(graphics, font, i.ToString(), margin, y, title, m * size);

                for (int j = 0; j < m; j++)
                {
                    int _y = y + (m-j-1) * size;

                    graphics.DrawRectangle(Pens.Black, x, _y, T * scale, size);

                    if (rk[i, j] - r[i, j] > 0)
                        DrawCommunication(graphics, j.ToString(),
                            x + r[i, j] * scale, _y, (rk[i, j] - r[i, j]) * scale, size);

                    //if (tk[i, j] - t[i, j] > 0)
                    //    DrawComputation(graphics, j.ToString(),
                    //        x + t[i, j] * scale, _y, (tk[i, j] - t[i, j]) * scale, size);
                }
            }

            if (ganttPictureBox.Image != null)
                ganttPictureBox.Image.Dispose();

            ganttPictureBox.Image = bitmap;
        }


        private void resetButton_Click(object sender, EventArgs e)
        {
            scaleTextBox.Text = (0.03F).ToString();
            widthTextBox.Text = (1010).ToString();
            stepTextBox.Text = (1000).ToString();
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            if (ganttPictureBox.Image != null)
                if (outputSaveFileDialog.ShowDialog() == DialogResult.OK)
                    ((Bitmap)ganttPictureBox.Image).Save(outputSaveFileDialog.FileName);
        }

        private void DrawGrid(Graphics graphics, float x, float y, float width, float height, float scale, float step)
        {
            int axis = 30;

            Pen pen = new Pen(Color.Gray);
            pen.DashStyle = DashStyle.Dash;

            Font font = new Font(FontFamily.GenericSansSerif, 12);

            for (float _x = x, i = 0; _x < x + width; _x += step * scale, i++)
            {
                graphics.DrawLine(pen, _x, y + axis, _x, y + height);

                if (i % 2 == 0)
                    DrawStringCentered(graphics, font, Math.Round((_x - x) / scale).ToString(),
                        _x - step * scale, y, 2 * step * scale, axis);
            }
        }

        private void DrawCommunication(Graphics graphics, string text, float x, float y, float width, float height)
        {
            DrawBlock(graphics, Brushes.Red, text, x, y, width, height);
        }

        private void DrawComputation(Graphics graphics, string text, float x, float y, float width, float height)
        {
            DrawBlock(graphics, Brushes.Green, text, x, y, width, height);
        }

        private void DrawBlock(Graphics graphics, Brush brush, string text, float x, float y, float width, float height)
        {
            graphics.FillRectangle(brush, x, y, width, height);
            graphics.DrawRectangle(Pens.Black, x, y, width, height);

            DrawStringCentered(graphics, Font, text, x, y, width, height);
        }

        private static void DrawStringCentered(Graphics graphics, Font font, string text, float x, float y, float width, float height)
        {
            SizeF size = graphics.MeasureString(text, font);

            graphics.DrawString(text, font, Brushes.Black,
                x + width / 2 - size.Width / 2, y + height / 2 - size.Height / 2);
        }
    }
}