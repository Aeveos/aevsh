#include "exec/builtins.h"
#include "frontend/lexer.h"
#include "core/core.h"
#include "Termiox/termiox.h"

static struct Command builtIn_cmd[] = { {.cmd_name = "exit", .func = cmd_exit, .description = "Used to exit the shell. "},
										{.cmd_name = "help", .func = cmd_help, .description = "Description of builtin commands. "},
										{.cmd_name = "cd", .func = cmd_cd, .description = "Changes the working directory of the shell. "},
										{.cmd_name = "pwd", .func = cmd_pwd, .description = "Prints the Working Directory."},
										{.cmd_name = "clear", .func = cmd_clear, .description = "Clears the terminal. "},
										{.cmd_name = "echo", .func = cmd_echo, .description = "Prints text to the terminal. "},
										{.cmd_name = "his", .func = cmd_his, .description = "Prints your command history for your current session. "}};

#define CMD_COUNT (sizeof(builtIn_cmd) / sizeof(struct Command)) 


static int cmd_clear(char args[64][256], int args_count) {

	if(!ClrScreen()) {
		fprintf(stderr, "ClrScreen failed!!");
		return 0;
	}

	return 1;
}

static int cmd_pwd(char args[64][256], int args_count) {

	PrintWorkingDirectory(YELLOW);
	printf("\n \n");

	return 1;

}

static int cmd_cd(char args[64][256], int args_count) {

	if (args_count < 2) {
		printf(RED "Please define the directory.\n" RESET);
		printf("\n");
		return 0;
	}
	else {

		if (_chdir(args[1]) != 0) {
			printf(RED "Error : Directory not found! \n" RESET);
			printf("\n");
			return 0;
		}
	}

	return 1;
}

static int cmd_exit(char args[64][256], int args_count) {
	
	exit(0);

}

static int cmd_echo(char args[64][256], int args_count) {

	for (int i = 1;i < token_count; i++) {
		printf("%s ", args[i]);
	}
	printf("\n");

	return 1;
}

static int cmd_help(char args[64][256], int args_count) {

	printf(BGREEN "Name\t\tDescription" RESET);
	printf("\n");

	for (int i = 0; i < CMD_COUNT;i++) {
		printf("%s\t\t%s \n", builtIn_cmd[i].cmd_name, builtIn_cmd[i].description);
	}

	printf("\n");

	return 1;
}

static int cmd_his(char args[64][256], int args_count) {


	printf(BGREEN "Id\t\tCommandLine\n" RESET);
	printf(BGREEN "--\t\t-----------\n" RESET);

	for(int z = 0; z < history_count-1; z++) {
		printf("%d\t\t%s", z, history[z]);
	}
	printf("\n");

	return 1;
}

int execute_builtins(char args[64][256], int args_count) {

	for (int i = 0; i < CMD_COUNT;i++) {

		if (strcmp(args[0], builtIn_cmd[i].cmd_name) == 0) {

			builtIn_cmd[i].func(token, token_count);

			return 1;

		}

	}
	return 0; // Not Found in Builtin commands.
}

