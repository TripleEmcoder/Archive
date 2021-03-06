/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <channel.h>
#include <misc.h>
#include "config.h"

int** init_memory(int from, int to, int phases, int channel)
{
	int i, j;
	int** data;

	/*printf("Initializing memory...\n");*/
	
	data = (int**) malloc(phases * sizeof(int*));
	for (i = 0; i < phases; ++i)
	{
		int size = 0;
		for (j = 0; j < channel; ++j)
			size += sizes[from][to][i][j];
		data[i] = (int*) malloc(size * sizeof(int));
		/*printf("Allocated %d at %p for phase %d.\n", size, data[i], i);*/
	}
	
	/*printf("Memory initialization finished.\n");*/
	return data;
}

int main()
{
	int proc = *((int*) get_param(3));
	int out_count = *((int*) get_param(4));
	Channel** out = init_channels(out_count, 4);
	Channel* debug_in = (Channel*) get_param(5 + out_count);
	int** data = init_memory(proc, proc, phase_count, out_count);
	struct time_info* times;
	int count, k, phase, i;
	int base_time;

	ChanOutInt(out[out_count-1], 1);

	for (i = 0; i < out_count-1; ++i)
		ChanOutInt(out[i], 1);

	base_time = ProcTime();

#ifdef SYNC

	ChanOutInt(out[out_count-1], base_time);

	for (i = 0; i < out_count-1; ++i)
		ChanOutInt(out[i], base_time);

#endif

	for(k = 1; k < phase_count; ++k)
	{
		sizes[proc][proc][0][out_count-1] += sizes[proc][proc][k][out_count-1];
		sizes[proc][proc][k][out_count-1] = 0;
	}

	/*printf("Local processing...\n");*/
	phase = phase_count;
	while (phase--)
	{
		struct packet_info info;

		info.ptr = data[phase];
		info.size = sizes[proc][proc][phase][out_count-1];
			
		/*printf("%d: Sending info: (%p, %d)\n", ProcTime(), info.ptr, info.size, out[out_count-1]);*/
		ChanOut(out[out_count-1], &info, sizeof(struct packet_info));
		/*printf("%d: Sent.\n", ProcTime());*/
		
	}
	
	/*printf("Sending...\n");*/
	phase = phase_count;
	while (phase--)
	{
		int shift = 0;
		/*printf("Phase %d...\n", phase);*/
		for (i = 0; i < out_count-1; ++i)
		{
			struct packet_info info;
			info.ptr = data[phase] + shift;
			info.size = sizes[proc][proc][phase][i];
			/*printf("%d: Sending info: (%p, %d)\n", ProcTime(), info.ptr, info.size, out[i]);*/
			ChanOut(out[i], &info, sizeof(struct packet_info));
			/*printf("%d: Sent.\n", ProcTime());*/
			shift += info.size;
		}
		/*printf("Phase %d finished.\n", phase);*/
	}

	free(out);

	count = ChanInInt(debug_in);
	printf("Received %d\n", count);
	times = (struct time_info*) malloc(count * sizeof(struct time_info));
	ChanIn(debug_in, times, count * sizeof(struct time_info));

	printf("Times:\n");
	for (k = 0; k < count; ++k)
	{
		printf("%d %d %d %d %d\n", times[k].from, times[k].to, times[k].phase, times[k].start, times[k].end);
	}

	printf("Terminating...\n");
	exit_terminate(0);

	return 0;
}

