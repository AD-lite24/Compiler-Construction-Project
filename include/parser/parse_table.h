#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H

#include "grammar.h"
#include "parser.h"

ProdRule ParseTable[52][58];

Terminals * computeFirstSpecial(ProdRule rule, grammar G);
Terminals * computeFollowSpecial(ProdRule rule, grammar G);


// FirstAndFollow    ComputeFirstAndFollowSets (grammar G);

ProdRule** createParseTable(FirstAndFollow F, ProdRule** parseTable);

// parseInputSourceCode(char *testcaseFile, table T);

// printParseTree(parseTree PT, char *outfile); 

#endif