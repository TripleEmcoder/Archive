#include "requests.h"
#include "packets.h"
#include "protocol.h"
#include <string.h>
#include <stdio.h>

void send_request(int queue, int subtype, void* data, int size)
{
	send_packet(queue, REQUEST_TYPE, subtype, data, size);
}

void send_login_request(int queue, pid_t pid)
{
	fprintf(stderr, "login_request(%d, %d)\n", queue, pid);

	struct login_request request;
	request.pid = pid;
	send_request(queue, LOGIN_SUBTYPE, &request, sizeof(request));
}

void send_logout_request(int queue)
{
	fprintf(stderr, "login_request(%d)\n", queue);

	struct logout_request request;
	send_request(queue, LOGOUT_SUBTYPE, &request, sizeof(request));
}

void send_nick_request(int queue, const char* nick)
{
	fprintf(stderr, "nick_request(%d, \"%s\")\n", queue, nick);

	struct nick_request request;
	strncpy((char*)&request.nick, nick, MAX_NICK+1);
	send_request(queue, NICK_SUBTYPE, &request, sizeof(request));
}

void send_join_request(int queue, const char* group)
{
	fprintf(stderr, "join_request(%d, \"%s\")\n", queue, group);
	
	struct join_request request;
	strncpy((char*)&request.group, group, MAX_GROUP+1);
	send_request(queue, JOIN_SUBTYPE, &request, sizeof(request));
}

void send_part_request(int queue, const char* group)
{
	fprintf(stderr, "part_request(%d, \"%s\")\n", queue, group);

	struct part_request request;
	strncpy((char*)&request.group, group, MAX_GROUP+1);
	send_request(queue, PART_SUBTYPE, &request, sizeof(request));
}

void send_private_request(int queue, const char* recipient, const char* message)
{
	fprintf(stderr, "private_request(%d, %d, \"%s\")\n",
		queue, recipient, message);

	struct private_request request;
	strncpy((char*)&request.recipient, recipient, MAX_NICK+1);
	strncpy((char*)&request.message, message, MAX_MESSAGE+1);
	send_request(queue, PRIVATE_SUBTYPE, &request, sizeof(request));
}

void send_group_request(int queue, const char* group, const char* message)
{
	fprintf(stderr, "group_request(%d, \"%s\", \"%s\")\n",
		queue, group, message);
		
	struct group_request request;
	strncpy((char*)&request.group, group, MAX_GROUP+1);
	strncpy((char*)&request.message, message, MAX_MESSAGE+1);
	send_request(queue, GROUP_SUBTYPE, &request, sizeof(request));
}
