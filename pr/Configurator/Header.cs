using System;
using System.Collections.Generic;
using System.Text;

using System.IO;

namespace Configurator
{
    class Header
    {
        private int m; //j - fazy

        private int n; //i - procesory

        private int l; //k - paczki
        private float[,] Sa;

        private int[] pv, pc;

        public void Load(TextReader reader)
        {
            Dictionary<string, float> variables = new Dictionary<string, float>();

            reader.ReadLine();

            while (reader.Peek() != -1)
            {
                string[] parts = reader.ReadLine().Split(';');

                if (parts.Length < 2)
                    continue;

                variables[parts[0]] = float.Parse(parts[1]);
            }

            string sf = "{0}_{1:D1}";
            string df = "{0}_{1:D1}_{2:D1}";

            n = 8;
            l = 16;

            m = (int)variables["m"];

            Sa = new float[l, m];
            pv = new int[l];
            pc = new int[l];

            for (int k = 0; k < l; k++)
            {
                for (int j = 0; j < m; j++)
                    Sa[k, j] = variables[string.Format(df, "Sa", k, j)];

                pc[k] = (int)variables[string.Format(sf, "pc", k)];
                pv[k] = (int)variables[string.Format(sf, "pv", k)];
            }
        }

        public void Save(TextWriter writer, string name)
        {
            float[, , ,] sizes = new float[n, n, m, 3];
            int[] indices = new int[l];

            for (int k = 1; k < l; k++)
                for (int j = 0; j < m; j++)
                    sizes[pc[pv[k]], pc[k], j, 0] = Sa[k, j];

            for (int k = 4; k < l; k++)
            {
                indices[pv[k]]++;

                for (int j = 0; j < m; j++)
                    sizes[pc[pv[pv[k]]], pc[pv[k]], j, indices[pv[k]]] = Sa[k, j];
            }

            writer.WriteLine(string.Format("float {0}**** = ", name));
            Write(writer, sizes, 0, new int[] { 0, 0, 0, 0 });

        }

        private void Write(TextWriter writer, Array array, int dimension, int[] indices)
        {
            if (dimension == array.Rank)
            {
                writer.Write(Math.Round((float)array.GetValue(indices)));
                return;
            }

            string newline = "";

            if (dimension < array.Rank - 1)
                newline = writer.NewLine;

            writer.Write("{" + newline);

            for (int i = 0; i < array.GetLength(dimension) - 1; i++)
            {
                indices[dimension] = i;
                Write(writer, array, dimension + 1, indices);
                writer.Write("," + newline);
            }

            indices[dimension] = array.GetLength(dimension) - 1;
            Write(writer, array, dimension + 1, indices);

            writer.Write(newline + "}");
        }
    }
}
