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

int init_channels(Channel** in)
{
	int i, param_count = 1;
	int count = *((int*) get_param(++param_count));

	in = (Channel**) malloc(count * sizeof(Channel*));
	for (i = 0; i < count; ++i)
		in[i] = (Channel *) get_param(++param_count);

	return count;
}

void process(int x)
{
	return;	
}

int main()
{
	Channel** in = NULL;

	int proc = *((int*) get_param(1));
	int in_count = init_channels(in);
	int phase = phase_count;
	struct packet_info* info = (struct packet_info*) malloc(in_count * sizeof(struct packet_info));
	
	while (phase--)
	{
		int i, j;
		
		for (i = 0; i < in_count; ++i)
		{
			/*int active = ProcAltList(in);
			ChanIn(in[active], &info[active], sizeof(struct packet_info));*/
			ChanIn(in[i], &info[i], sizeof(struct packet_info));
		}

		for (i = 0; i < in_count; ++i)
		{
			for (j = 0; j < info[i].size; ++j)
				process(*(info[i].ptr + j));
		}
	}

	free(in);
	return 0;
}
