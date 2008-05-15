#pragma once

namespace LibTiffWrapper
{
	ref class TiffImage;

	public ref class TiffFile
	{
	public:
		TiffFile(System::String^ path);
		~TiffFile();
		array<TiffImage^>^ GetImages();
	private:
		::TIFF* handle;
	};
}
