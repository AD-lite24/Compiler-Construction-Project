#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAXLEN 1024

typedef struct LineReferenceList {

    int line;
    REFLIST next;
    int type;

} ref_list;

typedef struct NodeItem
{
    char name[MAXLEN];
    int size;
    int scope;
} node_item;

typedef ref_list* REFLIST;

node_item createNewItem();

#endif
