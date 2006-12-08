#include "notifies.h"
#include "packets.h"
#include "protocol.h"
#include <string.h>
#include <stdio.h>

void send_notify(int queue, int subtype, void* data, int size)
{
	send_packet(queue, NOTIFY_TYPE, subtype, data, size);	
}

void send_private_notify(int queue, int sender, const char* message)
{
	printf("private_notify(%d, %d, \"%s\")\n",
		queue, sender, message);

	private_notify notify;
	notify.sender = sender;
	strncpy((char*)&notify.message, message, MAX_MESSAGE+1);
	send_notify(queue, PRIVATE_SUBTYPE, &notify, sizeof(notify));
}


void send_group_notify(int queue, int sender, const char* group, const char* message)
{
	printf("group_notify(%d, %d, \"%s\", \"%s\")\n", 
		queue, sender, group, message);

	group_notify notify;
	notify.sender = sender;
	strncpy((char*)&notify.group, group, MAX_GROUP+1);
	strncpy((char*)&notify.message, message, MAX_MESSAGE+1);
	send_notify(queue, GROUP_SUBTYPE, &notify, sizeof(notify));
}