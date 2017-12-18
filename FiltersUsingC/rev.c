#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "ensureCap.h"

char* init(int argc, char *argv[]) {
	if(argc == 1) {
		return NULL;
	} else {
		return "Needs two arguments: num\n";
	}
}

void swap(char * a, char * b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void process(char **line, ssize_t *num, size_t *len) {
	for( int i = 0; i < *num / 2; ++i )
		swap( *line + i, *line + *num - i - 2 );
}

void finalize(char **line, ssize_t *num, size_t *len) {
	*num = 0;
}
