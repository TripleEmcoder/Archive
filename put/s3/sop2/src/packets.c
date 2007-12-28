#include "packets.h"
#include "protocol.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

void send_packet(int qid, int type, int subtype, void* data, int size)
{
	//fprintf(stderr, "send_packet(%d, %d)\n", type, subtype);

	struct packet_common packet;
	packet.type = type;
	packet.subtype = subtype;
	
	memcpy(&packet.data, data, size);
	
	if (msgsnd(qid, &packet, MAX_PACKET, IPC_NOWAIT) == -1)
		write_output("%s.\n", strerror(errno));
}
