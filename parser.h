#ifndef PARSER
#define PARSER

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
	TOKEN_KEYWORD,
	TOKEN_NUMBER,
	TOKEN_UNKNOWN,
	TOKEN_EOF
} TokenType;

typedef struct {
	TokenType type;
	char value[64];
} Token;

Token get_next_token(const char **input);
Token *get_tokens(const char *query, size_t *count);

#endif // PARSER
