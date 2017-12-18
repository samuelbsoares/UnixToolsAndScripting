#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "ensureCap.h"

char to;
char from;

char* init(int argc, char *argv[]) {
	if(argc == 3) {
		from = *(argv[1]);
		to = *(argv[2]);
		return NULL;
	} else {
		return "Needs two arguments: num\n";
	}
}

void process(char **line, ssize_t *num, size_t *len) {
	for( char * i = *line; i < *line + *num - 1; ++i )
		if( *i == from ) {
			*i = to;
		}
}

void finalize(char **line, ssize_t *num, size_t *len) {
	*num = 0;
}
