#ifndef PARSER_H
#define PARSER_H

#include "../datastructures/linked_list_parser.h"
#include "../datastructures/stack_parser.h"
#include "../lexer/lexer.h"
#include "../lexer/lexerDef.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TERMS 58
#define NUM_NONTERMS 53
#define NUM_ELEMENTS 113

typedef struct grammar {
    LL_LL rules[NUM_NONTERMS];
} grammar;
typedef grammar *GRAMMAR;

// GRAMMAR grammar_glob;

typedef struct FirstAndFollow {
    LL_ELE firstSet[NUM_ELEMENTS];
    LL_ELE followSet[NUM_NONTERMS];
} FirstAndFollow;

typedef struct FirstAndFollow *FIRSTANDFOLLOW;

struct ProdRule {
    Elements LHS;
    Elements RHS[10];
    int count_rhs;
};

typedef struct ProdRule ProdRule;

// ProdRule ParseTable[NUM_NONTERMS][NUM_TERMS+1];
struct TreeNode {
    Elements x;     // NodeSymbol
    int lineNumber; // lineno
    char *value;    // ValueIfNumber
    char *lexeme;   // lexeme

    struct TreeNode *children[10];
    struct TreeNode *parent; // ParentNodeSymbol
    int count_children;      // isLeafNode
};

typedef struct TreeNode TreeNode;
typedef TreeNode *TREE_NODE;

Elements stringToEnum(char *str);
void parseFile(char *filename);
int checkEpsilonInFirst(LL_ELE first);
void ComputeFirst(FIRSTANDFOLLOW firstAndFollowSet);
void ComputeFollow(FIRSTANDFOLLOW firstAndFollowSet);

FIRSTANDFOLLOW ComputeFirstAndFollowSets();

ProdRule convertLLtoProd(Elements lhs, NODE_LL rule);
void initialiseParseTable();
void entryIntoParseTable(FIRSTANDFOLLOW F, Elements lhs, ProdRule rule);
void createParseTable(FIRSTANDFOLLOW F);
TREE_NODE createTreeNode(Elements x, TREE_NODE parent, returnToken *k);
int createParseTree(Stack *st, TREE_NODE root, returnToken *flag);
TREE_NODE parseInputSourceCode();
void printParseTree(TREE_NODE root, char *outfile);

#endif