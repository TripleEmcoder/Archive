/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <stdio.h>
#include <process.h>
#include <channel.h>
#include <misc.h>
#include <stdlib.h>
#include <string.h>

void test_link(Channel* out, Channel* in, int count, int size, int step)
{
	int i;
	int* sizes = (int*) malloc(count * sizeof(int));
	int* times = (int*) malloc(count * sizeof(int));
	int* data;
	
	ChanOutInt(out, count);
	ChanOutInt(out, size);
	ChanOutInt(out, step);

	ChanInInt(in);
	ChanInInt(in);
	ChanInInt(in);

	data = (int*) malloc((size + count * step) * sizeof(int));
	
	for (i = 0; i < count; ++i)   
	{
		int start;
		int end;
		
		start = ProcTime();
	
		ChanOut(out, data, size * sizeof(int));
		ChanIn(in, data, size * sizeof(int));
		
		end = ProcTime();

		sizes[i] = size;
		times[i] = ProcTimeMinus(end, start);
				
		size += step;
	}
	
	for (i = 0; i < count; ++i)
	{
		printf("%d,%d\n", sizes[i], times[i]);
	}

	free(data);
	free(times);
	free(sizes);

}

void test_proc(Channel* out, Channel* in, int count, int size, int step)
{
	int i;
	int* sizes = (int*) malloc(count * sizeof(int));
	int* times = (int*) malloc(count * sizeof(int));
	
	ChanOutInt(out, count);
	ChanOutInt(out, size);
	ChanOutInt(out, step);
	
	for (i = 0; i < count; ++i)   
	{
		int* data = (int*) malloc(size * sizeof(int));
		memset(data, 2, size);
		
		ChanOut(out, data, size * sizeof(int));
		
		sizes[i] = size;
		times[i] = ChanInInt(in);
				
		free(data);
		
		size += step;
	}
	
	for (i = 0; i < count; ++i)
	{
		printf("%d,%d\n", sizes[i], times[i]);
	}

	free(times);
	free(sizes);
}

int main(int argc, char** argv)
{
	Channel*  KANAL2WY;
	Channel*  KANAL3WE;
	Channel*  KANAL4WY;
	Channel*  KANAL5WE;
	
	int count = atoi(argv[1]);
	int size = atoi(argv[2]);
	int step = atoi(argv[3]);

	KANAL2WY   = (Channel *)  get_param (3);
	KANAL3WE   = (Channel *)  get_param (4);
	KANAL4WY   = (Channel *)  get_param (5);
	KANAL5WE   = (Channel *)  get_param (6);

	/*printf("Testing fast link...\n");
	test_link(KANAL2WY, KANAL3WE, count, size, step);
	printf("Test finished.\n");

	printf("Testing slow link...\n");
	test_link(KANAL4WY, KANAL5WE, count, size, step);
	printf("Test finished.\n");*/

	printf("Testing fast proc...\n");
	test_proc(KANAL4WY, KANAL5WE, count, size, step);
	printf("Test finished.\n");

	printf("Testing slow proc...\n");
	test_proc(KANAL2WY, KANAL3WE, count, size, step);
	printf("Test finished.\n");

	exit_terminate (0);
	return 0;
}
