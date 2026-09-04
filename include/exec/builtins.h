#pragma once

#ifdef _WIN32

#include <Windows.h>

#endif

#ifdef __linux__

#include unistd.h

#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>

#define RESET   "\033[0m"
#define GREEN   "\033[32m" // Green
#define RED     "\033[31m" // Red
#define YELLOW  "\033[33m"
#define BOLDGREEN   "\033[1m\033[32m" // Bold Green
#define BOLDRED  "\033[1m\033[31m" // Bold Red

extern int args_count;

struct Command {
	char* cmd_name;
	int (*func)(char args[64][256], int args_count);
	char description[256];
	// char thorough[256];
};


int cmd_clear(char args[64][256], int args_count);
int cmd_pwd(char args[64][256], int args_count);
int cmd_cd(char args[64][256], int args_count);
int cmd_exit(char args[64][256], int args_count);
int cmd_echo(char args[64][256], int args_count);
int cmd_help(char args[64][256], int args_count);
int cmd_his(char args[64][256], int args_count);
int execute_builtins(char args[64][256], int args_count);