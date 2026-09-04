#pragma once

extern int lexer_index;
extern int quotes;
extern int index_start;
extern int token_length;
extern char token[64][256];
extern int token_count;

extern int lexer(char source[256]);