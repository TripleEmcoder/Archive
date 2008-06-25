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

            string path = FileContext.Current.Path;
            string key = FileContext.Current.Key;

            using (TiffTileProvider provider = new TiffTileProvider(path))
            using (Bitmap bitmap = provider.GetTile(key, 256))
            {
                if (bitmap == null)
                {
                    context.Response.StatusCode = 404;
                    return;
                }

                DrawTileInfo(bitmap, key);

                context.Response.ContentType = "image/jpeg";
                context.Response.BufferOutput = true;

#if DEBUG
                context.Response.CacheControl = "No-Cache";
#endif

                bitmap.Save(context.Response.OutputStream, ImageFormat.Jpeg);
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
