using System;
using System.Collections.Generic;
using System.Text;

using System.IO;

namespace Converter
{
    class Schedule
    {
        const string sf = "{0}_{1:D1}";
        const string df = "{0}_{1:D2}_{2:D1}";

        private float T;

        private int m; //j - fazy

        private int n; //i - procesory
        private float[,] t, tk;

        private int l; //k - paczki
        private float[,] r, rk;

        private int[] pv, pc;

        public void LoadSimulation(TextReader reader)
        {
            Dictionary<string, float> variables = new Dictionary<string, float>();

            reader.ReadLine();

            while (reader.Peek() != -1)
            {
                string[] parts = reader.ReadLine().Split(';');

                if (parts.Length < 2)
                    continue;

                variables[parts[0]] = float.Parse(parts[parts.Length - 1]);
            }

            n = 8;
            l = 16;

            m = (int)variables["m"];

            t = new float[n, m];
            tk = new float[n, m];
            r = new float[l, m];
            rk = new float[l, m];
            pv = new int[l];
            pc = new int[l];

            for (int k = 0; k < l; k++)
            {
                pc[k] = (int)variables[string.Format(sf, "pc", k)];
                pv[k] = (int)variables[string.Format(sf, "pv", k)];
            }
        }

        public void LoadReal(TextReader reader)
        {
            while (reader.Peek() != -1)
            {
                string[] parts = reader.ReadLine().Split(' ');

                if (parts.Length < 5)
                    continue;

                int si = int.Parse(parts[0]);
                int ti = int.Parse(parts[1]);
                int j = int.Parse(parts[2]);
                int s = int.Parse(parts[3]);
                int st = int.Parse(parts[4]);

                if (si == ti)
                {
                    t[si, j] = s;
                    tk[si, j] = st;
                }
                else for (int k = 0; k < l; k++)
                        if (pc[pv[k]] == si && pc[k] == ti)
                        {
                            r[k, j] = s;
                            rk[k, j] = st;
                        }
            }

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    T = Math.Max(T, tk[i, j]);

            for (int k = 0; k < l; k++)
                for (int j = 0; j < m; j++)
                    T = Math.Max(T, rk[k, j]);
        }

        public void Save(TextWriter writer)
        {
            writer.WriteLine("Variables;result");
            writer.WriteLine("m;" + m);
            writer.WriteLine("T;" + T);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    writer.WriteLine(string.Format(df, "t", i, j) + ";" + t[i, j]);
                    writer.WriteLine(string.Format(df, "tk", i, j) + ";" + tk[i, j]);
                }

            for (int k = 0; k < l; k++)
            {
                for (int j = 0; j < m; j++)
                {
                    writer.WriteLine(string.Format(df, "r", k, j) + ";" + r[k, j]);
                    writer.WriteLine(string.Format(df, "rk", k, j) + ";" + rk[k, j]);
                }

                writer.WriteLine(string.Format(sf, "pc", k) + ";" + pc[k]);
                writer.WriteLine(string.Format(sf, "pv", k) + ";" + pv[k]);
            }
        }
    }
}
