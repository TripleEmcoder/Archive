#include "FastFourierTransform.h"

using namespace Bridge;
using namespace Types;

using namespace System;

FastFourierTransform::FastFourierTransform(int size)
{
	this->size = size;

	_input = (double*) fftw_malloc(sizeof(double) * size);
	_output = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * size);

	plan = fftw_plan_dft_r2c_1d(size, _input, _output, 
		FFTW_DESTROY_INPUT | FFTW_MEASURE);
}

FastFourierTransform::~FastFourierTransform()
{
	fftw_destroy_plan(plan);
	fftw_free(_input);
	fftw_free(_output);
}

array<Types::Complex>^ FastFourierTransform::Calculate (array<double>^ input)
{
	if (input->Length != size)
		throw gcnew ArgumentOutOfRangeException();

	for (int i=0; i<size; i++)
		_input[i] = input[i];

	fftw_execute(plan);

	array<Complex>^ output = gcnew array<Complex>(size);

	for (int i=0; i<size; i++)
	{
		output[i].Real = _output[i][0];
		output[i].Imaginary = _output[i][1];
	}

	return output;
}
