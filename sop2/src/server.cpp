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

#include <sys/msg.h>
#include <errno.h>

extern "C" 
{
#include "protocol.h"
#include "replies.h"
#include "notifies.h"
}

map<int, string> nicks;
map<string, int> qids;
map<string, set<int> > groups;

list<shared_ptr<thread> > threads;

#define NICK_CHANGED_NOTIFY   "Uzytkownik %s zmienil nick na %s."
#define NICK_CHANGED_REPLY    "Nick zostal zmieniony."
#define DUPLICATE_NICK_REPLY  "Nick jest juz zajety."

#define GROUP_JOINED_NOTIFY   "Uzytkownik %s wszedl do grupy %s."
#define GROUP_JOINED_REPLY    "group joined!"
#define ALREADY_JOINED_REPLY  "already joined!"

#define GROUP_PARTED_NOTIFY   "Uzytkownik %s wyszedl z grupy %s."
#define GROUP_PARTED_REPLY    "group parted!"
#define ALREADY_PARTED_REPLY  "already parted!"

#define NOT_ALLOWED_REPLY     "Ta operacja jest niedozwolona."

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
	
	//...
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
	
	//...
}

void handle_private_request(int qid, private_request* request)
{
	fprintf(stderr, "private_request(%d, \"%s\", \"%s\")\n", 
		qid, request->recipient, request->message);
		
	if (qids.count(request->recipient) != 0)
	{
		send_private_notify(qids[request->recipient], nicks[qid].c_str(), request->message);
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
			handle_client_request(qid, &packet);
			
			if (packet.subtype == LOGOUT_SUBTYPE)
				break;
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
	
	nicks[qid] = lexical_cast<string>(qid);
	qids[lexical_cast<string>(qid)] = qid;
	groups[SYSTEM_GROUP].insert(qid);
	
	send_private_notify(qid, SYSTEM_NICK, "hello!");
	read_client_queue(qid);
	send_private_notify(qid, SYSTEM_NICK, "bye bye!");
	
	//part groups
	groups[SYSTEM_GROUP].erase(qid);
	qids.erase(nicks[qid]);
	nicks.erase(qid);
	
	printf("Client message queue handler finished.\n");
}

void handle_login_request(int qid, login_request* request)
{
	printf("login_request(%d, %d)\n", qid, request->pid);
	
	threads.push_back(shared_ptr<thread>(
		new thread(bind(handle_client_queue, request->pid))));
			
	//handle_client_queue(request->pid);
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
