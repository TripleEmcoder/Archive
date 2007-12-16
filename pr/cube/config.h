#include "sizes.h"

struct packet_info {
	int* ptr;
	int size;
};

struct time_info {
	int from, to, phase, time;
};

int phase_count = 3;

Channel** init_channels(int count, int param_count)
{
	Channel** result = (Channel**) (Channel**) malloc(count * sizeof(Channel*));
	int i;
	for (i = 0; i < count; ++i)
	{
		result[i] = (Channel *) get_param(++param_count);
		/*if (result[i] == NULL)
			printf("Channel at %d not initialized!!!\n", param_count);*/
	}
	return result;
}

struct time_info get_time_info(int from, int to, int phase, int time)
{
	struct time_info info;
	info.from = from;
	info.to = to;
	info.phase = phase;
	info.time = time;
	return info;
}
