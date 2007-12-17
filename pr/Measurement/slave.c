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
	int* data;
	
	count = ChanInInt(in);
	size = ChanInInt(in);
	step = ChanInInt(in);

	ChanOutInt(out, 0);
	ChanOutInt(out, 0);
	ChanOutInt(out, 0);

	data = (int*) malloc((size + count * step) * sizeof(int));

	for (i = 0; i < count; ++i) 
	{
		ChanIn(in, data, size * sizeof(int));
		ChanOut(out, data, size * sizeof(int));
		size += step;
	}
	free(data);
}

int process(int x)
{
	return 
		-9*x*x*x*x*x*x*x*x*x 
		+8*x*x*x*x*x*x*x*x 
		-7*x*x*x*x*x*x*x
		-6*x*x*x*x*x*x 
		-5*x*x*x*x*x* 
		+4*x*x*x*x 
		-3*x*x*x;
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

		ChanIn(in, data, size * sizeof(int));
		
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

	/*test_link(in, out);*/
	test_proc(in, out);
	
	return 0;
}
