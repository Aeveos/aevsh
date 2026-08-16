#include "exec/builtins.h"
#include "frontend/lexer.h"

struct Command builtIn_cmd[] = { {"exit", cmd_exit, "Used to exit the shell. "},
								 {"help", cmd_help, "Description of builtin commands. "},
								 {"cd", cmd_cd, "Changes the working directory of the shell. "},
								 {"pwd", cmd_pwd, "Prints the Working Directory."} };

#define CMD_COUNT (sizeof(builtIn_cmd) / sizeof(struct Command)) 

int args_count = 0;

int cmd_exit(char args[64][256], int args_count) {
	printf("GoodBye Dear User!!!");
	exit(0);

	return 0;
}

int cmd_help(char args[64][256], int args_count) {

	printf("Aevsh : List of all commands : Total = %d\n", CMD_COUNT);
	printf("\n");
	printf("Name\t\tDescription");
	printf("\n");

	for (int i = 0; i < CMD_COUNT;i++) {
		printf("%s\t\t%s \n", builtIn_cmd[i].cmd_name, builtIn_cmd[i].description);
	}

	printf("\n");

	return 0;
}

int cmd_cd(char args[64][256], int args_count) {

	if (args_count < 2)
		printf("Please define the directory.\n");
	else {

		if (_chdir(args[1]) != 0) {
			printf("Error : Directory not found! \n");
		}
	}

	return 0;
}

int cmd_pwd(char args[64][256], int args_count) {

	char pwd[256];

	if (_getcwd(pwd, sizeof(pwd)) != 0) {
		printf("%s", pwd);
	}
	else {
		printf("Unable to print the current working directory");
	}

	return 0;
}

int execute_builtins(char args[64][256], int args_count) {

	for (int i = 0; i < CMD_COUNT;i++) {

		if (strcmp(args[0], builtIn_cmd[i].cmd_name) == 0) {
			builtIn_cmd[i].func(token, token_count);
		}
	}

	return 0;
}

