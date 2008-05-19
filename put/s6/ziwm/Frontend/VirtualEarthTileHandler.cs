using System.Drawing.Imaging;
using System.Text.RegularExpressions;
using System.Web;
using System.Drawing;
using LibTiffWrapper;
using System.Web.UI.WebControls;
using System.Diagnostics;

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
                TiffImage image = file.Images[file.Images.Count - key.Length - 2];

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

        private static void DecodeRefererPath(string query, out string path)
        {
            path = new SiteMapDataSource().Provider.FindSiteMapNode(query).Key;
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
