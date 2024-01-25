#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHTABLE_SIZE 5000

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


typedef struct h_item {
    long long int key;
    char value[30];
} h_item;

typedef h_item* H_ITEM;

typedef struct hashtable {
    LL* items;
    int count;
} htable;

typedef htable* HTABLE;

H_ITEM createItem(long long int key, char *value);

HTABLE createTable();

// void printTable(HTABLE table);

void htInsert(HTABLE table,char *value);

void freeItem(H_ITEM item);

void freeTable(HTABLE table);

int hashfunction(char* name);

#endif 
