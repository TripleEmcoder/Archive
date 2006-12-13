#include <string>
#include <map>
#include <set>
using namespace std;

#define foreach(c, i) \
    typedef __typeof__(c) c##_for; \
    for(c##_for::iterator i = c.begin(); i != c.end(); ++i)

extern "C" 
{
#include <errno.h>
#include <pthread.h>
#include "protocol.h"
#include "replies.h"
#include "notifies.h"
#include "server.h"
}

map<int, string> nicks;
map<string, int> qids;
map<string, set<int> > groups;
//list<pthread_t> threads;

void send_system_notify(int qid, const char* message)
{
	foreach (nicks, iterator)
		if (iterator->first != qid && iterator->second != SYSTEM_NICK)
			send_private_notify(iterator->first, SYSTEM_NICK, message);
}

void send_system_reply(int qid, const char* message)
{
	send_private_notify(qid, SYSTEM_NICK, message);
}

void handle_nick_request(int qid, nick_request* request)
{
	fprintf(stderr, "nick_request(%d, \"%s\")\n", qid, request->nick);
		
	if (qids.count(request->nick) == 0)
	{
		char message[MAX_MESSAGE+1];
		sprintf(message, NICK_CHANGED_NOTIFY,
			nicks[qid].c_str(), request->nick);
		
		send_system_notify(qid, message);
		send_system_reply(qid, NICK_CHANGED_REPLY);

		qids.erase(nicks[qid]);
		nicks.erase(qid);
		
		nicks[qid] = request->nick;
		qids[request->nick] = qid;
	}
	else
	{
		send_system_reply(qid, DUPLICATE_NICK_REPLY);
	}
}

void handle_groups_request(int qid, groups_request* request)
{
	fprintf(stderr, "groups_request(%d)\n", qid);
	
	char temp[MAX_GROUPS][MAX_GROUP+1];
	
	int count = 0;
	
	foreach (groups, iterator)
		strncpy(temp[count++], iterator->first.c_str(), MAX_GROUP+1);
	
	send_groups_reply(qid, count, temp);	
}

void handle_join_request(int qid, join_request* request)
{
	fprintf(stderr, "join_request(%d, \"%s\")\n", qid, request->group);

	if (strcmp(request->group, SYSTEM_GROUP) != 0)
	{
		if (groups[request->group].count(qid) == 0)
		{
			groups[request->group].insert(qid);
		
			char message[MAX_MESSAGE+1];
			sprintf(message, GROUP_JOINED_NOTIFY,
				nicks[qid].c_str(), request->group);
		
			send_system_notify(qid, message);
			send_system_reply(qid, GROUP_JOINED_REPLY);
		}
		else
		{
			send_system_reply(qid, ALREADY_JOINED_REPLY);
		}
	}
	else
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
	}
}

void handle_part_request(int qid, part_request* request)
{
	fprintf(stderr, "part_request(%d, \"%s\")\n", qid, request->group);

	if (strcmp(request->group, SYSTEM_GROUP) != 0)
	{
		if (groups[request->group].count(qid) != 0)
		{
			groups[request->group].erase(qid);
			
			char message[MAX_MESSAGE+1];
			sprintf(message, GROUP_PARTED_NOTIFY,
				nicks[qid].c_str(), request->group);
		
			send_system_notify(qid, message);
			send_system_reply(qid, GROUP_PARTED_REPLY);
		}
		else
		{
			send_system_reply(qid, ALREADY_PARTED_REPLY);
		}
		
		if (groups[request->group].size() == 0)
			groups.erase(request->group);
	}
	else
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
	}
}

void handle_users_request(int qid, users_request* request)
{
	fprintf(stderr, "users_request(%d, \"%s\")\n", qid, request->group);
	
	set<int>& members = groups[request->group];
	
	char temp[MAX_NICKS][MAX_NICK+1];
	
	int count = 0;
	
	foreach (members, iterator)
		strncpy(temp[count++], nicks[*iterator].c_str(), MAX_NICK+1);
		
	send_users_reply(qid, request->group, count, temp);
}

void handle_private_request(int qid, private_request* request)
{
	fprintf(stderr, "private_request(%d, \"%s\", \"%s\")\n", 
		qid, request->nick, request->message);
		
	if (qids.count(request->nick) != 0)
	{
		send_private_notify(qids[request->nick], nicks[qid].c_str(), request->message);
		send_private_notify(qid, SYSTEM_NICK, "message sent!");
	}
	else
	{
		send_private_notify(qid, SYSTEM_NICK, "invalid recipient!");		
	}
}

void handle_group_request(int qid, group_request* request)
{
	fprintf(stderr, "group_request(%d, \"%s\", \"%s\")\n",
		qid, request->group, request->message);
		
	if (groups.count(request->group) != 0)
	{
		set<int>& members = groups[request->group];
		
		foreach (members, member)
			if (*member != qid)
				send_group_notify(*member, nicks[qid].c_str(), request->group, request->message);
			
		send_private_notify(qid, SYSTEM_NICK, "message sent!");
	}
	else
	{
		send_private_notify(qid, SYSTEM_NICK, "invalid group!");		
	}
}

void handle_client_request(int qid, packet_common* packet)
{
	switch (packet->subtype)
	{
		case NICK_SUBTYPE:
			handle_nick_request(qid, (nick_request*)&packet->data);
			break;
		
		case GROUPS_SUBTYPE:
			handle_groups_request(qid, (groups_request*)&packet->data);
			break;
		
		case JOIN_SUBTYPE:
			handle_join_request(qid, (join_request*)&packet->data);
			break;
		
		case PART_SUBTYPE:
			handle_part_request(qid, (part_request*)&packet->data);
			break;
			
		case USERS_SUBTYPE:
			handle_users_request(qid, (users_request*)&packet->data);
			break;
		
		case PRIVATE_SUBTYPE:
			handle_private_request(qid, (private_request*)&packet->data);
			break;
			
		case GROUP_SUBTYPE:
			handle_group_request(qid, (group_request*)&packet->data);
			break;
			
		default:
			printf("Unknown client request (%d).\n", packet->subtype);
			break;
	}
}

void read_client_queue(int qid)
{
	bool shutdown = false;

	while (!shutdown)
	{
		packet_common packet;
		msgrcv(qid, &packet, MAX_PACKET, REQUEST_TYPE, 0);
		
		if (packet.type == REQUEST_TYPE)
		{
			if (packet.subtype == LOGOUT_SUBTYPE)
				break;
				
			handle_client_request(qid, &packet);
		}
	}
}

void handle_client_queue(pid_t pid)
{
	printf("Accessing client message queue...\n");
	int qid = msgget(pid, 0);
	
	if (qid == -1)
	{
		printf("%s.\n", strerror(errno));
		return;
	}
	
	char buffer[100];
	sprintf(buffer, "%d", qid);
	
	nicks[qid] = buffer;
	qids[buffer] = qid;
	groups[SYSTEM_GROUP].insert(qid);
	
	send_system_reply(qid, AFTER_LOGIN_REPLY);
	read_client_queue(qid);
	//send_system_reply(qid, BEFORE_LOGOUT_REPLY);
	
	//part groups
	groups[SYSTEM_GROUP].erase(qid);
	qids.erase(nicks[qid]);
	nicks.erase(qid);
	
	printf("Client message queue handler finished.\n");
}

void handle_login_request(int qid, login_request* request)
{
	fprintf(stderr, "login_request(%d, %d)\n", qid, request->pid);
	
	pthread_t id;
	pthread_create(&id, NULL, 
		(void* (*)(void*))handle_client_queue,
		(void*)request->pid);
	//handle_client_queue(request->pid);
}

void handle_server_request(int qid, packet_common* packet)
{
	switch (packet->subtype)
	{
		case LOGIN_SUBTYPE:
			handle_login_request(qid, (login_request*)&packet->data);
			break;
		
		default:
			printf("Unknown server request (%d).\n", packet->subtype);
			break;
	}
}

void read_server_queue(int qid)
{
	bool shutdown = false;
	
	while (!shutdown)
	{
		packet_common packet;
		msgrcv(qid, &packet, MAX_PACKET, REQUEST_TYPE, 0);
		
		if (packet.type == REQUEST_TYPE)
		{
			if (packet.subtype == LOGOUT_SUBTYPE)
				break;
				
			handle_server_request(qid, &packet);
		}
	}
}

void handle_server_queue(key_t key)
{
	printf("Creating server message queue...\n");
	int qid = msgget(SERVER_KEY, IPC_CREAT | 0660);
	
	if (qid == -1)
	{
		printf("%s.\n", strerror(errno));
		return;
	}

	nicks[qid] = SYSTEM_NICK;	
	qids[SYSTEM_NICK] = qid;
	
	read_server_queue(qid);
	
	qids.erase(SYSTEM_NICK);
	nicks.erase(qid);
	
	printf("Removing server message queue...\n");
	msgctl(qid, IPC_RMID, 0);
}

int main()
{
	handle_server_queue(SERVER_KEY);
	return 0;
}
