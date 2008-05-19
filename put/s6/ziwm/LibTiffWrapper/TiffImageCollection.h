#pragma once

namespace LibTiffWrapper
{
	ref class TiffImage;

	public ref class TiffImageCollection
	{
	internal:
		TiffImageCollection(::TIFF* handle);

	public:
		property int Count
		{
			int get();
		}

		property TiffImage^ default[int]
		{
			TiffImage^ get(int index);
		}

	private:
		::TIFF* handle;
	};
}
