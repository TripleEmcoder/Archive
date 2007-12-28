#pragma once

#include <libsndfile.h>

namespace Bridge
{
	public ref class SoundFile
	{
	public:
		SoundFile(System::String^ path);
		~SoundFile();

		property long Frames 
		{ 
			long get();
		};

		property int Samplerate 
		{ 
			int get();
		};

		property int Channels 
		{ 
			int get();
		};

		array<double>^ ReadDouble(int size);

	private:
		SF_INFO* info;
		SNDFILE* handle;
	};
}
