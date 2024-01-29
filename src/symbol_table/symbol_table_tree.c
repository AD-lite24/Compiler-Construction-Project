#include "symbol_table/symbol_table_tree.h"
#include <stdlib.h>

void insert_node_tree(TREESYM tree, NODETREESYM node) {
    node->par = tree->curr_tree_node;
    tree->curr_tree_node = node;
    return;
}

void remove_node_tree(TREESYM tree) {
    NODETREESYM ptr = tree->curr_tree_node;
    tree->curr_tree_node = tree->curr_tree_node->par;
    free(ptr);
    return;
}

TREESYM create_tree() {
    TREESYM tree = (TREESYM) malloc(sizeof(SymbolTree));
    NODETREESYM root = create_tree_node();
    tree->root = root;
    tree->curr_tree_node = root;
    return tree;
}

NODETREESYM create_tree_node() {
    NODETREESYM node = (NODETREESYM) malloc(sizeof(SymbolTreeNode));
    node->curr_table = createTable();
    node->par = NULL;
    return node;
}

node_item * lookup_id(char* attr,TREESYM tree) {
    NODETREESYM node = tree->curr_tree_node;
    while (1) {
        HTABLE tab = node->curr_table;
        int key = hashfunction(attr);
        LL list = tab->items[key];

        if (list) {
            NODE x = list->head;
            while (x != NULL) {
                if (x->item.name == attr) return &(x->item);
                x = x->next;
            }
        }

        if (!node->par) break;
        node = node->par;
    }
    return NULL;
}
