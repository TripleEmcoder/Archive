#include "stdafx.h"

#include "TiffFile.h"
#include "TiffImage.h"
#include "TiffImageCollection.h"

using namespace System;
using namespace System::Text;
using namespace LibTiffWrapper;

array<unsigned char>^ EncodeText(String^ value)
{
	return Encoding::GetEncoding("ascii")->GetBytes(value);
}

TiffFile::TiffFile(String^ path)
{
	pin_ptr<unsigned char> _path = &EncodeText(path)[0];
	
	handle = ::TIFFOpen((const char*)_path, "r");

	if (handle == NULL)
		throw gcnew Exception("Cannot open file.");

	images = gcnew TiffImageCollection(handle);
}

TiffFile::~TiffFile()
{
	::TIFFClose(handle);
}

TiffImageCollection^ TiffFile::Images::get()
{
	return images;
}
