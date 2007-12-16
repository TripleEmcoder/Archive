/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <stdio.h>
#include <process.h>
#include <channel.h>
#include <misc.h>
#include <stdlib.h>
#include "config.h"

int** init_memory(int from, int to, int phases, int channel)
{
	int i;
	int** data;

	printf("Initializing memory...\n");
	
	data = (int**) malloc(phases * sizeof(int*));
	for (i = 0; i < phases; ++i)
	{
		data[i] = (int*) malloc(sizes[from][to][i][channel] * sizeof(int));
		printf("Allocated %d at %p for phase %d.", sizes[from][to][i][channel], data[i], i);
	}
	
	printf("Memory initialization finished.\n");
	return data;
}

int main()
{
	int from = *((int*) get_param(1));
	int to   = *((int*) get_param(2));
	int out_count = *((int*) get_param(3));
	Channel* in = (Channel*) get_param(4);
	Channel** out = init_channels(out_count, 4);
	Channel** debug_in = init_channels(out_count, 4 + out_count);
	Channel* debug_out = (Channel*) get_param(5 + 2 * out_count);
	
	int** data = init_memory(from, to, phase_count, 0);
	struct time_info* times;
	int* count = (int*) malloc(out_count * sizeof(int));
	int* local_times = (int*) malloc(phase_count * sizeof(int));
	int shift, k;
	int phase = phase_count;
	

	printf("Processing...\n");
	while (phase--)
	{
		int i, start, end;
		printf("Phase %d...\n", phase);

		start = ProcTime();
		ChanIn(in, data[phase], sizes[from][to][phase][0] * sizeof(int));
		end = ProcTime();

		printf("Received data, size: %d, addr: %p.\n", sizes[from][to][phase][0], data[phase]);

		local_times[phase] = ProcTimeMinus(end, start);
		
		shift = 0;
		for (i = 0; i < out_count; ++i)
		{
			struct packet_info info;
			info.ptr = data[phase] + shift;
			info.size = sizes[from][to][phase][i+1];
			printf("Sending info: (%p, %d)\n", info.ptr, info.size);
			ChanOut(out[i], &info, sizeof(struct packet_info));
			printf("Sent.\n");
			shift += info.size;
		}
		printf("Phase %d finished.\n", phase);
	}

	shift = 0;
	for (k = 0; k < out_count; ++k)
	{
		count[k] = ChanInInt(debug_in[k]);
		shift += count[k];
	}

	times = (struct time_info*) malloc((shift + phase_count) * sizeof(struct time_info));

	for (k = 0; k < phase_count; ++k)
	{
		times[shift + k] = get_time_info(from, to, k, local_times[k]);
	}

	shift = 0;
	for (k = 0; k < out_count; ++k)
	{
		ChanIn(debug_in[k], times + shift, count[k] * sizeof(struct time_info));
		shift += count[k];
	}

	ChanOutInt(debug_out, (shift + phase_count));
	ChanOut(debug_out, times, (shift + phase_count) * sizeof(struct time_info));

	free(out);
	free(debug_in);
	free(local_times);
	free(times);
	return 0;
}
