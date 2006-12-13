#include <list>
using namespace std;

extern "C" 
{
#include <unistd.h>
#include <errno.h>
#include "protocol.h"
#include "requests.h"
#include "client.h"
}

//list<pthread_t> threads;

void handle_groups_reply(int qid, groups_reply* reply)
{
	for (int i=0; i<reply->count; i++)
		printf("Grupa: %s\n", reply->groups[i]);
}

void handle_private_notify(int qid, private_notify* notify)
{
	fprintf(stderr, "private_notify(%d, \"%s\", \"%s\")\n", 
		qid, notify->nick, notify->message);
		
	printf("[%s] %s\n", notify->nick, notify->message);
}

void handle_group_notify(int qid, group_notify* notify)
{
	fprintf(stderr, "group_notify(%d, \"%s\", \"%s\", \"%s\")\n",
		qid, notify->nick, notify->group, notify->message);
		
	printf("<%s> [%s] %s\n", notify->group, notify->nick, notify->message);
}

void handle_users_reply(int qid, users_reply* reply)
{
	printf("Grupa: %s\n", reply->group);
	for (int i=0; i<reply->count; i++)
		printf("User: %s\n", reply->nicks[i]);
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
			printf("Unknown client notify (%d).\n", packet->subtype);
			break;
	}
}

void read_client_queue(int qid)
{
	bool shutdown = false;
	
	while (!shutdown)
	{
		packet_common packet;
		msgrcv(qid, &packet, MAX_PACKET, NOTIFY_TYPE, 0);
		
		if (packet.type == NOTIFY_TYPE)
			handle_client_notify(qid, &packet);
	}
}

void handle_nick_command(int qid)
{
	char nick[MAX_NICK+1];
	scanf("%s", nick);
	send_nick_request(qid, nick);
}

void handle_groups_command(int qid)
{
	send_groups_request(qid);
}

void handle_join_command(int qid)
{
	char group[MAX_GROUP+1];
	scanf("%s", group);
	send_join_request(qid, group);
}

void handle_part_command(int qid)
{
	char group[MAX_GROUP+1];
	scanf("%s", group);
	send_part_request(qid, group);
}

void handle_users_command(int qid)
{
	char group[MAX_GROUP+1];
	scanf("%s", group);
	send_users_request(qid, group);
}

void handle_private_command(int qid)
{
	char nick[MAX_NICK+1];
	char message[MAX_MESSAGE+1];
	scanf("%s %[^\n]s", nick, message);
	send_private_request(qid, nick, message);
}

void handle_group_command(int qid)
{
	char group[MAX_GROUP+1];
	char message[MAX_MESSAGE+1];
	scanf("%s %[^\n]s", group, message);
	send_group_request(qid, group, message);
}

void handle_stdin_command(int qid, const char* command)
{
	if (strcmp(command, NICK_COMMAND) == 0)
		handle_nick_command(qid);
		
	else if (strcmp(command, GROUPS_COMMAND) == 0)
		handle_groups_command(qid);
		
	else if (strcmp(command, JOIN_COMMAND) == 0)
		handle_join_command(qid);
		
	else if (strcmp(command, PART_COMMAND) == 0)
		handle_part_command(qid);

	else if (strcmp(command, USERS_COMMAND) == 0)
		handle_users_command(qid);
		
	else if (strcmp(command, PRIVATE_COMMAND) == 0)
		handle_private_command(qid);
		
	else if (strcmp(command, GROUP_COMMAND) == 0)
		handle_group_command(qid);
	
	else
		printf("Unknown client command (\"%s\").\n", command);
}

void read_stdin_commands(int qid)
{
	bool shutdown = false;
	
	while (!shutdown)
	{
		char command[MAX_COMMAND+1];
		scanf("%s", command);

		if (strcmp(command, LOGOUT_COMMAND) == 0)
			break;
		
		handle_stdin_command(qid, command);
	}
}

void handle_client_queue(pid_t pid)
{
	printf("Creating client message queue...\n");
	int client = msgget(pid, IPC_CREAT | 0660);
	
	if (client == -1)
	{
		printf("%s.\n", strerror(errno));
		return;
	}
	
	printf("Accessing server message queue...\n");
	int server = msgget(SERVER_KEY, 0);
	
	if (server == -1)
	{
		printf("%s.\n", strerror(errno));
		return;
	}
	
	printf("Sending login request...\n");
	send_login_request(server, pid);
	
	pthread_t id;	
	pthread_create(&id, NULL,
		(void* (*)(void*))read_client_queue,
		(void*)client);
	//read_client_queue(client);
	
	read_stdin_commands(client);
	
	printf("Sending logout request...\n");
	send_logout_request(client);
	
	printf("Removing client message queue...\n");
	msgctl(client, IPC_RMID, 0);
}

int main()
{
	handle_client_queue(getpid());
	return 0;
}
