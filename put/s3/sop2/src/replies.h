#pragma once

#include "protocol.h"

void send_groups_reply(int qid, int count,
	const char groups[MAX_GROUPS][MAX_GROUP+1]);

void send_users_reply(int qid, const char* group, int count,
	const char nicks[MAX_NICKS][MAX_NICK+1]);
