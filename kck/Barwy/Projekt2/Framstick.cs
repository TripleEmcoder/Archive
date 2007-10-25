using System;
using System.Collections.Generic;
using System.Text;

using System.IO;
using System.Globalization;
using System.Drawing;

namespace Projekt2
{
    class Framstick
    {
        private Part[] parts;
        private Stick[] sticks;

        public string[] GetTokens(StreamReader reader)
        {
            while (true)
            {
                string line = reader.ReadLine();

                if (line == null)
                    return null;

                if (line == "" || line.StartsWith("#"))
                    continue;

                return line.Split(' ');
            }
        }

        public void Load(StreamReader reader)
        {
            string[] header = GetTokens(reader);

            parts = new Part[int.Parse(header[1])];
            sticks = new Stick[int.Parse(header[2])];


            for (int i = 0; i < parts.Length; i++)
            {
                string[] part = GetTokens(reader);

                parts[i].X = float.Parse(part[0]);
                parts[i].Y = float.Parse(part[1]);
                parts[i].Z = float.Parse(part[2]);
            }

            float minX = float.MaxValue;
            float minY = float.MaxValue;
            float minZ = float.MaxValue;

            for (int i = 0; i < parts.Length; i++)
            {
                minX = Math.Min(minX, parts[i].X);
                minY = Math.Min(minY, parts[i].Y);
                minZ = Math.Min(minZ, parts[i].Z);
            }

            for (int i = 0; i < parts.Length; i++)
            {
                parts[i].X -= minX;
                parts[i].Y -= minY;
                parts[i].Z -= minZ;
            }

            for (int i = 0; i < sticks.Length; i++)
            {
                string[] stick = GetTokens(reader);

                sticks[i].A = int.Parse(stick[0]);
                sticks[i].B = int.Parse(stick[1]);
                sticks[i].LinearStress = float.Parse(stick[2]);
            }
        }

        public void Paint(Graphics graphics)
        {
            float scale = 50;
            Size origin = new Size(100, 100);

            for (int i = 0; i < parts.Length; i++)
            {
                graphics.FillEllipse(Brushes.Black,
                    new Rectangle(parts[i].GetPoint(scale) - new Size(5, 5) + origin, new Size(10, 10)));
            }

            for (int i = 0; i < sticks.Length; i++)
            {
                graphics.DrawLine(Pens.Brown,
                    parts[sticks[i].A].GetPoint(scale) + origin, parts[sticks[i].B].GetPoint(scale) + origin);
            }
        }
    }
}
