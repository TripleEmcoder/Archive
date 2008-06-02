using System;
using System.Diagnostics;
using System.Drawing;
using LibTiffWrapper;
using Utility;

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

            int row, column;
            QuadKeyToRowColumn(key, out row, out column);

            System.Drawing.Point offset = new System.Drawing.Point(
                ((1 << key.Length) * image.TileWidth - image.Width) / 2,
                ((1 << key.Length) * image.TileWidth - image.Height) / 2);

            Rectangle region = new Rectangle(
                column * size, row * size, size, size);

            return Extract(image, offset, region);
        }

        public Bitmap Extract(TiffImage image, System.Drawing.Point offset, Rectangle region)
        {
            Bitmap regionImage = new Bitmap(region.Width, region.Height);

            Rectangle tile = new Rectangle(
                Math.Max(region.X - (region.X - offset.X) % image.TileWidth, offset.X),
                Math.Max(region.Y - (region.Y - offset.Y) % image.TileWidth, offset.Y),
                image.TileWidth, image.TileHeight);

            tile = FixTileSize(image, offset, tile);

            using (Graphics graphics = Graphics.FromImage(regionImage))
                DrawRows(image, offset, region, tile, graphics);

            return regionImage;
        }

        private void DrawRows(TiffImage image, System.Drawing.Point offset, Rectangle region, Rectangle tile, Graphics graphics)
        {
            while (tile.IntersectsWith(region))
            {
                DrawRow(image, offset, region, tile, graphics);
                tile = NextTileY(image, offset, tile);
            }
        }

        private void DrawRow(TiffImage image, System.Drawing.Point offset, Rectangle region, Rectangle tile, Graphics graphics)
        {
            while (tile.IntersectsWith(region))
            {
                Rectangle fragment = Rectangle.Intersect(tile, region);
                Rectangle source = fragment.OffsetCopy(tile.Location.NegateCopy());
                Rectangle destination = fragment.OffsetCopy(region.Location.NegateCopy());

                using (Bitmap tileImage = image.GetTile(tile.X - offset.X, tile.Y - offset.Y))
                {
                    graphics.DrawImage(tileImage, destination, source, GraphicsUnit.Pixel);
                    graphics.DrawRectangle(Pens.Yellow, destination);
                }

                tile = NextTileX(image, offset, tile);
            }
        }

        private static Rectangle NextTileX(TiffImage image, System.Drawing.Point offset, Rectangle tile)
        {
            tile.Offset(image.TileWidth, 0);
            return FixTileSize(image, offset, tile);
        }

        private Rectangle NextTileY(TiffImage image, System.Drawing.Point offset, Rectangle tile)
        {
            tile.Offset(0, image.TileHeight);
            return FixTileSize(image, offset, tile);
        }

        private static Rectangle FixTileSize(TiffImage image, System.Drawing.Point offset, Rectangle tile)
        {
            return Rectangle.FromLTRB(
                tile.Left, tile.Top,
                Math.Min(tile.Right, offset.X + image.Width),
                Math.Min(tile.Bottom, offset.Y + image.Height));
        }

        private static void QuadKeyToRowColumn(string key, out int row, out int column)
        {
            int level = 0;
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
