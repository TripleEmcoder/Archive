#pragma once

void send_login_request(int qid, int pid);
void send_logout_request(int qid);
void send_nick_request(int qid, const char* nick);
void send_groups_request(int qid);
void send_join_request(int qid, const char* group);
void send_part_request(int qid, const char* group);
void send_users_request(int qid, const char* group);
void send_private_request(int qid, const char* recipient, const char* message);
void send_group_request(int qid, const char* group, const char* message);
