#include "replies.h"
#include "packets.h"
#include "protocol.h"
#include "windows.h"
#include <string.h>
#include <stdio.h>

void send_reply(int qid, int subtype, void* data, int size)
{
	send_packet(qid, REPLY_TYPE, subtype, data, size);	
}

void send_groups_reply(int qid, int count, 
	const char groups[MAX_GROUPS][MAX_GROUP+1])
{
	write_debug_output("groups_reply(%d, %d, ...)\n", qid, count);

	struct groups_reply reply;
	reply.count = count;
	memcpy(reply.groups, groups, MAX_GROUPS*(MAX_GROUP+1));
	send_notify(qid, GROUPS_SUBTYPE, &reply, sizeof(reply));
}

void send_users_reply(int qid, const char* group, int count,
	const char nicks[MAX_NICKS][MAX_NICK+1])
{
	write_debug_output("users_reply(%d, \"%s\", %d, ...)\n", qid, group, count);

	struct users_reply reply;
	strncpy((char*)reply.group, group, MAX_NICK+1);
	reply.count = count;
	memcpy(reply.nicks, nicks, MAX_NICKS*(MAX_NICK+1));
	send_notify(qid, USERS_SUBTYPE, &reply, sizeof(reply));
}
