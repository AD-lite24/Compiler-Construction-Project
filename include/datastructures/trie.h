#ifndef TRIE_H
#define TRIE_H

#include "../../include/tokens/tokens.h"
typedef struct Trie * TRIE;

struct Trie{
    char c;
    TRIE next[26];
    enum Token tk;
};

void insertIntoTrie(TRIE root, char* word, enum Token tk);

enum Token lookupTrie(TRIE root, char* word);

TRIE populateTrie();

#endif