#include "notifies.h"
#include "packets.h"
#include "protocol.h"
#include "windows.h"
#include <string.h>
#include <stdio.h>

void send_notify(int qid, int subtype, void* data, int size)
{
	send_packet(qid, NOTIFY_TYPE, subtype, data, size);	
}

void send_private_notify(int qid, const char* nick, const char* message)
{
	write_debug_output("private_notify(%d, \"%s\", \"%s\")\n",
		qid, nick, message);

	struct private_notify notify;
	strncpy((char*)&notify.nick, nick, MAX_NICK+1);
	strncpy((char*)&notify.message, message, MAX_MESSAGE+1);
	send_notify(qid, PRIVATE_SUBTYPE, &notify, sizeof(notify));
}


void send_group_notify(int queue, const char* nick, const char* group, const char* message)
{
	write_debug_output("group_notify(%d, \"%s\", \"%s\", \"%s\")\n", 
		queue, nick, group, message);

	struct group_notify notify;
	strncpy((char*)&notify.nick, nick, MAX_NICK+1);
	strncpy((char*)&notify.group, group, MAX_GROUP+1);
	strncpy((char*)&notify.message, message, MAX_MESSAGE+1);
	send_notify(queue, GROUP_SUBTYPE, &notify, sizeof(notify));
}
