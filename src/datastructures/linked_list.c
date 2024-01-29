#include "datastructures/linked_list.h"
#include "symbol_table/symbol_table.h"
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
    list->count++;
}

void insertNodeLast(NODE node, LL list) {

    if (!node || !list) return;

    if (list->head == NULL) list->head = node;

    else {
        NODE temp = list->head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
    node->next = NULL;
    list->count++;
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
    list->count--;
    freeNode(rem);
}

void removeNodeLast(LL list) {
    if (!list->head) 
        return;

    NODE temp = list->head;
    NODE prev;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    freeNode(temp);
    list->count--;
}

void freeLL(LL list) {
    NODE current = list->head;
    NODE next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}
