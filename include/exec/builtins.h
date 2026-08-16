#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>

extern int args_count;

struct Command {
	char* cmd_name;
	int (*func)(char args[64][256], int args_count);
	char description[256];
};

int cmd_exit(char args[64][256], int args_count);
int cmd_help(char args[64][256], int args_count);
int cmd_cd(char args[64][256], int args_count);
int cmd_pwd(char args[64][256], int args_count);
int execute_builtins(char args[64][256], int args_count);
