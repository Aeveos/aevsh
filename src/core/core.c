// Shell.c : Defines the entry point for the application.

#include "frontend/lexer.h"
#include "exec/builtins.h"
#include "core/core.h"

#define CMD_COUNT (sizeof(builtIn_cmd) / sizeof(struct Command)) 

char input[256];
int num = 0;
int builtins_success = 0;

int main()
{
	
	while (1) {
		token_count = 0;

		char pwd[256];
		_getcwd(pwd, sizeof(pwd));
		printf("%s> ", pwd);

		if (fgets(input, sizeof(input), stdin)) {
			if (1 == sscanf(input, "%d", &num)) {

			}
		}
		fflush(stdin);

		lexer(input);
		
		builtins_success = execute_builtins(token, token_count);
		if (builtins_success == 1) {
			char* args[64];

			for (int i = 0;i < token_count;i++) {
				args[i] = token[0];
			}

			args[token_count] = NULL;

			_spawnvp(_P_WAIT, args[0], args);

		}

	}
}