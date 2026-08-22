#include "exec/builtins.h"
#include "frontend/lexer.h"

struct Command builtIn_cmd[] = { {"exit", cmd_exit, "Used to exit the shell. "},
								 {"help", cmd_help, "Description of builtin commands. "},
								 {"cd", cmd_cd, "Changes the working directory of the shell. "},
								 {"pwd", cmd_pwd, "Prints the Working Directory."},
                                 {"clear", cmd_clear, "Clears the terminal. "},
	                             {"echo", cmd_echo, "Prints text to the terminal. "}};

#define CMD_COUNT (sizeof(builtIn_cmd) / sizeof(struct Command)) 

int args_count = 0;

int cmd_clear(char args[64][256], int args_count) {

#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	return 0;
}

int cmd_pwd(char args[64][256], int args_count) {

	char pwd[256];

	if (_getcwd(pwd, sizeof(pwd)) == NULL) {
		perror("_getcwd error in builtins.h");
		printf("\n");
	}	
	else {
		printf("%s\n", pwd);
		printf("\n");
	}

	return 0;

}

int cmd_cd(char args[64][256], int args_count) {

	if (args_count < 2) {
		printf("Please define the directory.\n");
		printf("\n");
	}
	else {

		if (_chdir(args[1]) != 0) {
			printf("Error : Directory not found! \n");
			printf("\n");
		}
	}

	return 0;
}

int cmd_exit(char args[64][256], int args_count) {
	//printf("GoodBye Dear User!!!");
	exit(0);

	return 0;
}

int cmd_echo(char args[64][256], int args_count) {

	for (int i = 1;i < token_count; i++) {
		printf("%s ", args[i]);
	}
	printf("\n");
}

int cmd_help(char args[64][256], int args_count) {

	printf("Name\t\tDescription");
	printf("\n");

	for (int i = 0; i < CMD_COUNT;i++) {
		printf("%s\t\t%s \n", builtIn_cmd[i].cmd_name, builtIn_cmd[i].description);
	}

	printf("\n");

	return 0;
}

int execute_builtins(char args[64][256], int args_count) {

	for (int i = 0; i < CMD_COUNT;i++) {

		if (strcmp(args[0], builtIn_cmd[i].cmd_name) == 0) {
			builtIn_cmd[i].func(token, token_count);
			return 0;
		}
	}

	return 1; // Not Found in Builtin commands.
}