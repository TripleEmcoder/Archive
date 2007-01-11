#pragma once

#define MAX_COMMAND              10
#define LOGOUT_COMMAND           "/logout"
#define NICK_COMMAND             "/nick"
#define GROUPS_COMMAND           "/groups"
#define JOIN_COMMAND             "/join"
#define PART_COMMAND             "/part"
#define USERS_COMMAND            "/users"
#define PRIVATE_COMMAND          "/private"
#define GROUP_COMMAND            "/group"

#define UNKNOWN_CLIENT_COMMAND   "Unknown client command (\"%s\").\n"
#define MALFORMED_CLIENT_COMMAND "Malformed command (\"%s\").\n"

#define CREATING_CLIENT_QUEUE    "Creating client message queue (%d).\n"
#define REMOVING_CLIENT_QUEUE    "Removing client message queue...\n"
#define UNKNOWN_CLIENT_NOTIFY    "Unknown client notify (%d).\n"

#define JOINING_SERVER_QUEUE     "Joining server message queue (%d).\n"
#define PARTING_SERVER_QUEUE     "Parting server message queue (%d).\n"

#define SENDING_LOGIN_REQUEST    "Sending login request (%d).\n"
#define SENDING_LOGOUT_REQUEST   "Sending logout request (%d).\n"
