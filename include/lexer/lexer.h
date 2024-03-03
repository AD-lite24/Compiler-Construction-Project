#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lexerDef.h"


void insertIntoTrie(TRIE root, char *word, enum Token tk);

enum Token lookupTrie(TRIE root, char *word);

TRIE populateTrie();

FILE *removeComments(FILE *testcaseFile, FILE *cleanFile);

char *getLexeme(char *begin, char *forward);

void failure();

void printToken(Token tk);

returnToken makeReturnToken(int flag);

void initializeBuffers();

void reloadBuffer(char *buf);

void incrementLexemeBegin(int val);

void decrementForward(int val);

void incrementForward();

returnToken getNextToken();

void initLexer();

void printTokens();

#endif