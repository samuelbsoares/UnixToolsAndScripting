#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void err(char* msg);

int main(int argc, char* argv[]) {

	char* errMsg = init(argc, argv);
	if(errMsg) {
		err(errMsg);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while ((nread = getline(&line, &len, stdin)) != -1) {
		process(&line, &nread, &len);
		fwrite(line, nread, 1, stdout);
	}
	finalize(&line, &nread, &len);
	fwrite(line, nread, 1, stdout);
	free(line);

	if(ferror(stdout) || ferror(stdin)) {
		perror("I/O error in main.");
		err("");
	}
	exit(EXIT_SUCCESS);
}

void err(char* msg) {
	if(msg != NULL && msg[0] != '\0') {
		fputs(msg, stderr);
	}
	exit(EXIT_FAILURE);
}
