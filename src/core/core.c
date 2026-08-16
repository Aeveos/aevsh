// Shell.c : Defines the entry point for the application.

#include "frontend/lexer.h"
#include "exec/builtins.h"
#include "core/core.h"

#define CMD_COUNT (sizeof(builtIn_cmd) / sizeof(struct Command)) 

char input[256];
int num = 0;

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
		execute_builtins(token, token_count);

	}
}