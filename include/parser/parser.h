#ifndef PARSER_H
#define PARSER_H

#include "grammar.h"
// #include "../datastructures/hashtable.h"
#include "../datastructures/linked_list.h"
#define NUM_NONTERMS 53
#define NUM_EQN 50



// Terminals* First(char* nonterm);

// Terminals* Follow(char* nonterm);


typedef struct grammar {
    LL rules [NUM_NONTERMS];
}grammar;
typedef grammar* GRAMMAR;

typedef struct FirstAndFollow {
    Elements* firstSet[NUM_NONTERMS];
    Elements* followSet[NUM_NONTERMS];
}FirstAndFollow;
typedef struct FirstAndFollow* FIRSTANDFOLLOW;

GRAMMAR parseFile(char *filename);

#endif