#pragma once

void send_private_notify(int qid, const char* sender, const char* message);
void send_group_notify(int qid, const char* sender, const char* group, const char* message);
