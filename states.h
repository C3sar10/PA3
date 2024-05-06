/* 
 * Header file for PA3
 */
#ifndef STATES_H
#define STATES_H

/*
 * definitions for DFA states
 */
#define START 0
#define SLASH 1
#define DOUBLE 2
#define STAR 3
#define QUOTE 4
#define APOS 5
#define DSTAR 6
#define QUOTE_2 7
#define APOS_2 8
/*  function prototypes for each state handler of the DFA
 */
int STARTstate(int);
int SLASHstate(int);
int DOUBLEstate(int);
int STARstate(int);
int QUOTEstate(int);
int APOSstate(int);
int DSTARstate(int);
int QUOTE_2state(int);
int APOS_2state(int);

#endif
