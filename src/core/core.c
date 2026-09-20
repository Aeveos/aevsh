/*Shell.c : Defines the entry point for the application.

Tasks : 1.Improve how the shell works with cmd.exe to run its commands. 2.Add autocompletion 3. Improve the lexer and investigate :

Investigate why system executes echo as its builtin and why it just continues when : is types.

Implement history again
*/

#include <core/core.h>
#include <frontend/lexer.h>
#include <exec/builtins.h>
#include <core/input.h>
#include <Windows.h>
#include <Termiox/termiox.h>

char buffered_input[256];
char history[10][256];
int history_count = 0;
static int builtins_success = 0;
static intptr_t spawnvp_success = 0;
static int system_success = 0;

int main() {

	SetConsoleTitleA("aevsh");

	while (1) {
		token_count = 0;

		PrintWorkingDirectory(COLOR_NONE);
		printf(">");

		input();

		if (unbuffered_input[0] == '\n' || '\0') {
			continue;
		}

		memcpy(history[history_count], unbuffered_input, sizeof(unbuffered_input));
		history_count++;

#ifdef DEBUG
		printf("%s", unbuffered_input);
#endif

		lexer(unbuffered_input);

			builtins_success = execute_builtins(token, token_count);

			if (!builtins_success) {
				char* args[64];

				for (int i = 0;i < token_count;i++) {

					args[i] = token[0];

				}

				args[token_count] = NULL;

				spawnvp_success = _spawnvp(_P_WAIT, args[0], args);

				if (spawnvp_success < 0) {

					system_success = system(unbuffered_input);

					if (system_success < 0) {

						printf("'%s' is not recognized as an internal or external command,\noperable program or batch file.\n", args[0]);

						printf("\n");

					}
				}

			}

		}
	}

