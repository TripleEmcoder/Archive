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

	ChanOutInt(out, 0);

	for (i = 0; i < count; ++i) 
	{
		int* data = (int*) malloc(size * sizeof(int));
		ChanIn(in, data, size * sizeof(int));
		ChanOut(out, data, size * sizeof(int));
		free(data);
		size += step;
	}
}

int process(int x, int order)
{
	int result = 0;
	int i;
	for (i = 0; i < order; ++i)
	{
		int temp = 1;
		int j;
		for (j = 0; j < i; ++j)
			temp *= x;
		result += temp;
	}
	return result;
		
}

void test_proc(Channel* in, Channel* out)
{
	int count;
	int size;
	int step;
	int order;
	int i;
	
	count = ChanInInt(in);
	size = ChanInInt(in);
	step = ChanInInt(in);
	order = ChanInInt(in);

	for (i = 0; i < count; ++i) 
	{
		int* data = (int*) malloc(size * sizeof(int));
		int start, end, j;

		ChanIn(in, data, size * sizeof(int));
		
		start = ProcTime();
		
		for (j = 0; j < size; ++j)
			process(data[j], order);

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
	/*test_proc(in, out);*/
	
	return 0;
}
