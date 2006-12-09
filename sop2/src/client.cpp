#include <map>
using namespace std;

#include <boost/format.hpp>
#include <boost/thread/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
using namespace boost;

#include <unistd.h>
#include <errno.h>

extern "C" 
{
#include "protocol.h"
#include "requests.h"
}

map<int, string> nicks;
map<string, int> qids;


list<shared_ptr<thread> > threads;

void handle_private_notify(int qid, private_notify* notify)
{
	fprintf(stderr, "private_notify(%d, \"%s\", \"%s\")\n", 
		qid, notify->sender, notify->message);
		
	printf("[%s] %s\n", notify->sender, notify->message);
}

void handle_group_notify(int qid, group_notify* notify)
{
	fprintf(stderr, "group_notify(%d, \"%s\", \"%s\", \"%s\")\n",
		qid, notify->sender, notify->group, notify->message);
		
	printf("<%s> [%s] %s\n", notify->group, notify->sender, notify->message);
}

void handle_client_notify(int qid, packet_common* packet)
{
	switch (packet->subtype)
	{
		case PRIVATE_SUBTYPE:
			handle_private_notify(qid, (private_notify*)&packet->data);
			break;
			
		case GROUP_SUBTYPE:
			handle_group_notify(qid, (group_notify*)&packet->data);
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
		//printf("CLIENT: %d %d\n", packet.type, packet.subtype);
		
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

void handle_join_command(int qid)
{
	char group[MAX_GROUP+1];
	scanf("%s",group);
	send_join_request(qid, group);
}

void handle_part_command(int qid)
{
	char group[MAX_GROUP+1];
	scanf("%s",group);
	send_part_request(qid, group);
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

#define MAX_COMMAND 10
#define LOGOUT_COMMAND "/logout"
#define NICK_COMMAND "/nick"
#define JOIN_COMMAND "/join"
#define PART_COMMAND "/part"
#define PRIVATE_COMMAND "/private"
#define GROUP_COMMAND "/group"

void handle_stdin_command(int qid, const char* command)
{
	if (strcmp(command, NICK_COMMAND) == 0)
		handle_nick_command(qid);
		
	else if (strcmp(command, JOIN_COMMAND) == 0)
		handle_join_command(qid);
		
	else if (strcmp(command, PART_COMMAND) == 0)
		handle_part_command(qid);
		
	else if (strcmp(command, PRIVATE_COMMAND) == 0)
		handle_private_command(qid);
		
	else if (strcmp(command, GROUP_COMMAND) == 0)
		handle_group_command(qid);
}

void read_stdin_commands(int qid)
{
	bool shutdown = false;
	
	while (!shutdown)
	{
		char command[MAX_COMMAND+1];
		scanf("%s", command);
		
		handle_stdin_command(qid, command);
		
		if (strcmp(command, LOGOUT_COMMAND) == 0)
			break;
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
	
	/*
	send_private_request(client, client, "private");
	send_join_request(client, USERS_GROUP);
	send_part_request(client, USERS_GROUP);
	send_group_request(client, USERS_GROUP, "all");
	send_join_request(client, "group");
	send_group_request(client, "group", "group");
	send_part_request(client, "group");
	send_group_request(client, "group", "group");
	*/
	
	//read_client_queue(client);
	threads.push_back(shared_ptr<thread>(
		new thread(bind(read_client_queue, client))));
		
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
