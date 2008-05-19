using System.Drawing.Imaging;
using System.Text.RegularExpressions;
using System.Web;
using System.Drawing;
using LibTiffWrapper;

namespace Frontend
{
    public class VirtualEarthTileHandler : IHttpHandler
    {
        public void ProcessRequest(HttpContext context)
        {
            if (context.Request.UrlReferrer == null)
            {
                context.Response.StatusCode = 403;
                return;
            }

            string filePath, key;
            DecodeRefererPath(context.Request.UrlReferrer.PathAndQuery, out filePath);
            DecodePath(context.Request.Url.PathAndQuery, out key);

            using (TiffFile file = new TiffFile(filePath))
            {
                TiffImage[] levels = file.GetImages();
                TiffImage level = levels[levels.Length - key.Length];

                context.Response.ContentType = "image/jpeg";
                context.Response.BufferOutput = true;

                using (Bitmap bitmap = level.GetTile(int.Parse(key)))
                    bitmap.Save(context.Response.OutputStream, ImageFormat.Jpeg);
            }
        }

        private static void DecodeRefererPath(string query, out string path)
        {
            Regex regex = new Regex(@"Path=([^&]+)(&|$)", RegexOptions.Compiled);
            Match match = regex.Match(query);
            path = match.Groups[1].Value;
        }

        private static void DecodePath(string query, out string key)
        {
            Regex regex = new Regex(@"/(\w)(\d+)\.png", RegexOptions.Compiled);
            Match match = regex.Match(query);
            key = match.Groups[2].Value;
        }

        public bool IsReusable
        {
            get { return true; }
        }
    }
}
