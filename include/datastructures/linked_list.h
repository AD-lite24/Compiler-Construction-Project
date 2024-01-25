#ifndef LINKED_L
#define LINKED_L

#include "datastructures/symbol_table_item.h"

typedef struct Node {
    node_item item;
    NODE next;
} node;

typedef struct LinkedList {
    NODE head;
    int count;
} ll;

typedef node* NODE;
typedef ll* LL;

LL createNewList();

NODE createNewNode(node_item data);

void freeNode(NODE node);

void insertNodeFirst(NODE node, LL list);

void insertNodeLast(NODE node, LL list);

void removeNodeFirst(LL list);

void removeNodeLast(LL list);

#endif