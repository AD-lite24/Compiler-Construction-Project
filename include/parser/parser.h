#ifndef PARSER_H
#define PARSER_H

#include "grammar.h"

Terminals* First(char* nonterm);

Terminals* Follow(char* nonterm);

#endif