using System;
using System.Collections.Generic;
using System.Text;

using System.IO;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace Visualizer
{
    class Gantt
    {
        private float T;

        private int m; //j

        private int n; //i
        private float[,] t, tk;

        private int l; //k
        private float[,] r, rk;

        private int[] pv, pc;

        public void Load(Stream stream)
        {
            Dictionary<string, float> variables = new Dictionary<string, float>();

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

            string sf = "{0}_{1:D1}";
            string df = "{0}_{1:D2}_{2:D1}";

            n = 8;
            l = 16;

            m = (int)variables["m"];
            T = variables["T"];

            t = new float[n, m];
            tk = new float[n, m];

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    t[i, j] = variables[string.Format(df, "t", i, j)];
                    tk[i, j] = variables[string.Format(df, "tk", i, j)];
                }

            r = new float[l, m];
            rk = new float[l, m];
            pv = new int[l];
            pc = new int[l];

            for (int k = 0; k < l; k++)
            {
                for (int j = 0; j < m; j++)
                {
                    r[k, j] = variables[string.Format(df, "r", k, j)];
                    rk[k, j] = variables[string.Format(df, "rk", k, j)];
                }

                pc[k] = (int)variables[string.Format(sf, "pc", k)];
                pv[k] = (int)variables[string.Format(sf, "pv", k)];
            }
        }

        public Image Draw(float scale, float max, int step)
        {
            //float scale = 1000 / T;
            int size = 20;
            int margin = 30;
            int left = 100;
            int top = 50;
            int bottom = 20;
            float number = 0.3F;
            float path = 0.7F;

            max *= scale;

            int width = (int)max + 2 * margin + left;
            int height = (l -1 + n) * size + (n + 1) * margin + top + bottom;

            Bitmap bitmap = new Bitmap(width, height);
            Graphics graphics = Graphics.FromImage(bitmap);
            graphics.FillRectangle(Brushes.White, 0, 0, width, height);

            int x = margin + left;
            int y = margin + top;

            DrawGrid(graphics, x, margin, max, height - 2 * margin, scale, step);

            for (int i = 0; i < n; i++)
            {
                int _y = y;

                for (int k = 1; k < l; k++)
                    if (pc[k] == i)
                    {
                        DrawStringCentered(graphics, 10, GetPath(k),
                            margin + left * number, y, left * path, size);

                        graphics.DrawRectangle(Pens.Black, x, y, T * scale, size);

                        for (int j = 0; j < m; j++)
                        {
                            if (rk[k, j] - r[k, j] > 0)
                                DrawCommunication(graphics, j.ToString(),
                                    x + r[k, j] * scale, y, (rk[k, j] - r[k, j]) * scale, size);
                        }

                        y += size;
                    }

                graphics.DrawRectangle(Pens.Black, x, y, T * scale, size);

                for (int j = 0; j < m; j++)
                {
                    if (tk[i, j] - t[i, j] > 0)
                        DrawComputation(graphics, j.ToString(),
                            x + t[i, j] * scale, y, (tk[i, j] - t[i, j]) * scale, size);
                }

                y += size;

                DrawStringCentered(graphics, 20, i.ToString(),
                    margin, _y, left * number, y - _y);

                y += margin;
            }

            return bitmap;
        }

        private string GetPath(int k)
        {
            string separator = "-";
            string path = pc[k].ToString();

            while ((k = pv[k]) != 0)
                path = pc[k] + separator + path;

            return "0" + separator + path;
        }

        private void DrawGrid(Graphics graphics, float x, float y, float width, float height, float scale, float step)
        {
            int title = 30;

            Pen pen = new Pen(Color.Gray);
            pen.DashStyle = DashStyle.Dash;

            for (float _x = x, i = 0; _x <= x + width; _x += step * scale, i++)
            {
                graphics.DrawLine(pen, _x, y + title, _x, y + height);

                if (i % 2 == 0)
                    DrawStringCentered(graphics, 12, Math.Round((_x - x) / scale).ToString(),
                        _x - step * scale, y, 2 * step * scale, title);
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

            DrawStringCentered(graphics, 10, text, x, y, width, height);
        }

        private static void DrawStringCentered(Graphics graphics, int size, string text, float x, float y, float width, float height)
        {
            Font font = new Font(FontFamily.GenericSansSerif, size);
            SizeF measurement = graphics.MeasureString(text, font);

            graphics.DrawString(text, font, Brushes.Black,
                x + width / 2 - measurement.Width / 2, y + height / 2 - measurement.Height / 2);

            //graphics.DrawRectangle(Pens.Black, x, y, width, height);
        }
    }
}
