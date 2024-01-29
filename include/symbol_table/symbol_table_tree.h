#ifndef SYMBOL_TABLE_TREE_H
#define SYMBOL_TABLE_TREE_H

#include "datastructures/hashtable.h"
#include "symbol_table.h"
#include <stdio.h>

typedef struct SymbolTree {
    struct SymbolTreeNode* root;
    struct SymbolTreeNode* curr_tree_node;
} SymbolTree;

typedef struct SymbolTreeNode {
    struct SymbolTreeNode* par;
    HTABLE curr_table;
} SymbolTreeNode;

typedef SymbolTreeNode* NODETREESYM;
typedef SymbolTree* TREESYM;

void insert_node_tree(TREESYM tree, NODETREESYM node);

void remove_node_tree(TREESYM tree);

TREESYM create_tree();

NODETREESYM create_tree_node();

node_item * lookup_id(char* attr,TREESYM tree);



#endif 