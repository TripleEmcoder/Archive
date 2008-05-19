#pragma once

namespace LibTiffWrapper
{
	public ref class TiffImage
	{
	internal:
		TiffImage(::TIFF* handle, int index);

	public:
		property int Width
		{
			int get();
		}

		property int Height
		{
			int get();
		}

		property int TileWidth
		{
			int get();
		}

		property int TileHeight
		{
			int get();
		}

		System::Drawing::Bitmap^ GetTile(int number);
		System::Drawing::Bitmap^ GetTile(int x, int y);

	private:
		::TIFF* handle;
		int index;
	};
}
