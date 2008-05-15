#include "stdafx.h"

#include "TiffImage.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::IO;
using namespace LibTiffWrapper;

TiffImage::TiffImage(::TIFF* handle, int index)
:
handle(handle),
index(index)
{
}

TiffImage::~TiffImage()
{
}

int TiffImage::Width::get()
{
	uint32 width;
	TIFFSetDirectory(handle, index);
	TIFFGetField(handle, TIFFTAG_IMAGEWIDTH, &width);
	return width;
}

int TiffImage::Height::get()
{
	uint32 height;
	TIFFSetDirectory(handle, index);
	TIFFGetField(handle, TIFFTAG_IMAGELENGTH, &height);
	return height;
}

Bitmap^ TiffImage::GetTile(int index)
{
	const PixelFormat format = PixelFormat::Format24bppRgb;
	
	TIFFSetDirectory(handle, index);
	
	int width, height, size =  TIFFTileSize(handle);
	TIFFGetField(handle, TIFFTAG_TILEWIDTH, &width);
	TIFFGetField(handle, TIFFTAG_TILELENGTH, &height);
	
	Rectangle rectangle(0, 0, width, height);

	Bitmap^ bitmap = gcnew Bitmap(width, height, format);
	BitmapData^ data = bitmap->LockBits(rectangle, ImageLockMode::WriteOnly, format);
	TIFFReadEncodedTile(handle, index, (void*)data->Scan0, size);
	bitmap->UnlockBits(data);

	return bitmap;
}
