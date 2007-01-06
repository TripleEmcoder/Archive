#include "commands.h"
#include "protocol.h"
#include "requests.h"
#include <stdio.h>

void handle_nick_command(int qid, const char* line)
{
	char nick[MAX_NICK+1];
	sscanf(line, "%*s %s", nick);
	send_nick_request(qid, nick);
}

void handle_groups_command(int qid, const char* line)
{
	send_groups_request(qid);
}

void handle_join_command(int qid, const char* line)
{
	char group[MAX_GROUP+1];
	sscanf(line, "%*s %s", group);
	send_join_request(qid, group);
}

void handle_part_command(int qid, const char* line)
{
	char group[MAX_GROUP+1];
	sscanf(line, "%*s %s", group);
	send_part_request(qid, group);
}

void handle_users_command(int qid, const char* line)
{
	char group[MAX_GROUP+1];
	sscanf(line, "%*s %s", group);
	send_users_request(qid, group);
}

void handle_private_command(int qid, const char* line)
{
	char nick[MAX_NICK+1];
	char message[MAX_MESSAGE+1];
	sscanf(line, "%*s %s %[^\n]s", nick, message);
	send_private_request(qid, nick, message);
}

void handle_group_command(int qid, const char* line)
{
	char group[MAX_GROUP+1];
	char message[MAX_MESSAGE+1];
	sscanf(line, "%*s %s %[^\n]s", group, message);
	send_group_request(qid, group, message);
}
