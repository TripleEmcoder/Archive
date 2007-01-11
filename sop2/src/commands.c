#include "commands.h"
#include "protocol.h"
#include "requests.h"
#include "messages.h"
#include <stdio.h>

void handle_nick_command(int qid, const char* line)
{
	char nick[MAX_NICK+1];

	if (sscanf(line, "%*s %s", nick) != 1)
	{
		write_output(MALFORMED_CLIENT_COMMAND, line);
		return;
	}
	
	send_nick_request(qid, nick);
}

void handle_groups_command(int qid, const char* line)
{
	send_groups_request(qid);
}

void handle_join_command(int qid, const char* line)
{
	char group[MAX_GROUP+1];
	
	if (sscanf(line, "%*s %s", group) != 1)
	{
		write_output(MALFORMED_CLIENT_COMMAND, line);
		return;
	}
	
	send_join_request(qid, group);
}

void handle_part_command(int qid, const char* line)
{
	char group[MAX_GROUP+1];
	
	if (sscanf(line, "%*s %s", group) != 1)
	{
		write_output(MALFORMED_CLIENT_COMMAND, line);
		return;
	}
	
	send_part_request(qid, group);
}

void handle_users_command(int qid, const char* line)
{
	char group[MAX_GROUP+1];
	
	if (sscanf(line, "%*s %s", group) != 1)
	{
		write_output(MALFORMED_CLIENT_COMMAND, line);
		return;
	}
	
	send_users_request(qid, group);
}

void handle_private_command(int qid, const char* line)
{
	char nick[MAX_NICK+1];
	char message[MAX_MESSAGE+1];
	
	if (sscanf(line, "%*s %s %[^\n]s", nick, message) != 2)
	{
		write_output(MALFORMED_CLIENT_COMMAND, line);
		return;
	}
	
	send_private_request(qid, nick, message);
}

void handle_group_command(int qid, const char* line)
{
	char group[MAX_GROUP+1];
	char message[MAX_MESSAGE+1];
	
	if (sscanf(line, "%*s %s %[^\n]s", group, message) != 2)
	{
		write_output(MALFORMED_CLIENT_COMMAND, line);
		return;
	}
	
	send_group_request(qid, group, message);
}
