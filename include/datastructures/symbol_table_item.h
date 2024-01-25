#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAXLEN 1024


typedef struct LineReferenceList {
    int line;
    struct LineReferenceList* next;
    int type;
} ref_list;

typedef ref_list* REFLIST;

typedef struct NodeItem
{
    // char name[MAXLEN];
    // int size;
    // int scope;
    char* val;
} node_item;

node_item createNewItem(char* val);

#endif
