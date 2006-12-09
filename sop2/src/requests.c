#include "requests.h"
#include "packets.h"
#include "protocol.h"
#include <string.h>
#include <stdio.h>

void send_request(int qid, int subtype, void* data, int size)
{
	send_packet(qid, REQUEST_TYPE, subtype, data, size);
}

void send_login_request(int qid, pid_t pid)
{
	fprintf(stderr, "login_request(%d, %d)\n", qid, pid);

	struct login_request request;
	request.pid = pid;
	send_request(qid, LOGIN_SUBTYPE, &request, sizeof(request));
}

void send_logout_request(int qid)
{
	fprintf(stderr, "login_request(%d)\n", qid);

	struct logout_request request;
	send_request(qid, LOGOUT_SUBTYPE, &request, sizeof(request));
}

void send_nick_request(int qid, const char* nick)
{
	fprintf(stderr, "nick_request(%d, \"%s\")\n", qid, nick);

	struct nick_request request;
	strncpy((char*)&request.nick, nick, MAX_NICK+1);
	send_request(qid, NICK_SUBTYPE, &request, sizeof(request));
}

void send_groups_request(int qid)
{
	fprintf(stderr, "groups_request(%d)\n", qid);

	struct groups_request request;
	send_request(qid, GROUPS_SUBTYPE, &request, sizeof(request));
}

void send_join_request(int qid, const char* group)
{
	fprintf(stderr, "join_request(%d, \"%s\")\n", qid, group);
	
	struct join_request request;
	strncpy((char*)&request.group, group, MAX_GROUP+1);
	send_request(qid, JOIN_SUBTYPE, &request, sizeof(request));
}

void send_part_request(int qid, const char* group)
{
	fprintf(stderr, "part_request(%d, \"%s\")\n", qid, group);

	struct part_request request;
	strncpy((char*)&request.group, group, MAX_GROUP+1);
	send_request(qid, PART_SUBTYPE, &request, sizeof(request));
}

void send_users_request(int qid, const char* group)
{
	fprintf(stderr, "users_request(%d, \"%s\")\n", qid, group);
	
	struct users_request request;
	strncpy((char*)&request.group, group, MAX_GROUP+1);
	send_request(qid, USERS_SUBTYPE, &request, sizeof(request));
}

void send_private_request(int qid, const char* nick, const char* message)
{
	fprintf(stderr, "private_request(%d, %d, \"%s\")\n",
		qid, nick, message);

	struct private_request request;
	strncpy((char*)&request.nick, nick, MAX_NICK+1);
	strncpy((char*)&request.message, message, MAX_MESSAGE+1);
	send_request(qid, PRIVATE_SUBTYPE, &request, sizeof(request));
}

void send_group_request(int qid, const char* group, const char* message)
{
	fprintf(stderr, "group_request(%d, \"%s\", \"%s\")\n",
		qid, group, message);
		
	struct group_request request;
	strncpy((char*)&request.group, group, MAX_GROUP+1);
	strncpy((char*)&request.message, message, MAX_MESSAGE+1);
	send_request(qid, GROUP_SUBTYPE, &request, sizeof(request));
}
