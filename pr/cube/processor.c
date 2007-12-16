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

void process(int x)
{
	return;	
}

int main()
{
	int proc = *((int*) get_param(1));
	int in_count = *((int*) get_param(2));
	Channel** in = init_channels(in_count, 2);
	Channel** debug = init_channels(in_count, 2 + in_count);
	int phase = phase_count;
	struct packet_info* info = (struct packet_info*) malloc(in_count * sizeof(struct packet_info));
	struct time_info* times = (struct time_info*) malloc(phase_count * sizeof(struct time_info));
	int k;
	
	printf("Processing...\n");
	while (phase--)
	{
		int i, j, start, end;
		printf("Phase %d...\n", phase);
				
		for (i = 0; i < in_count; ++i)
		{
			/*int active = ProcAltList(in);
			ChanIn(in[active], &info[active], sizeof(struct packet_info));*/
			ChanIn(in[i], &(info[i]), sizeof(struct packet_info));
			printf("Received info: (%p, %d)\n", info[i].ptr, info[i].size);
		}

		start = ProcTime();
		for (i = 0; i < in_count; ++i)
		{
			for (j = 0; j < info[i].size; ++j)
				process(*(info[i].ptr + j));
		}
		end = ProcTime();
		
		times[phase] = get_time_info(proc, proc, phase, ProcTimeMinus(end, start));

		printf("Phase %d finished.\n", phase);
	}

	for (k = 0; k < in_count; ++k)
	{
		ChanOutInt(debug[k], phase_count);
		ChanOut(debug[k], times, phase_count * sizeof(struct time_info));
	}
	
	free(in);
	free(debug);
	free(times);
	free(info);
	return 0;
}
