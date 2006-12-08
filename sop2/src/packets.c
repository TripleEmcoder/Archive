#include "packets.h"
#include "protocol.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

void send_packet(int queue, int type, int subtype, void* data, int size)
{
	//printf("PACKET: %d %d\n", type, subtype);

	packet_common packet;
	packet.type = type;
	packet.subtype = subtype;
	
	memcpy(&packet.data, data, size);
	
	if (msgsnd(queue, &packet, MAX_PACKET, 0) == -1)
		printf("%s\n", strerror(errno));
}
