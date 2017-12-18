#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "ensureCap.h"

int size;
char* end;

char* init(int argc, char *argv[]) {
	if(argc == 2) {
		size = atoi(argv[1]);
		end = malloc(size + 1);
		if(end) {
			memset(end, '\n', size);
			end[size] = '\0';
			return NULL;
		} else {
			return "Failed to malloc memory.\n";
		}
	} else {
		return "Needs one argument: num\n";
	}
}

void process(char **line, ssize_t *num, size_t *len) {
	
	(*line)[(*num) -1] = '\0';
	*num = (*num) -1 + size;
	ensurecapacity(line, len, (*num) + 1);
	strcat(*line, end);
}

void finalize(char **line, ssize_t *num, size_t *len) {
	free(end);
	end = NULL;
	*num = 0;
}
