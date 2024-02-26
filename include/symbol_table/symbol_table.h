#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "tokens/tokens.h"

#define MAXLEN 1024

typedef struct LineReferenceList {
    int line;
    struct LineReferenceList *next;
    int type;
} ref_list;

typedef ref_list *REFLIST;

typedef struct ParamItem {

} ParamItem;

typedef ParamItem *PARAM;

typedef struct NodeItem {

    char *name;
    int size;
    REFLIST ref_head;
    Token token;

    // values
    int int_val;
    double real_val;

    // Record and union type here

    // function params
    PARAM *input_params;
    PARAM *output_params;
    int num_of_inp_params;
    int num_of_out_params;

} node_item;

node_item createNewItem(char *name);

#endif