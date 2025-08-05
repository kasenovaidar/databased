#include "parser.h"

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

// Принимает строку запроса и возвращает указатель на массив токенов
// count - количество токенов
// возвращает  NULL если токены не были считаны
Token *get_tokens(const char *query, size_t *count) {
	const char *p = query;
	Token *tokens = NULL;
	*count = 0;

	for (;;) {
		Token token = get_next_token(&p);
		if (token.type == TOKEN_EOF) {
			break;
		}

		tokens = realloc(tokens, ++(*count) * sizeof(Token));
		tokens[(*count) - 1] = token;
	}
	
	return tokens;
}

