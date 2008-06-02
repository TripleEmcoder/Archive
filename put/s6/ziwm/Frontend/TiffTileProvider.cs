using System;
using System.Data;
using System.Configuration;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;
using LibTiffWrapper;
using Image = System.Drawing.Image;

namespace Frontend
{
    public class TiffTileProvider : IDisposable
    {
        private readonly TiffFile file;

        public TiffTileProvider(string filePath)
        {
            file = new TiffFile(filePath);
        }

        public void Dispose()
        {
            file.Dispose();
        }

        public Bitmap GetTile(string key, int size)
        {
            int index = file.Images.Count - key.Length - 1;

            if (index < 0)
                return null;

            TiffImage image = file.Images[index];

            Debug.Assert(image.TileWidth == size);
            Debug.Assert(image.TileHeight == size);

            int row, column;
            QuadKeyToRowColumn(key, out row, out column);

            Bitmap bitmap = image.GetTile(column * size, row * size);
            return bitmap;
        }

        private static void QuadKeyToRowColumn(string key, out int row, out int column)
        {
            int level = 0;
            int size = 1 << key.Length;
            int skip = 1 << key.Length - 1;

            row = 0;
            column = 0;

            while (level < key.Length)
            {
                if (key[level] == '1' || key[level] == '3')
                    column += skip;

                if (key[level] == '2' || key[level] == '3')
                    row += skip;

                level += 1;
                skip /= 2;
            }
        }
    }
}
