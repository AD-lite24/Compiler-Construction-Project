#ifndef GRAMMAR_H
#define GRAMMAR_H

#define NUM_NONTERMS 52
#define NUM_ELEMENTS 111
#define NUM_EQN 50

#include "datastructures/linked_list.h"
#include "parser.h"


typedef struct grammar {
    LL_LL rules[NUM_NONTERMS];
} grammar;
typedef grammar *GRAMMAR;

GRAMMAR grammar_glob;

typedef struct FirstAndFollow {
    LL_ELE firstSet[NUM_ELEMENTS];
    LL_ELE followSet[NUM_NONTERMS];
} FirstAndFollow;

typedef struct FirstAndFollow *FIRSTANDFOLLOW;

GRAMMAR parseFile(char *filename);
FIRSTANDFOLLOW ComputeFirstAndFollowSets(GRAMMAR G);

struct ProdRule {
    Elements LHS;
    Elements RHS[10];
};

typedef struct ProdRule ProdRule;

#endif