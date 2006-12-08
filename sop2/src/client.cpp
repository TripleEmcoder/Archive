using namespace std;

#include <boost/format.hpp>
#include <boost/thread/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
using namespace boost;

#include <unistd.h>
#include <errno.h>
#include "protocol.h"
#include "requests.h"

list<shared_ptr<thread> > threads;

void handle_private_notify(int qid, private_notify* notify)
{
	printf("private_notify(%d, %d, \"%s\")\n", 
		qid, notify->sender, notify->message);
}

void handle_group_notify(int qid, group_notify* notify)
{
	printf("group_notify(%d, %d, \"%s\", \"%s\")\n",
		qid, notify->sender, notify->group, notify->message);
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

#define MAX_COMMAND 10

void read_stdin_command(int qid)
{
	char command[MAX_COMMAND+1];
	scanf("%s", command);
	printf("%s\n", command);
	//if (strcmp(command, 
}

void read_stdin_commands(int qid)
{
	bool shutdown = false;
	
	while (!shutdown)
	{
		char first = getc();
		
		if (first != '/')
		{
			ungetc(first);
			continue;
		}
	
		process_stdin_command(qid);
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
	
	send_nick_request(client, SYSTEM_NICK);
	send_nick_request(client, "Memfis");
	send_private_request(client, client, "private");
	send_join_request(client, USERS_GROUP);
	send_part_request(client, USERS_GROUP);
	send_group_request(client, USERS_GROUP, "all");
	send_join_request(client, "group");
	send_group_request(client, "group", "group");
	send_part_request(client, "group");
	send_group_request(client, "group", "group");
	
	//read_client_queue(client);
	threads.push_back(shared_ptr<thread>(
		new thread(bind(read_client_queue, client))));
		
	read_stdin_queue(client);
	
	printf("Removing client message queue...\n");
	msgctl(client, IPC_RMID, 0);
}

int main()
{
	setbuf(stdout, NULL);
	handle_client_queue(getpid());
	return 0;
}
