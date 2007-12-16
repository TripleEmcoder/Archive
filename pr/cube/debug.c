/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>
#include <stdlib.h>
#include "config.h"

int main()
{
	int in_count = *((int*) get_param(1));
	Channel** debug_in = init_channels(in_count, 1);
	Channel* debug_out = (Channel*) get_param(2 + in_count);
	int k, shift;
	int* count = (int*) malloc(in_count * sizeof(int));
	struct time_info* times;

	shift = 0;
	for (k = 0; k < in_count; ++k)
	{
		count[k] = ChanInInt(debug_in[k]);
		shift += count[k];
	}

	times = (struct time_info*) malloc(shift * sizeof(struct time_info));

	shift = 0;
	for (k = 0; k < in_count; ++k)
	{
		ChanIn(debug_in[k], times + shift, count[k] * sizeof(struct time_info));
		shift += count[k];
	}

	ChanOutInt(debug_out, shift);
	ChanOut(debug_out, times, shift * sizeof(struct time_info));

	free(times);
	free(count);
	free(debug_in);

	return 0;
}
