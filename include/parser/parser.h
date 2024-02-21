#ifndef PARSER_H
#define PARSER_H

#include "grammar.h"
// #include "../datastructures/hashtable.h"
#include "../datastructures/linked_list.h"
#define NUM_NONTERMS 52
#define NUM_ELEMENTS 111
#define NUM_EQN 50

// Terminals* First(char* nonterm);

// Terminals* Follow(char* nonterm);

void trim(char * str);
Elements stringToEnumTerm(char *str);
NonTerminals stringToEnumNonTerm(char *str);

typedef struct grammar {
    LL_LL rules[NUM_NONTERMS];
} grammar;
typedef grammar *GRAMMAR;

typedef struct FirstAndFollow {
    LL_ELE firstSet[NUM_ELEMENTS];
    LL_ELE followSet[NUM_NONTERMS];
} FirstAndFollow;
typedef struct FirstAndFollow *FIRSTANDFOLLOW;

GRAMMAR parseFile(char *filename);

#endif