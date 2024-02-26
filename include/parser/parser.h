#ifndef PARSER_H
#define PARSER_H

#include "include/datastructures/linked_list_parser.h"
#include "include/datastructures/stack_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NONTERMS 53
#define NUM_ELEMENTS 113

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
    int count_rhs;
};

typedef struct ProdRule ProdRule;

struct TreeNode {
    Elements x;
    struct TreeNode * children[10];
    struct TreeNode * parent;
    struct TreeNode * right_sibling;
    int count_children;
};

typedef struct TreeNode TreeNode;
typedef TreeNode *TREE_NODE;

void insertIntoTree(TREE_NODE root, ProdRule rule);

TREE_NODE createTreeNode(Elements x);

Elements stringToEnum(char *str);
GRAMMAR parseFile(char *filename);
int checkEpsilonInFirst(LL_ELE first);
void ComputeFirst(GRAMMAR G, FIRSTANDFOLLOW firstAndFollowSet);
void ComputeFollow(GRAMMAR G, FIRSTANDFOLLOW firstAndFollowSet);

FIRSTANDFOLLOW ComputeFirstAndFollowSets(GRAMMAR G);

#endif