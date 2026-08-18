// Shell.c : Defines the entry point for the application.

#include "frontend/lexer.h"
#include "exec/builtins.h"
#include "core/core.h"

char input[256];
int builtins_success = 0;
int _spawnvp_success = 0;
int strcspn_size = 0;

int main()
{
	
	while (1) {

		token_count = 0;

		char pwd[256];
		_getcwd(pwd, sizeof(pwd));
		printf("%s> ", pwd);

		if (fgets(input, sizeof(input), stdin) != NULL) {

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
					printf("'%s' is not recognized as an internal or external command,\noperable program or batch file.\n", args[0]);
					printf("\n");
				}

		    }

		}
		else {
			printf("Error : Code 1"); 
		}
	}
}