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
#include "config.h"

int** init_memory(int from, int to, int phases, int channel)
{
	int i;
	int** data;

	/*printf("Initializing memory...\n");*/
	
	data = (int**) malloc(phases * sizeof(int*));
	for (i = 0; i < phases; ++i)
	{
		data[i] = (int*) malloc(sizes[from][to][i][channel] * sizeof(int));
		/*printf("Allocated %d at %p for phase %d.", sizes[from][to][i][channel], data[i], i);*/
	}
	/*printf("Memory initialization finished.\n");*/
	return data;
}

int main()
{
	int from = *((int*) get_param(1));
	int to   = *((int*) get_param(2));
	int in_count = *((int*) get_param(3));
	Channel** in = init_channels(in_count, 3);
	Channel* out = (Channel*) get_param(4 + in_count);
	Channel* debug_in = (Channel*) get_param(5 + in_count);
	Channel** debug_out = init_channels(in_count, 5 + in_count);
	int phase = phase_count;
	int count, k, i;

	struct packet_info* info = (struct packet_info*) malloc(in_count * sizeof(struct packet_info));

	int** data = init_memory(from, to, phase_count, 0);
	struct time_info* times;
	int* local_times = (int*) malloc(2 * phase_count * sizeof(int));
	int base_time, base_time2 = 0;

	for (i = 0; i < in_count; ++i)
		ChanInInt(in[i]);

	ChanOutInt(out, 1);

#ifdef SYNC

	for (i = 0; i < in_count; ++i)
		base_time = ChanInInt(in[i]);

	base_time2 = ProcTime() - base_time;

	ChanOutInt(out, base_time);
	
#endif
	
	/*printf("Processing...\n");*/
	while (phase--)
	{
		int shift = 0, start, end;
		/*printf("Phase %d...\n", phase);*/

		for (i = 0; i < in_count; ++i)
		{
			/*int active = ProcAltList(in);
			ChanIn(in[active], &info[active], sizeof(struct packet_info));*/
			ChanIn(in[i], &(info[i]), sizeof(struct packet_info));
			/*printf("Received info: (%p, %d)\n", info[i].ptr, info[i].size);*/
		}

		for (i = 0; i < in_count; ++i)
		{
			memcpy(data[phase] + shift, info[i].ptr, info[i].size * sizeof(int));
			shift += info[i].size;
		}

		/*printf("Sending %d...\n", shift);*/
		start = ProcTime() - base_time2;
		ChanOut(out, data[phase], shift * sizeof(int));
		end = ProcTime() - base_time2;
		/*printf("Phase %d finished.\n", phase);*/

		local_times[2 * phase] = start;
		local_times[2 * phase + 1] = end;
	}

	count = ChanInInt(debug_in);

	times = (struct time_info*) malloc((count + phase_count) * sizeof(struct time_info));

	ChanIn(debug_in, times, count * sizeof(struct time_info));

	for (k = 0; k < phase_count; ++k)
	{
		times[count + k] = get_time_info(from, to, k, local_times[2*k], local_times[2*k+1]);
	}

	for (k = 0; k < in_count; ++k)
	{
		ChanOutInt(debug_out[k], count + phase_count);
		ChanOut(debug_out[k], times, (count + phase_count) * sizeof(struct time_info));
	}

	free(local_times);
	free(times);
	free(debug_out);
	free(in);
	return 0;
}
