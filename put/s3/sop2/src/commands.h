#pragma once

void handle_nick_command(int qid, const char* line);
void handle_groups_command(int qid, const char* line);
void handle_join_command(int qid, const char* line);
void handle_part_command(int qid, const char* line);
void handle_users_command(int qid, const char* line);
void handle_private_command(int qid, const char* line);
void handle_group_command(int qid, const char* line);
