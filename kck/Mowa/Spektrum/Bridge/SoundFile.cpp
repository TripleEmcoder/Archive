#include "SoundFile.h"

using namespace Bridge;

using namespace System;
using namespace System::Text;

SoundFile::SoundFile(String^ path)
{
	pin_ptr<unsigned char> _path = &Encoding::Default->GetBytes(path)[0];

	SF_INFO _info;
	handle = sf_open ((const char*)_path, SFM_READ, &_info);

	if (handle == NULL)
		throw gcnew Exception();

	info = new SF_INFO();
	*info = _info;
}

SoundFile::~SoundFile()
{
	sf_close(handle);
	delete info;
}

long SoundFile::Frames::get()
{
	return info->frames;
}

int SoundFile::Samplerate::get()
{
	return info->samplerate;
}

int SoundFile::Channels::get()
{
	return info->channels;
}

array<double>^ SoundFile::ReadDouble(int size)
{
	array<double>^ buffer = gcnew array<double>(size*info->channels);
	pin_ptr<double> _buffer = &buffer[0];
	sf_readf_double(handle, _buffer, size);

	return buffer;
}
