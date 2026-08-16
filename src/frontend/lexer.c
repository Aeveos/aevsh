#include "frontend/lexer.h"

// #define DEBUG // Comment this preprocessor to turn of debugging

int index = 0;
int quotes = 0;
int index_start = 0;
int token_length = 0;
int token_count = 0;

char token[64][256];

int lexer(char input[256])
{

	while (input[index] != '\0') {

		char current = input[index]; // GG "Hello World"

		if (current == '"') {

			if (quotes == 0) {
				quotes = 1;
			}
			else {
				quotes = 0;
			}
		}
		else if ((current == ' ' || current == '\n' || current == '\0') && quotes == 0) {
			// printf("We hit a boundary!!!");

			token_length = index - index_start; // For Eg. Hello World; 5 - 0 = 5;  2nd Eg when it loops again token lenght will be 11-6 = 5

			strncpy(token[token_count], &input[index_start], token_length); // Destination, Source which is Input from the index start which is 0, and token length which is calculated above.

			token[token_count][token_length] = '\0'; // For example. Token_buffer[token_length] = 5 and 5 is a namespace so thats a end '\0'


#ifdef DEBUG
			printf("Token : %s\n", token[token_count]); // For debbuging
#endif // DEBUG

			index_start = index + 1;
			token_count++;

		}

		else {

		}
		index++;
	}
	index = 0;
	index_start = 0;
	return 0;
}