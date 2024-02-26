#ifndef LINKED_L
#define LINKED_L

// #include "symbol_table/symbol_table.h"
#include "parser/parser.h"
#include "parser/grammar.h"

typedef struct NodeEle {
    Elements item;
    struct NodeEle* next;
} node_Ele;

typedef node_Ele* NODE_ELE;
typedef struct LinkedListEle {
    NODE_ELE head;
    int count;
} ll_ele;
typedef ll_ele* LL_ELE;

typedef struct NodeLL {
    LL_ELE item;
    struct NodeLL* next;
} node_LL;
typedef node_LL* NODE_LL;
typedef struct LinkedListLL {
    NODE_LL head;
    int count;
} ll_ll;
typedef ll_ll* LL_LL;

LL_LL createNewList_LL();
NODE_LL createNewNode_LL(LL_ELE data);
void freeNode_LL(NODE_LL node);
void insertNode_LLFirst(NODE_LL node, LL_LL list);
void insertNode_LLLast(NODE_LL node, LL_LL list);
void removeNode_LLFirst(LL_LL list);
void removeNode_LLLast(LL_LL list);
void freeLL_LL(LL_LL list);

LL_ELE createNewList_Ele();
NODE_ELE createNewNode_Ele(Elements data);
void freeNode_Ele(NODE_ELE node);
void insertNode_EleFirst(NODE_ELE node, LL_ELE list);
void insertNode_EleLast(NODE_ELE node, LL_ELE list);
void removeNode_EleFirst(LL_ELE list);
void removeNode_EleLast(LL_ELE list);
void freeLL_ELE(LL_ELE list);

#endif


