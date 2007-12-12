/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <stdio.h>
#include <process.h>
#include <channel.h>
#include <misc.h>
#include "config.h"

int init_channels(Channel** out)
{
	int i, param_count = 1;
	int count = *((int*) get_param(++param_count));

	out = malloc(count * sizeof(Channel*));
	for (i = 0; i < count; ++i)
		out[i] = (Channel *) get_param(++param_count);

	return count;
}

int** init_memory(int from, int to, int phases, int channel)
{
	int i;
	int** data = malloc(phases * sizeof(int*));
	for (i = 0; i < phases; ++i)
	{
		data[i] = malloc(sizes[from][to][i][channel] * sizeof(int));
	}
	return data;
}

int main()
{
	Channel** out = NULL;

	int proc = *((int*) get_param(1));
	int out_count = init_channels(out);
	int phase = phase_count;

	int** data = init_memory(proc, proc, phase_count, 0);
	
	while (phase--)
	{
		int i, shift = 0;
		for (i = 0; i < out_count; ++i)
		{
			struct packet_info info;
			info.ptr = data[phase] + shift;
			info.size = sizes[proc][proc][phase][i+2];
			ChanOut(out[i], &info, sizeof(struct packet_info));
			shift += info.size;
		}
	}

	free(out);

	exit_terminate(0);

	return 0;
}

