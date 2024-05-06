/*
 * CSE Programming assignment 3 
 *
 * removes line and block comments from a source file
 * comments are replaced with a single space
 * while writing all other stdin to stdout
 * handles single and double quoted sequences
 * Ignores line continuation characters
 *
 * error handling:
 *     prints starting line for unterminated comment sequences
 */

#include <stdio.h>
#include <stdlib.h>
#include "states.h"

int
main(void)
{

int c;
int temp = 0;
int startline;
int state = START;
while ((c = getchar()) != EOF) {
	if (c == '\n'){
		temp += 1;
	}
	else if (state == STAR){
	       startline = temp;
	}	       
	switch (state) {
	case START:
		state = STARTstate(c);
		break;
	case SLASH:
		state = SLASHstate(c);
		break;
	case QUOTE:
		state = QUOTEstate(c);
		break;
	case APOS:
		state = APOSstate(c);
		break;
	case DOUBLE:
		state = DOUBLEstate(c);
		break;
	case STAR:
		state = STARstate(c);
	        break;	
	case DSTAR:
		state = DSTARstate(c);
		break;
	case QUOTE_2:
		state = QUOTE_2state(c);
		break;
	case APOS_2:
		state = APOS_2state(c);
		break;
	default:
		fprintf(stderr, "Error: Invalid state (%d)\n", state);
		return EXIT_FAILURE;
	}
}

	if ((state != STAR) && (state != DSTAR)) { 
		 return EXIT_SUCCESS;
	}
	else {
		fprintf(stderr, "Error: line %d: unterminated comment\n", startline);
		return EXIT_FAILURE;
	}
}
