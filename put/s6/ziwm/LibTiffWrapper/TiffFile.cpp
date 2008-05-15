#include "stdafx.h"

#include "TiffFile.h"
#include "TiffImage.h"

using namespace System;
using namespace System::Text;
using namespace LibTiffWrapper;

array<unsigned char>^ EncodeText(String^ value)
{
	return Encoding::GetEncoding("utf-8")->GetBytes(value);
}

TiffFile::TiffFile(String^ path)
{
	pin_ptr<unsigned char> _path = &EncodeText(path)[0];
	handle = ::TIFFOpen((const char*)_path, "r");
}

TiffFile::~TiffFile()
{
	TIFFClose(handle);
}

array<TiffImage^>^ TiffFile::GetImages()
{
	array<TiffImage^>^ images = gcnew array<TiffImage^>(TIFFNumberOfDirectories(handle));
	
	for(int imageIndex = 0; imageIndex < images->Length; imageIndex++)
		images[imageIndex] = gcnew TiffImage(handle, imageIndex);

	return images;
}
