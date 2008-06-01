using System;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.Text.RegularExpressions;
using System.Web;
using System.Web.UI.WebControls;
using LibTiffWrapper;

namespace Frontend
{
    public class VirtualEarthTileHandler : IHttpHandler
    {
        static VirtualEarthTileHandler()
        {
            string path = string.Format("{0};{1}",
                Environment.GetEnvironmentVariable("PATH"),
                AppDomain.CurrentDomain.RelativeSearchPath);

            Environment.SetEnvironmentVariable("PATH", path, EnvironmentVariableTarget.Process);
        }

        public void ProcessRequest(HttpContext context)
        {
            if (context.Request.UrlReferrer == null)
            {
                context.Response.StatusCode = 403;
                return;
            }

            string filePath = FileContext.Current.Path;
            string key = FileContext.Current.Key;

            using (TiffFile file = new TiffFile(filePath))
            {
                int index = file.Images.Count - key.Length - 2;

                if (index < 0)
                {
                    context.Response.StatusCode = 404;
                    return;
                }

                TiffImage image = file.Images[index];

                Debug.Assert(image.TileWidth == 256);
                Debug.Assert(image.TileHeight == 256);

                int level = 0, x = 0, y = 0;
                int size = 1 << key.Length;
                int skip = 1 << key.Length - 1;

                while (level < key.Length)
                {
                    if (key[level] == '1' || key[level] == '3')
                        x += skip;

                    if (key[level] == '2' || key[level] == '3')
                        y += skip;

                    level += 1;
                    skip /= 2;
                }

                context.Response.ContentType = "image/jpeg";
                context.Response.BufferOutput = true;

                context.Response.CacheControl = "No-Cache";

                using (Bitmap bitmap = image.GetTile(x * 256, y * 256))
                {
                    DrawTileInfo(bitmap, key);
                    bitmap.Save(context.Response.OutputStream, ImageFormat.Jpeg);
                }
            }
        }

        [Conditional("DEBUG")]
        private void DrawTileInfo(Bitmap bitmap, string key)
        {
            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                graphics.DrawString(key, new Font(FontFamily.GenericSansSerif, 8), Brushes.White, 0, 0);
                graphics.DrawRectangle(Pens.White, 0, 0, 255, 255);
            }
        }

       

        public bool IsReusable
        {
            get { return true; }
        }
    }
}
