#pragma once

void send_login_request(int queue, int pid);
void send_logout_request(int queue);
void send_nick_request(int queue, const char* nick);
void send_join_request(int queue, const char* group);
void send_part_request(int queue, const char* group);
void send_private_request(int queue, const char* recipient, const char* message);
void send_group_request(int queue, const char* group, const char* message);
