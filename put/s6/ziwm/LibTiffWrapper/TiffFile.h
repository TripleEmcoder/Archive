#pragma once

namespace LibTiffWrapper
{
	ref class TiffImageCollection;

	public ref class TiffFile
	{
	public:
		TiffFile(System::String^ path);
		~TiffFile();

		property TiffImageCollection^ Images
		{
			TiffImageCollection^ get();
		}

	private:
		::TIFF* handle;
		TiffImageCollection^ images;
	};
}
