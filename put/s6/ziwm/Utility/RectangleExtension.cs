using System.Drawing;

namespace Utility
{
    public static class RectangleExtension
    {
        public static Rectangle OffsetCopy(this Rectangle @this, Point offset)
        {
            return new Rectangle(
                @this.X+offset.X, @this.Y+offset.Y, @this.Width, @this.Height);
        }
    }
}