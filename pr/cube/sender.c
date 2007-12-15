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
	int in_count = *((int*) get_param(3));
	Channel** in = init_channels(in_count, 3);
	Channel* out = (Channel*) get_param(4 + in_count);
	int phase = phase_count;

	struct packet_info* info = (struct packet_info*) malloc(in_count * sizeof(struct packet_info));

	int** data = init_memory(from, to, phase_count, 0);
	
	printf("Processing...\n");
	while (phase--)
	{
		int i, shift = 0;
		printf("Phase %d...\n", phase);
		
		for (i = 0; i < in_count; ++i)
		{
			/*int active = ProcAltList(in);
			ChanIn(in[active], &info[active], sizeof(struct packet_info));*/
			printf("Receiving to channel %p...\n", in[i]);
			ChanIn(in[i], &(info[i]), sizeof(struct packet_info));
			printf("Received info: (%p, %d)\n", info[i].ptr, info[i].size);
		}

		for (i = 0; i < in_count; ++i)
		{
			memcpy(data[phase] + shift, info[i].ptr, info[i].size * sizeof(int));
			shift += info[i].size;
		}

		ChanOut(out, data[phase], shift * sizeof(int));
		printf("Phase %d finished.\n", phase);
	}

	
	free(in);
	return 0;
}
