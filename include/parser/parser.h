#ifndef PARSER_H
#define PARSER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructures/linked_list_parser.h"

#define NUM_NONTERMS 52
#define NUM_TERMS 58
#define NUM_ELEMENTS 111
#define NUM_EQN 50

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

void trim(char *str);
Elements stringToEnum(char *str);
void printHEHE(LL_LL eqn);
void printFirollow(FIRSTANDFOLLOW fnf, Elements id);
GRAMMAR parseFile(char *filename);
int checkEpsilonInFirst(LL_ELE first);
void ComputeFirst(GRAMMAR G, FIRSTANDFOLLOW firstAndFollowSet);
void ComputeFollow(GRAMMAR G, FIRSTANDFOLLOW firstAndFollowSet);

// Elements *computeFirstSpecial(ProdRule rule);
// Elements *computeFollowSpecial(ProdRule rule);
Elements *computeFollowSpecial(ProdRule rule, FIRSTANDFOLLOW firstAndFollowSet);
Elements *computeFirstSpecial(Elements lhs, LL_ELE rule, FIRSTANDFOLLOW firstAndFollowSet);

FIRSTANDFOLLOW ComputeFirstAndFollowSets(GRAMMAR G);





#endif