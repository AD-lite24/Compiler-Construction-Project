#ifndef SYMBOL_TABLE_TREE_H
#define SYMBOL_TABLE_TREE_H

#include "datastructures/hashtable.h"
#include "tokens/tokens.h"

typedef struct SymbolTreeNode {
    struct SymbolTreeNode* par;
    HTABLE curr_table;
} SymbolTreeNode;

typedef SymbolTreeNode* NODETREEESYM;

typedef struct SymbolTree {
    NODETREEESYM root;
    NODETREEESYM curr_tree_node;
} SymbolTree;

typedef SymbolTree* TREESYM;

void insert_node_tree(TREESYM tree, NODETREEESYM node);

void remove_node_tree(TREESYM tree, NODETREEESYM node);

TREESYM create_tree();

NODETREEESYM create_tree_node();

NODETREEESYM lookup_id(char* attr);



#endif 