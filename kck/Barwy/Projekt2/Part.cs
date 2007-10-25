using System;
using System.Collections.Generic;
using System.Text;

using System.Drawing;

namespace Projekt2
{
    struct Part
    {
        public float X;
        public float Y;
        public float Z;

        public Point GetPoint(float scale)
        {
            return new Point(
                (int)(X * scale),
                (int)(Y * scale)
            );
        }
    }
}
