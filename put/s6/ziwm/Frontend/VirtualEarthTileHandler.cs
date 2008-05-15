using System.Drawing.Imaging;
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

            string quadKey = "0";
            string imagePath = "F:\\Downloads\\Public\\VLI\\heic0602a.ptiff";

            using (TiffFile file = new TiffFile(imagePath))
            {
                TiffImage[] levels = file.GetImages();
                TiffImage level = levels[levels.Length - quadKey.Length];

                context.Response.ContentType = "image/jpeg";
                context.Response.BufferOutput = true;

                using (Bitmap bitmap = level.GetTile(int.Parse(quadKey)))
                    bitmap.Save(context.Response.OutputStream, ImageFormat.Jpeg);
            }
        }

        public bool IsReusable
        {
            get { return true; }
        }
    }
}
