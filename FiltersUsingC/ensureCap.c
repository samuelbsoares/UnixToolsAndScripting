#include <stdlib.h>
#include <stdio.h>
#include "ensureCap.h"

void ensurecapacity(char **buff, size_t *before, size_t after) {
	if(*before < after) {
		if(*buff = realloc(*buff, after * sizeof(char))) {
			*before = after;
		} else {
			fputs("Failed to (re)alloc memory.\n", stderr);
			exit(EXIT_FAILURE);
		}
	}
}
