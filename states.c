/*
 * State handler routines for PA3
 * one function for each state of the DFA
 * each function is passed current input and returns next state
 */
#include <stdio.h>
#include "states.h"

int STARTstate(int c)
{
	if (c == '/'){
		return SLASH;
	} 
	else if (c == '"'){
		putchar('"');
		return QUOTE;
	}
	else if (c == '\''){
		putchar('\'');
		return APOS;
	}
	else {
		putchar(c);
		return START;
	}
}

int SLASHstate(int c)
{
	if (c == '/'){
		putchar(' ');
		return DOUBLE;
	} 
	else if (c == '*'){
		putchar(' ');
		return STAR;
	}
	else if (c == '"'){
		putchar('/');
		putchar('"');
		return QUOTE;
	}
	else if (c == '\''){
	       putchar('/');
	       putchar('\'');
	       return APOS;
	}	       
	else {
		putchar('/');
		putchar(c);
		return START;
	}
}

int QUOTEstate(int c)
{
	if (c == '\\'){
		putchar('\\');
		return QUOTE_2;
	}
	else if (c == '"'){
		putchar('"');
		return START;
	}
	else{
		putchar(c);
		return QUOTE;
	}
}

int APOSstate(int c)
{
	if (c == '\\'){
		putchar('\\');
		return APOS_2;
	}
	else if (c == '\''){
		putchar('\'');
		return START;
	}
	else {
		putchar(c);
		return APOS;
	}
}

int DOUBLEstate(int c)
{
	if (c == '\n'){
		putchar('\n');
		return START;
	}
	else {
		return DOUBLE;
	}
} 

int STARstate(int c)
{
	if (c=='*'){
		return DSTAR;
	}
	else if (c == '\n'){
		putchar('\n');
		return STAR;
	}
	else{
		return STAR;
	}
}

int QUOTE_2state(int c)
{
	putchar(c);
	return QUOTE;
}

int APOS_2state(int c)
{
	putchar(c);
	return APOS;
}

int DSTARstate(int c)
{
	if (c == '/'){
		return START;
	}
	else if (c == '*'){
		return DSTAR;
	}
	else if (c == '\n'){
		putchar('\n');
		return STAR;
	}
	else{
		return STAR;
	}
} 
