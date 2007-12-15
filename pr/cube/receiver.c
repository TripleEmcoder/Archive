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
	int phase = phase_count;

	int** data = init_memory(from, to, phase_count, 0);

	printf("Processing...\n");
	while (phase--)
	{
		int i, shift = 0;
		printf("Phase %d...\n", phase);

		printf("Receiving %d to %p...\n", sizes[from][to][phase][0], data[phase]);
		ChanIn(in, data[phase], sizes[from][to][phase][0] * sizeof(int));
		
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

	free(out);
	return 0;
}
