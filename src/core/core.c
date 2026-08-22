// Shell.c : Defines the entry point for the application.

// Tasks : 1.Improve how the shell works with cmd.exe to run its commands. 2.Add autocompletion 3. Improve the lexer

#include "frontend/lexer.h"
#include "exec/builtins.h"
#include "core/core.h"

char input[256];
char pwd[256];
char history[10][256];
int history_count = 0;
int builtins_success = 0;
intptr_t _spawnvp_success = 0;
int system_success = 0;

int main() {
	
	while (1) {

		token_count = 0;
		// free(pwd);

		if (_getcwd(pwd, sizeof(pwd)) == NULL) {

			perror("_getcwd error");

		}
		printf("%s> ", pwd);

		if (fgets(input, sizeof(input), stdin) != NULL) {

			if (input[0] == '\n' || '\0') {

				continue;

			}

			strcpy_s(history[history_count], sizeof(history[history_count]), input);
			history_count++;

			lexer(input);

			fflush(stdin);

			builtins_success = execute_builtins(token, token_count);

			if (builtins_success == 1) {
				char* args[64];

				for (int i = 0;i < token_count;i++) {

					args[i] = token[0];

				}

				args[token_count] = NULL;

				_spawnvp_success = _spawnvp(_P_WAIT, args[0], args);

				if (_spawnvp_success < 0) {

					system_success = system(input);

					if (system_success < 0) {

						printf("'%s' is not recognized as an internal or external command,\noperable program or batch file.\n", args[0]);

						printf("\n");

					}

					/*printf(RED "'%s' is not recognized as an internal or external command,\noperable program or batch file.\n" RESET, args[0]);

					printf("\n");*/


				}

			}

		}
		else {

			printf(BOLDRED "Error : Code 1" RESET);

		}
	}
	
}