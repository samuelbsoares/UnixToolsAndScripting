#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "ensureCap.h"

int n;

char* init(int argc, char *argv[]) {
	if(argc == 2) {
		n = atoi(argv[1]);
		return NULL;
	} else {
		return "Needs two arguments: num\n";
	}
}

void process(char **line, ssize_t *num, size_t *len) {
	if( ! n )
		*num = 0;
	else
		n--;
}

void finalize(char **line, ssize_t *num, size_t *len) {
	*num = 0;
}
