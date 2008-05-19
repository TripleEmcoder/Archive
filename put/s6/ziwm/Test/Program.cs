using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using LibTiffWrapper;
using System.Drawing.Imaging;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TiffFile file = new TiffFile("F:\\Downloads\\Public\\VLI\\heic0601a.ptiff"))
            {
                TiffImage image = file.Images[5];

                using (Bitmap bitmap = image.GetTile(0 * 256, 0 * 256))
                    bitmap.Save("0.jpg", ImageFormat.Jpeg);

                using (Bitmap bitmap = image.GetTile(1 * 256, 0 * 256))
                    bitmap.Save("1.jpg", ImageFormat.Jpeg);

                using (Bitmap bitmap = image.GetTile(0 * 256, 1 * 256))
                    bitmap.Save("2.jpg", ImageFormat.Jpeg);

                using (Bitmap bitmap = image.GetTile(1 * 256, 1 * 256))
                    bitmap.Save("3.jpg", ImageFormat.Jpeg);

            }
        }
    }
}
