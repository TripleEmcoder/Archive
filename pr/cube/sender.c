/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process1.h>
#include <channel.h>
#include <misc.h>
#include <memory.h>
#include "config.h"

int init_channels(Channel** in, Channel* out)
{
	int i, param_count = 2;
	int count = *((int*) get_param(++param_count));

	in = malloc(count * sizeof(Channel*));
	for (i = 0; i < count; ++i)
		in[i] = (Channel *) get_param(++param_count);

	out = (Channel*) get_param(++param_count);
	
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
	Channel** in = NULL;
	Channel* out = NULL;

	int from = *((int*) get_param(1));
	int to   = *((int*) get_param(2));
	int in_count = init_channels(in, out);
	int phase = phase_count;
	struct packet_info* info = malloc(in_count * sizeof(struct packet_info));

	int** data = init_memory(from, to, phase_count, in_count);
	
	while (phase--)
	{
		int i, shift = 0;

		for (i = 0; i < in_count; ++i)
		{
			int active = ProcAltList(in);
			ChanIn(in[active], &info[active], sizeof(struct packet_info));
		}

		for (i = 0; i < in_count; ++i)
		{
			memcpy(data[phase] + shift, info[i].ptr, info[i].size * sizeof(int));
			shift += info[i].size;
		}

		ChanOut(out, data[phase], shift * sizeof(int));
	}

	
	free(in);
	return 0;
}
