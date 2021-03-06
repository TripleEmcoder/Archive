#include <list>
using namespace std;

extern "C" 
{
#include <unistd.h>
#include <errno.h>
#include "client.h"
#include "protocol.h"
#include "requests.h"
#include "windows.h"
#include "commands.h"
#include "messages.h"
}

void handle_groups_reply(int qid, groups_reply* reply)
{
	write_output("Lista grup:\n");
	
	for (int i=0; i<reply->count; i++)
		write_output("-> %s\n", reply->groups[i]);
}

void handle_private_notify(int qid, private_notify* notify)
{
	write_debug_output("private_notify(%d, \"%s\", \"%s\")\n", 
		qid, notify->nick, notify->message);
		
	write_output("[%s] %s\n", notify->nick, notify->message);
}

void handle_group_notify(int qid, group_notify* notify)
{
	write_debug_output("group_notify(%d, \"%s\", \"%s\", \"%s\")\n",
		qid, notify->nick, notify->group, notify->message);
		
	write_output("<%s> [%s] %s\n", notify->group, notify->nick, notify->message);
}

void handle_users_reply(int qid, users_reply* reply)
{
	write_output("Lista uzytkownikow w grupie %s:\n", reply->group);
	
	for (int i=0; i<reply->count; i++)
		write_output("-> %s\n", reply->nicks[i]);
}

void handle_client_notify(int qid, packet_common* packet)
{
	switch (packet->subtype)
	{
		case GROUPS_SUBTYPE:
			handle_groups_reply(qid, (groups_reply*)&packet->data);
			break;
			
		case USERS_SUBTYPE:
			handle_users_reply(qid, (users_reply*)&packet->data);
			break;
			
		case PRIVATE_SUBTYPE:
			handle_private_notify(qid, (private_notify*)&packet->data);
			break;
			
		case GROUP_SUBTYPE:
			handle_group_notify(qid, (group_notify*)&packet->data);
			break;
			
		default:
			write_output(UNKNOWN_CLIENT_NOTIFY, packet->subtype);
			break;
	}
}

void read_client_queue(int qid)
{
	bool shutdown = false;
	
	while (!shutdown)
	{
		packet_common packet;
		
		if (msgrcv(qid, &packet, MAX_PACKET, NOTIFY_TYPE, 0) == -1)
		{
			write_output("%s.\n", strerror(errno));
			return;
		}	
		
		if (packet.type == NOTIFY_TYPE)
			handle_client_notify(qid, &packet);
	}
}

void handle_stdin_command(int qid, const char* line)
{
	char command[MAX_COMMAND+1];
	if (sscanf(line, "%s", command) != 1)
		return;

	if (strcmp(command, NICK_COMMAND) == 0)
		handle_nick_command(qid, line);
		
	else if (strcmp(command, GROUPS_COMMAND) == 0)
		handle_groups_command(qid, line);
		
	else if (strcmp(command, JOIN_COMMAND) == 0)
		handle_join_command(qid, line);
		
	else if (strcmp(command, PART_COMMAND) == 0)
		handle_part_command(qid, line);

	else if (strcmp(command, USERS_COMMAND) == 0)
		handle_users_command(qid, line);
		
	else if (strcmp(command, PRIVATE_COMMAND) == 0)
		handle_private_command(qid, line);
		
	else if (strcmp(command, GROUP_COMMAND) == 0)
		handle_group_command(qid, line);
	
	else
		write_output(UNKNOWN_CLIENT_COMMAND, command);
}

void read_stdin_commands(int qid)
{
	bool shutdown = false;
	
	while (!shutdown)
	{
		char line[MAX_MESSAGE+1];
		read_input(line);
		
		char command[MAX_COMMAND+1];
		sscanf(line, "%s", command);

		if (strcmp(command, LOGOUT_COMMAND) == 0)
			break;
		
		handle_stdin_command(qid, line);
	}
}

void handle_client_queue(pid_t pid)
{
	write_output(CREATING_CLIENT_QUEUE, pid);
	int client = msgget(pid, IPC_CREAT | 0660);
	
	if (client == -1)
	{
		write_output("%s.\n", strerror(errno));
		return;
	}
	
	write_output(JOINING_SERVER_QUEUE, SERVER_KEY);
	int server = msgget(SERVER_KEY, 0);
	
	if (server == -1)
	{
		write_output("%s.\n", strerror(errno));
		return;
	}
	
	write_output(SENDING_LOGIN_REQUEST, server);
	send_login_request(server, pid);
	
	write_output(PARTING_SERVER_QUEUE, server);
	
	pthread_t id;	
	pthread_create(&id, NULL,
		(void* (*)(void*))read_client_queue,
		(void*)client);
	
	//read_client_queue(client);
	read_stdin_commands(client);
	
	write_output(SENDING_LOGOUT_REQUEST, client);
	send_logout_request(client);
	
	write_output(REMOVING_CLIENT_QUEUE, client);
	msgctl(client, IPC_RMID, 0);
}

int main()
{
	create_windows();
	handle_client_queue(getpid());
	sleep(2);
	destroy_windows();
	return 0;
}
