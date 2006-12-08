#pragma once

void send_private_notify(int queue, int sender, const char* message);
void send_group_notify(int queue, int sender, const char* group, const char* message);
