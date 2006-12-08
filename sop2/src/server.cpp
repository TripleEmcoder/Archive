#include <string>
#include <map>
#include <set>
using namespace std;

#include <boost/lexical_cast.hpp>
#include <boost/thread/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
using namespace boost;

#define foreach(c, i) \
    typedef __typeof__(c) c##_for; \
    for(c##_for::iterator i = c.begin(); i != c.end(); ++i)

#include <errno.h>

extern "C" 
{
#include "protocol.h"
#include "replies.h"
#include "notifies.h"
}

set<string> nicks;
map<int, string> users;
map<string, set<int> > groups;

list<shared_ptr<thread> > threads;

void handle_logout_request(int qid, logout_request* request)
{
	printf("logout_request(%d)\n", qid);
	
	send_private_notify(qid, SYSTEM_QID, "bye bye!");
	nicks.erase(users[qid]);
	users.erase(qid);
}

void handle_nick_request(int qid, nick_request* request)
{
	printf("nick_request(%d, \"%s\")\n", qid, request->nick);
		
	if (nicks.count(request->nick) == 0)
	{
		nicks.erase(users[qid]);
		users[qid] = request->nick;
		nicks.insert(users[qid]);

		send_private_notify(qid, SYSTEM_QID, "nick changed!");
	}
	else
	{
		send_private_notify(qid, SYSTEM_QID, "duplicate nick!");
	}
}

void handle_groups_request(int qid, groups_request* request)
{
	printf("groups_request(%d)\n", qid);
	
	//...
}

void handle_join_request(int qid, join_request* request)
{
	printf("join_request(%d, \"%s\")\n", qid, request->group);

	if (strcmp(request->group, USERS_GROUP) != 0)
	{
		groups[request->group].insert(qid);
	
		send_private_notify(qid, SYSTEM_QID, "group joined!");
	}
	else
	{
		send_private_notify(qid, SYSTEM_QID, "not allowed!");
	}
}

void handle_part_request(int qid, part_request* request)
{
	printf("part_request(%d, \"%s\")\n", qid, request->group);

	if (strcmp(request->group, USERS_GROUP) != 0)
	{
		groups[request->group].erase(qid);
	
		if (groups[request->group].size() == 0)
			groups.erase(request->group);
		
		send_private_notify(qid, SYSTEM_QID, "group parted!");
	}
	else
	{
		send_private_notify(qid, SYSTEM_QID, "not allowed!");
	}
}

void handle_users_request(int qid, users_request* request)
{
	printf("users_request(%d, \"%s\")\n", qid, request->group);
	
	//...
}

void handle_private_request(int qid, private_request* request)
{
	printf("private_request(%d, %d, \"%s\")\n", 
		qid, request->recipient, request->message);
		
	if (users.count(request->recipient) != 0)
	{
		send_private_notify(request->recipient, qid, request->message);
		send_private_notify(qid, SYSTEM_QID, "message sent!");
	}
	else
	{
		send_private_notify(qid, SYSTEM_QID, "invalid recipient!");		
	}
}

void handle_group_request(int qid, group_request* request)
{
	printf("group_request(%d, \"%s\", \"%s\")\n",
		qid, request->group, request->message);
		
	if (groups.count(request->group) != 0)
	{
		set<int>& members = groups[request->group];
		
		foreach (members, member)
			if (*member != qid)
				send_group_notify(*member, qid, request->group, request->message);
			
		send_private_notify(qid, SYSTEM_QID, "message sent!");
	}
	else
	{
		send_private_notify(qid, SYSTEM_QID, "invalid group!");		
	}
}

void handle_client_request(int qid, packet_common* packet)
{
	switch (packet->subtype)
	{
		case LOGOUT_SUBTYPE:
			handle_logout_request(qid, (logout_request*)&packet->data);
			break;
			
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
	}
}

void read_client_queue(int qid)
{
	bool shutdown = false;

	while (!shutdown)
	{
		packet_common packet;
		msgrcv(qid, &packet, MAX_PACKET, REQUEST_TYPE, 0);
		//printf("CLIENT: %d %d\n", packet.type, packet.subtype);
		
		if (packet.type == REQUEST_TYPE)
		{
			handle_client_request(qid, &packet);
			
			if (packet.subtype == LOGOUT_SUBTYPE)
				break;
		}
	}
}

void handle_client_queue(pid_t pid)
{
	printf("Accessing client message queue...\n");
	int client = msgget(pid, 0);
	
	if (client == -1)
	{
		printf("%s.\n", strerror(errno));
		return;
	}
	
	groups[USERS_GROUP].insert(client);
	read_client_queue(client);
	groups[USERS_GROUP].erase(client);
	
	printf("Client message queue handler finished.\n");
}

void handle_login_request(int qid, login_request* request)
{
	printf("login_request(%d, %d)\n", qid, request->pid);
		
	handle_client_queue(request->pid);
}

void handle_server_request(int qid, packet_common* packet)
{
	switch (packet->subtype)
	{
		case LOGIN_SUBTYPE:
			handle_login_request(qid, (login_request*)&packet->data);
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
		//printf("SERVER: %d %d\n", packet.type, packet.subtype);
		
		if (packet.type == REQUEST_TYPE)
		{
			handle_server_request(qid, &packet);
			
			if (packet.subtype == LOGOUT_SUBTYPE)
				break;
		}
	}
}

void handle_server_queue(key_t key)
{
	printf("Creating server message queue...\n");
	int server = msgget(SERVER_KEY, IPC_CREAT | 0660);
	
	if (server == -1)
	{
		printf("%s.\n", strerror(errno));
		return;
	}
	
	nicks.insert(SYSTEM_NICK);
	users[SYSTEM_QID] = SYSTEM_NICK;
	read_server_queue(server);
	
	printf("Removing server message queue...\n");
	msgctl(server, IPC_RMID, 0);
}

int main()
{
	setbuf(stdout, NULL);
	handle_server_queue(SERVER_KEY);
	return 0;
}
