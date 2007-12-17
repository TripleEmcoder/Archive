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

int process(int x)
{
	return 
		-9*x*x*x*x*x*x*x*x*x 
		+8*x*x*x*x*x*x*x*x 
		-7*x*x*x*x*x*x*x
		-6*x*x*x*x*x*x 
		-5*x*x*x*x*x* 
		+4*x*x*x*x 
		-3*x*x*x;
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
	int k, i;
	int base_time, base_time2 = 0;

	for (i = 0; i < in_count; ++i)
		ChanInInt(in[i]);

#ifdef SYNC

	for (i = 0; i < in_count; ++i)
		base_time = ChanInInt(in[i]);

	base_time2 = ProcTime() - base_time;

#endif

	/*printf("Processing...\n");*/
	while (phase--)
	{
		int j, start, end;
		/*printf("Phase %d...\n", phase);*/
				
		for (i = 0; i < in_count; ++i)
		{
			/*int active = ProcAltList(in);
			ChanIn(in[active], &info[active], sizeof(struct packet_info));*/
			ChanIn(in[i], &(info[i]), sizeof(struct packet_info));
			/*printf("Received info: (%p, %d)\n", info[i].ptr, info[i].size);*/
		}

		start = ProcTime()*64 - base_time2;
		for (i = 0; i < in_count; ++i)
		{
			for (j = 0; j < info[i].size; ++j)
				process(*(info[i].ptr + j));
		}
		end = ProcTime()*64 - base_time2;
		
		times[phase] = get_time_info(proc, proc, phase, start, end);

		/*printf("Phase %d finished.\n", phase);*/
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
