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
#include <signal.h>
#include "server.h"
#include "protocol.h"
#include "replies.h"
#include "notifies.h"
#include "windows.h"
#include "messages.h"
}

map<int, string> nicks;
map<string, int> qids;
map<string, set<int> > groups;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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
	request->nick[MAX_NICK] = '\0';
	
	write_debug_output("nick_request(%d, \"%s\")\n", qid, request->nick);
	
	if (strlen(request->nick) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}
	
	if (qids.count(request->nick) != 0)
	{
		send_system_reply(qid, DUPLICATE_NICK_REPLY);
		return;
	}

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

void handle_groups_request(int qid, groups_request* request)
{
	write_debug_output("groups_request(%d)\n", qid);
	
	char temp[MAX_GROUPS][MAX_GROUP+1];
	
	int count = 0;
	
	foreach (groups, iterator)
		strncpy(temp[count++], iterator->first.c_str(), MAX_GROUP+1);
	
	send_groups_reply(qid, count, temp);	
}

void handle_join_request(int qid, join_request* request)
{
	request->group[MAX_GROUP] = '\0';
	
	write_debug_output("join_request(%d, \"%s\")\n", qid, request->group);

	if (strlen(request->group) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}

	if (strcmp(request->group, SYSTEM_GROUP) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}

	if (groups.count(request->group) == 0 && groups.size() == MAX_GROUPS)
	{
		send_system_reply(qid, MAX_GROUPS_REPLY);
		return;
	}

	if (groups[request->group].count(qid) != 0)
	{
		send_system_reply(qid, ALREADY_JOINED_REPLY);
		return;
	}
	
	if (groups[request->group].size() == MAX_NICKS)
	{
		send_system_reply(qid, MAX_NICKS_REPLY);
		return;
	}

	groups[request->group].insert(qid);
		
	char message[MAX_MESSAGE+1];
	sprintf(message, GROUP_JOINED_NOTIFY,
		nicks[qid].c_str(), request->group);
		
	send_system_notify(qid, message);
	send_system_reply(qid, GROUP_JOINED_REPLY);
}

void handle_part_request(int qid, part_request* request)
{
	request->group[MAX_GROUP] = '\0';
	
	write_debug_output("part_request(%d, \"%s\")\n", qid, request->group);

	if (strlen(request->group) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}

	if (strcmp(request->group, SYSTEM_GROUP) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}

	if (groups.count(request->group) == 0)
	{
		send_system_reply(qid, NONEXISTANT_GROUP_REPLY);
		return;
	}
	
	if (groups[request->group].count(qid) == 0)
	{
		send_system_reply(qid, ALREADY_PARTED_REPLY);
		return;
	}

	groups[request->group].erase(qid);
	
	char message[MAX_MESSAGE+1];
	sprintf(message, GROUP_PARTED_NOTIFY,
		nicks[qid].c_str(), request->group);
	
	send_system_notify(qid, message);
	send_system_reply(qid, GROUP_PARTED_REPLY);

	if (groups[request->group].size() == 0)
		groups.erase(request->group);
}

void handle_users_request(int qid, users_request* request)
{
	request->group[MAX_GROUP] = '\0';
	
	write_debug_output("users_request(%d, \"%s\")\n", qid, request->group);
	
	if (strlen(request->group) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}

	if (groups.count(request->group) == 0)
	{
		send_system_reply(qid, NONEXISTANT_GROUP_REPLY);
		return;
	}

	set<int>& members = groups[request->group];
	
	char temp[MAX_NICKS][MAX_NICK+1];
	
	int count = 0;
	
	foreach (members, iterator)
		strncpy(temp[count++], nicks[*iterator].c_str(), MAX_NICK+1);
		
	send_users_reply(qid, request->group, count, temp);
}

void handle_private_request(int qid, private_request* request)
{
	request->nick[MAX_NICK] = '\0';
	request->message[MAX_MESSAGE] = '\0';
	
	write_debug_output("private_request(%d, \"%s\", \"%s\")\n", 
		qid, request->nick, request->message);

	if (strlen(request->nick) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}

	if (strlen(request->message) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}
	
	if (strcmp(request->nick, SYSTEM_NICK) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}

	if (qids.count(request->nick) == 0)
	{
		send_system_reply(qid, INVALID_RECIPIENT_REPLY);
		return;
	}

	send_private_notify(qids[request->nick], 
		nicks[qid].c_str(), request->message);
			
	send_private_notify(qid, 
		nicks[qid].c_str(), request->message);
			
	//send_system_reply(qid, MESSAGE_SENT_REPLY);
}

void handle_group_request(int qid, group_request* request)
{
	request->group[MAX_GROUP] = '\0';
	request->message[MAX_MESSAGE] = '\0';

	write_debug_output("group_request(%d, \"%s\", \"%s\")\n",
		qid, request->group, request->message);
	
	if (strlen(request->group) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}

	if (strlen(request->message) == 0)
	{
		send_system_reply(qid, NOT_ALLOWED_REPLY);
		return;
	}
	
	if (groups.count(request->group) == 0)
	{
		send_system_reply(qid, INVALID_RECIPIENT_REPLY);
		return;
	}

	set<int>& members = groups[request->group];
		
	foreach (members, member)
		//if (*member != qid)
		if (nicks[*member] != SYSTEM_NICK)
			send_group_notify(*member, nicks[qid].c_str(), 
				request->group, request->message);
			
	//send_system_reply(qid, MESSAGE_SENT_REPLY);
}

void handle_client_request(int qid, packet_common* packet)
{
	pthread_mutex_lock(&mutex);
	write_debug_output("i\nn");
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
			write_output(UNKNOWN_CLIENT_REQUEST, packet->subtype);
			break;
	}
	
	write_debug_output("out\n");
	pthread_mutex_unlock(&mutex);
}

void read_client_queue(int qid)
{
	bool shutdown = false;

	while (!shutdown)
	{
		packet_common packet;
		if (msgrcv(qid, &packet, MAX_PACKET, REQUEST_TYPE, 0) == -1)
		{
			write_output("%s.\n", strerror(errno));
			return;
		}	
		
		if (packet.type == REQUEST_TYPE)
		{
			if (packet.subtype == LOGOUT_SUBTYPE)
				break;
				
			handle_client_request(qid, &packet);
		}
	}
}

bool handle_client_login(int qid)
{
	pthread_mutex_lock(&mutex);
	
	if (nicks.size() == MAX_NICKS)
	{
		send_system_reply(qid, MAX_NICKS_REPLY);
		return false;
	}
	
	write_output(CREATING_CLIENT_RECORD, qid);
	
	char buffer[100];
	sprintf(buffer, "%d", qid);
	
	nicks[qid] = buffer;
	qids[buffer] = qid;
	groups[SYSTEM_GROUP].insert(qid);
	
	char message[MAX_MESSAGE+1];
	sprintf(message, AFTER_LOGIN_NOTIFY, nicks[qid].c_str());
		
	send_system_notify(qid, message);
	send_system_reply(qid, AFTER_LOGIN_REPLY);
	
	pthread_mutex_unlock(&mutex);

	return true;
}

void handle_client_logout(int qid)
{
	pthread_mutex_lock(&mutex);
	
	write_output(REMOVING_CLIENT_RECORD, qid);
	
	char message[MAX_MESSAGE+1];
	sprintf(message, BEFORE_LOGOUT_NOTIFY, nicks[qid].c_str());
		
	send_system_notify(qid, message);
	//send_system_reply(qid, BEFORE_LOGOUT_REPLY);
	
	foreach (groups, iterator)
		iterator->second.erase(qid);
		
	groups[SYSTEM_GROUP].erase(qid);
	qids.erase(nicks[qid]);
	nicks.erase(qid);
	
	pthread_mutex_unlock(&mutex);
}

void handle_client_queue(pid_t pid)
{
	write_output(JOINING_CLIENT_QUEUE, pid);
	int qid = msgget(pid, 0);
	
	if (qid == -1)
	{
		write_output("%s.\n", strerror(errno));
		return;
	}

	if (handle_client_login(qid))
	{
		read_client_queue(qid);
		handle_client_logout(qid);
	}
	
	write_output(PARTING_CLIENT_QUEUE, qid);
}

void handle_login_request(int qid, login_request* request)
{
	write_debug_output("login_request(%d, %d)\n", qid, request->pid);
	
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
			write_output(UNKNOWN_SERVER_REQUEST, packet->subtype);
			break;
	}
}

void read_server_queue(int qid)
{
	bool shutdown = false;
	
	while (!shutdown)
	{
		packet_common packet;
		
		if (msgrcv(qid, &packet, MAX_PACKET, REQUEST_TYPE, 0) == -1)
		{
			write_output("%s.\n", strerror(errno));
			return;
		}		
		
		if (packet.type == REQUEST_TYPE)
		{
			if (packet.subtype == LOGOUT_SUBTYPE)
				break;
				
			handle_server_request(qid, &packet);
		}
	}
}

int qid;

void handle_server_queue(key_t key)
{
	write_output(CREATING_SERVER_QUEUE, key);
	qid = msgget(SERVER_KEY, IPC_CREAT | 0660);
	
	if (qid == -1)
	{
		write_output("%s.\n", strerror(errno));
		return;
	}

	nicks[qid] = SYSTEM_NICK;	
	qids[SYSTEM_NICK] = qid;
	groups[SYSTEM_GROUP].insert(qid);
	
	read_server_queue(qid);
	
	groups[SYSTEM_GROUP].erase(qid);
	qids.erase(SYSTEM_NICK);
	nicks.erase(qid);
	
	write_output(REMOVING_SERVER_QUEUE, qid);
	msgctl(qid, IPC_RMID, 0);
}

void handle_server_signal(int number)
{
	signal(SIGINT, handle_server_signal);
	msgctl(qid, IPC_RMID, 0);
}

int main()
{
	create_windows();
	signal(SIGINT, handle_server_signal);
	handle_server_queue(SERVER_KEY);
	sleep(2);
	destroy_windows();
	return 0;
}
