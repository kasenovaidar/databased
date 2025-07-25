#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
	TOKEN_KEYWORD,
	TOKEN_NUMBER,
	TOKEN_UNKNOWN,
	TOKEN_EOF
} TokenType;

typedef struct {
	TokenType type;
	char value[256];
} Token;

Token get_next_token(const char **input) {
	Token token;
	token.type = TOKEN_UNKNOWN;
	memset(token.value, 0, sizeof(token.value));

	// Skip spaces
	while (isspace(**input)) {
		(*input)++;
	}

	// End of the line
	if (**input == '\0') {
		token.type = TOKEN_EOF;
		return token;
	}

	// Numbers
	if (isdigit(**input)) {
		int i = 0;
		while (isdigit(**input)) {
			token.value[i++] = **input;
			(*input)++;
		}
		token.type = TOKEN_NUMBER;
		return token;
	}

	// Keywords
	if (isalpha(**input) || **input == '_') {
		int i = 0;
		while (isalnum(**input) || **input == '_') {
			token.value[i++] = **input;
			(*input)++;
		}
		token.type = TOKEN_KEYWORD;
		return token;
	}

	token.value[0] = **input;
	(*input)++;
	return token;
}

int main() {
	const char *query = "select * from users where id = 123";
	const char *p = query;

	while (true) {
		Token token = get_next_token(&p);
		if (token.type == TOKEN_EOF) {
			break;
		}

		const char *token_type_str;
		switch (token.type) {
			case TOKEN_KEYWORD:		token_type_str = "KEYWORD"; break;
			case TOKEN_NUMBER:		token_type_str = "NUMBER"; break;
			default:				token_type_str = "UNKNOWN"; break;
		}

		printf("%s\t%s\n", token_type_str, token.value);
	}
	
	return 0;
}
	
