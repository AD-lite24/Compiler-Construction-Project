#ifndef LINKED_L
#define LINKED_L

#include "datastructures/symbol_table_item.h"

typedef struct Node {
    char* item;
    struct Node* next;
} node;

typedef node* NODE;

typedef struct LinkedList {
    NODE head;
    int count;
} ll;
typedef ll* LL;

LL createNewList();

NODE createNewNode(char* data);

void freeNode(NODE node);

void insertNodeFirst(NODE node, LL list);

void insertNodeLast(NODE node, LL list);

void removeNodeFirst(LL list);

void removeNodeLast(LL list);

void freeLL(LL list);

#endif


