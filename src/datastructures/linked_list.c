#include "datastructures/linked_list.h"
#include "datastructures/symbol_table_item.h"
#include <stdlib.h>

LL createNewList(){
    LL list = malloc(sizeof(ll));
    list->head = NULL;
    list->count = 0;
    return list;
}

NODE createNewNode(node_item data) {
    NODE new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->item = data;
    return new_node;
}

void insertNodeFirst(NODE node, LL list) {
    node->next = list->head;
    list->head = node;
}

void insertNodeLast(NODE node, LL list) {
    NODE temp = list->head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = node;
}

void freeNode(NODE node) {
    free(node);
}

void removeNodeFirst(LL list) {

    if (!list->head) 
        return;

    NODE temp = list->head->next;
    NODE rem = list->head;
    list->head = temp;
    rem->next = NULL;
    free(rem);
}

void removeNodeLast(LL list) {
    if (!list->head) 
        return NULL;

    NODE temp = list->head;
    NODE prev;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    freeNode(temp);
}

