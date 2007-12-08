/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>
#include <stdlib.h>

void test_link(Channel* in, Channel* out)
{
	int count;
	int size;
	int step;
	int i;
	
	count = ChanInInt(in);
	size = ChanInInt(in);
	step = ChanInInt(in);

	for (i = 0; i < count; ++i) 
	{
		int* data = (int*) malloc(size * sizeof(int));
		ChanIn(in, data, size);
		ChanOut(out, data, size);
		free(data);
		size += step;
	}
}

int process(int x)
{
	return 6*x*x*x*x*x*x + 4*x*x*x*x + 2*x*x;
}

void test_proc(Channel* in, Channel* out)
{
	int count;
	int size;
	int step;
	int i;
	
	count = ChanInInt(in);
	size = ChanInInt(in);
	step = ChanInInt(in);

	for (i = 0; i < count; ++i) 
	{
		int* data = (int*) malloc(size * sizeof(int));
		int start, end, j;

		ChanIn(in, data, size);
		
		start = ProcTime();
		
		for (j = 0; j < size; ++j)
			process(data[j]);

		end = ProcTime();

		ChanOutInt(out, ProcTimeMinus(end, start));
		
		free(data);
		size += step;
	}
}

int main()
{
	Channel*  in;
	Channel*  out;
	
	in   = (Channel *)  get_param (1);
	out   = (Channel *)  get_param (2);

	test_link(in, out);
	test_proc(in, out);
	
	return 0;
}
