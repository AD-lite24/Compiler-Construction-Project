#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include "tokens/tokens.h"

#define BUFFER_SIZE 1024

FILE *removeComments(FILE *testcaseFile, FILE *cleanFile);

char *getLexeme(char *begin, char *forward);

void failure();

void printToken(Token tk);

void initializeBuffers();

void reloadBuffer(char *buf);

void incrementLexemeBegin(int val);

void decrementForward(int val);

void incrementForward();

Token getNextToken();

void printTokens();


#endif