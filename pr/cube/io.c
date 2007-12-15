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
	int i, param_count = 3;
	int count = *((int*) get_param(++param_count));

	out = (Channel**) malloc(count * sizeof(Channel*));
	for (i = 0; i < count; ++i)
		out[i] = (Channel *) get_param(++param_count);

	return count;
}

int** init_memory(int from, int to, int phases, int channel)
{
	int i;
	int** data = (int**) malloc(phases * sizeof(int*));
	for (i = 0; i < phases; ++i)
	{
		data[i] = (int*) malloc(sizes[from][to][i][channel] * sizeof(int));
	}
	return data;
}

int main()
{
	Channel** out = NULL;

	int proc = *((int*) get_param(3));
	int out_count = init_channels(out);
	int phase = phase_count;
	int** data;

	printf("Initializing memory...\n");
	data = init_memory(proc, proc, phase_count, 0);
	
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
			ChanOut(out[i], &info, sizeof(struct packet_info));
			shift += info.size;
		}
		printf("Phase %d finished.\n", phase);
	}

	free(out);

	printf("Terminating...\n");
	exit_terminate(0);

	return 0;
}

