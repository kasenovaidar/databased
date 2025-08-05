#include "db_types.h"

void process_create(char *input_buffer, size_t buffer_length) {
	printf("CREATE COMMAND PROCESSED\n");
}

int main() {
	printf("It's main function of a database\n");

	char *input_buffer;
	size_t buffer_length;
	// REPL
	for (;;) {
		printf("> ");
		ssize_t bytes_read = getline(&input_buffer, &buffer_length, stdin);

		if (bytes_read <= 0) {
			printf("Error reading input\n");
			exit(EXIT_FAILURE);
		}

		if (strncmp(input_buffer, "exit", 4) == 0) {
			break;
		}
		else if (strncmp(input_buffer, "create", 6) == 0) {
			process_create(input_buffer, buffer_length);
		}
		else {
			printf("Unrecognized command.\n");
			continue;
		}
	}	

	return 0;
}
	
