#include "stdafx.h"

#include "TiffImageCollection.h"
#include "TiffImage.h"

using namespace LibTiffWrapper;

TiffImageCollection::TiffImageCollection(::TIFF* handle)
:
handle(handle)
{
}

int TiffImageCollection::Count::get()
{ 
	return ::TIFFNumberOfDirectories(handle);
}

TiffImage^ TiffImageCollection::default::get(int index)
{
	return gcnew TiffImage(handle, index);
}
