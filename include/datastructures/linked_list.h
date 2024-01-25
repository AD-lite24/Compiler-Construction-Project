#ifndef LINKED_L
#define LINKED_L

typedef struct Item {

} node_item;

typedef struct Node {
    node_item* item;
    node* next;
} node;

typedef struct LinkedList {
    node* head;
    int count;
} ll;



#endif