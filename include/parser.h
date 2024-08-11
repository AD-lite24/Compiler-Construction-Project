#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "parserDef.h"

LL_LL createNewList_LL();
NODE_LL createNewNode_LL(LL_ELE data); //
void freeNode_LL(NODE_LL node);
void insertNode_LLFirst(NODE_LL node, LL_LL list);
void insertNode_LLLast(NODE_LL node, LL_LL list); //
// void removeNode_LLFirst(LL_LL list);
// void removeNode_LLLast(LL_LL list);
void freeLL_LL(LL_LL list);

LL_ELE createNewList_Ele(); //
NODE_ELE createNewNode_Ele(Elements data); //
void freeNode_Ele(NODE_ELE node);
void insertNode_EleFirst(NODE_ELE node, LL_ELE list); 
void insertNode_EleLast(NODE_ELE node, LL_ELE list); //
void removeNode_EleFirst(LL_ELE list); //
// void removeNode_EleLast(LL_ELE list);
void freeLL_ELE(LL_ELE list);

Stack* createStack(); //
void push(Stack* stack,Elements element); //
Elements top(Stack* stack); //
void pop(Stack* stack); //
// bool isEmpty(Stack* stack); 

void synchPopulateParseTable(FIRSTANDFOLLOW Fnf);
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