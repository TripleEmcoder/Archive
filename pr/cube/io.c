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

int init_channels(Channel** out)
{
	int i, param_count = 3, count;

	printf("Initializing channels...\n");
	
	count = *((int*) get_param(++param_count));

	out = (Channel**) malloc(count * sizeof(Channel*));
	for (i = 0; i < count; ++i)
		out[i] = (Channel *) get_param(++param_count);

	printf("%d channels initialized.\n", count);
	return count;
}

int** init_memory(int from, int to, int phases, int channel)
{
	int i, j;
	int** data;

	printf("Initializing memory...\n");
	
	data = (int**) malloc(phases * sizeof(int*));
	for (i = 0; i < phases; ++i)
	{
		int size = 0;
		for (j = 0; j < channel; ++j)
			size += sizes[from][to][i][j];
		data[i] = (int*) malloc(size * sizeof(int));
		printf("Allocated %d at %p for phase %d.", size, data[i], i);
	}
	
	printf("Memory initialization finished.\n");
	return data;
}

int main()
{
	Channel** out = NULL;

	int proc = *((int*) get_param(3));
	int out_count = init_channels(out);
	int phase = phase_count;
	int** data = init_memory(proc, proc, phase_count, out_count);
	
	printf("Processing...\n");
	while (phase--)
	{
		int i, shift = 0;
		printf("Phase %d...\n", phase);
		for (i = 0; i < out_count; ++i)
		{
			struct packet_info info;
			info.ptr = data[phase] + shift;
			info.size = sizes[proc][proc][phase][i];
			printf("Sending info: (%p, %d)\n", info.ptr, info.size);
			ChanOut(out[i], &info, sizeof(struct packet_info));
			printf("Sent.\n");
			shift += info.size;
		}
		printf("Phase %d finished.\n", phase);
	}

	free(out);

	printf("Terminating...\n");
	exit_terminate(0);

	return 0;
}

