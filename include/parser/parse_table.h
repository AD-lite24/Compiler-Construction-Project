#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H

#include "parser.h"


#include <stdio.h>
#include <stdlib.h>

ProdRule ParseTable[NUM_NONTERMS][NUM_ELEMENTS-NUM_NONTERMS-1];

ProdRule convertLLtoProd(int i, NODE_LL rule);

// FirstAndFollow    ComputeFirstAndFollowSets (grammar G);

void createParseTable(FIRSTANDFOLLOW F, ProdRule **parseTable);

// void parseInputSourceCode(char *testcaseFile, table T);

// printParseTree(parseTree PT, char *outfile);

#endif