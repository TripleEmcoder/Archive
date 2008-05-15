#pragma once

namespace LibTiffWrapper {

	public ref class TiffImage
	{
	internal:
		TiffImage(::TIFF* handle, int index);
		~TiffImage();

	public:
		property int Width
		{
			int get();
		}

		property int Height
		{
			int get();
		}

		System::Drawing::Bitmap^ GetTile(int index);

	private:
		::TIFF* handle;
		int index;
	};
}
