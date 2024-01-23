#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int c;

	(void)argc;
	(void)argv;
	
	while ((c = getc(stdin)) != EOF) {
		if (putc(c, stdout) == EOF) {
			fprintf(stderr, "Failed to write: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}

	if (ferror(stdin)) {
		fprintf(stderr, "Failed to read: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
