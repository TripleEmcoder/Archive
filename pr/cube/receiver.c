/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process1.h>
#include <channel.h>
#include <misc.h>
#include <memory.h>
#include "config.h"

int init_channels(Channel* in, Channel** out)
{
	int i, param_count = 2;
	int count = *((int*) get_param(++param_count));

	in = (Channel*) get_param(++param_count);
	
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
	Channel* in = NULL;
	Channel** out = NULL;

	int from = *((int*) get_param(1));
	int to   = *((int*) get_param(2));
	int out_count = init_channels(in, out);
	int phase = phase_count;

	int** data = init_memory(from, to, phase_count, 0);

	while (phase--)
	{
		int i, shift = 0;

		ChanIn(in, data[phase], sizes[from][to][phase][0] * sizeof(int));
		
		for (i = 0; i < out_count; ++i)
		{
			struct packet_info info;
			info.ptr = data[phase] + shift;
			info.size = sizes[from][to][phase][i+1];
			ChanOut(out[i], &info, sizeof(struct packet_info));
			shift += info.size;
		}
	}

	free(out);
	return 0;
}
