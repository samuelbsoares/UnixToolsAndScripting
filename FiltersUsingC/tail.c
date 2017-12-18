#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "ensureCap.h"

int n;
int processedLines;

typedef struct {
	char * content;
	ssize_t size;
} lineList;

lineList * * tailLines;

char* init(int argc, char *argv[]) {
	if(argc == 2) {
		n = atoi(argv[1]);
		processedLines = 0;
		tailLines = malloc( n * sizeof( struct lineList * ) );
		if( tailLines ) {
			for( int i = 0; i < n; ++i ) {
				if ( tailLines[ i ] = malloc( sizeof( lineList ) ) ) {
					tailLines[ i ]->content = calloc( 1, sizeof( char ) );
					tailLines[ i ]-> content[0] = '\0';
					tailLines[ i ]->size = 0;
				} else {
					return "Error allocating char!";
				}
			}
			return NULL;
		} else {
			return "Error allocating memory.";
		}
	} else {
		return "Needs two arguments: num\n";
	}
}

void process(char **line, ssize_t *num, size_t *len) {
	if( n > 0 ) {
		// saves pointer to element that is going to
		// be replaced when shifting elements
		// and deletes its content
		lineList * tmp = tailLines[n - 1];
		// shifts elements
		for( int i = n - 2; i >= 0; --i )
			tailLines[i + 1] = tailLines[i];
		tailLines[0] = tmp;
		// enters all data in the last slot
		ensurecapacity( &( tmp->content ), &( tmp->size ), *num + 1 );
		memcpy( tmp->content, *line, ( *num + 1 ) * sizeof( char ) );
		( *line )[*num] = '\0';
		tmp->size = *num;
		// line processed!
		if( processedLines < n ) ++processedLines;
	}
	// sets num to avoid printing
	*num = 0;
}

void finalize(char **line, ssize_t *num, size_t *len) {
	int totalSize = 0;
	memset( *line, '\0', sizeof( *line ) );
	*num = 1;
	// concatenates last processed lines into the buffer and updates num
	for( ; processedLines > 0; processedLines-- ) {
		lineList * current = tailLines[processedLines - 1];
		totalSize += current->size;
		ensurecapacity( line, num, totalSize + 1 );
		(*line)[totalSize] = '\0';
		strcat( *line, current->content );
		// frees char array
		free( current->content );
		free( current );
		//current = NULL;
	}
	// frees the array of pointers
	free( tailLines );
	//tailLines = NULL;
	*num = totalSize;
}
