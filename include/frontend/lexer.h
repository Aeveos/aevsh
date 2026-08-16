#pragma once

extern int index;
extern int quotes;
extern int index_start;
extern int token_length;
extern char token[64][256];
extern int token_count;

int lexer(char input[256]);