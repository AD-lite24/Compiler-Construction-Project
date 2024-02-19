#ifndef PARSER_H
#define PARSER_H

#include "grammar.h"
#include "../datastructures/hashtable.h"
#define NUM_NONTERMS 49

Terminals firstSet[NUM_NONTERMS][20];
Terminals followSet[NUM_NONTERMS][20];

Terminals* First(char* nonterm);

Terminals* Follow(char* nonterm);

void parseFile(char *filename, int table_type);

#endif