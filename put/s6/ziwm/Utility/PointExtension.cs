using System.Drawing;

namespace Utility
{
    public static class PointExtension
    {
        public static Point NegateCopy(this Point @this)
        {
            return new Point(-@this.X, -@this.Y);
        }
    }
}