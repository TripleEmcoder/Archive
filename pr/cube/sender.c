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

int init_channels(Channel** in, Channel* out)
{
	int i, param_count = 2, count;

	printf("Initializing channels...\n");
	
	count = *((int*) get_param(++param_count));

	in = (Channel**) malloc(count * sizeof(Channel*));
	for (i = 0; i < count; ++i)
		in[i] = (Channel *) get_param(++param_count);

	out = (Channel*) get_param(++param_count);
	
	printf("%d channels initialized.\n", count);
	return count;
}

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
	Channel** in = NULL;
	Channel* out = NULL;

	int from = *((int*) get_param(1));
	int to   = *((int*) get_param(2));
	int in_count = init_channels(in, out);
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
			printf("Receiving to %p...\n", &(info[i]));
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
