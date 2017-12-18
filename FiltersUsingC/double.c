#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "ensureCap.h"

int n;

char* init(int argc, char *argv[]) {
	if(argc == 1) {
		return NULL;
	} else {
		return "Needs no arguments: num\n";
	}
}

void process(char **line, ssize_t *num, size_t *len) {
	char arr[*num * 2];
	for( int i = 0; i < *num; ++i ) {
		arr[2*i] = (*line)[i];
		arr[2*i+1] = (*line)[i];
	}
	arr[(*num) * 2 - 1] = '\0';
	ensurecapacity( line, len, (*num) * 2 );
	*num = *num * 2;
	memcpy( *line, arr, sizeof(char) * (*num) );
}

void finalize(char **line, ssize_t *num, size_t *len) {
	*num = 0;
}
