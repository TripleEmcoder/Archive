#pragma once

#include <libfftw.h>

namespace Bridge
{
	public ref class FastFourierTransform
	{
	public:
		FastFourierTransform(int size);
		~FastFourierTransform();

		array<Types::Complex>^ Calculate (array<double>^ input);

	private:
		int size;
		double* _input;
		fftw_complex* _output;
		fftw_plan plan;
	};
}
