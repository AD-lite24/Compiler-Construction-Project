#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAXLEN 1024

// token types
#define NUM_TK 0
#define R_NUM_TK 1
#define RUID 2
#define FUNID_TK 3
#define FIELDID_TK 4
#define ID_TK 5

typedef struct LineReferenceList {
    int line;
    struct LineReferenceList* next;
    int type;
} ref_list;

typedef ref_list* REFLIST;

typedef struct NodeItem {
    char* name;
    int size;
    int scope;
} node_item;

node_item createNewItem(char* name);

#endif
