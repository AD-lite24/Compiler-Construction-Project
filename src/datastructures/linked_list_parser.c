#include "datastructures/linked_list_parser.h"
// #include "symbol_table/symbol_table.h"
#include <stdlib.h>

LL_LL createNewList_LL(){
    LL_LL list = malloc(sizeof(ll_ll));
    list->head = NULL;
    list->count = 0;
    return list;
}
NODE_LL createNewNode_LL(LL_ELE data){
    NODE_LL new_node = malloc(sizeof(node_LL));
    new_node->next = NULL;
    new_node->item = data;
    return new_node;
}
void insertNode_LLFirst(NODE_LL node, LL_LL list){
    node->next = list->head;
    list->head = node;
    list->count++;
}
void insertNode_LLLast(NODE_LL node, LL_LL list){
    if (!node || !list) return;

    if (list->head == NULL) list->head = node;
    else {
        NODE_LL temp = list->head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
    node->next = NULL;
    list->count++;
}
void freeNode_LL(NODE_LL node){
    free(node);
}
void removeNode_LLFirst(LL_LL list){
    if (!list->head) 
        return;

    NODE_LL temp = list->head->next;
    NODE_LL rem = list->head;
    list->head = temp;
    rem->next = NULL;
    list->count--;
    freeNode_LL(rem);
}
void removeNode_LLLast(LL_LL list){
    if (!list->head) 
        return;

    NODE_LL temp = list->head;
    NODE_LL prev;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    freeNode_LL(temp);
    list->count--;
}
void freeLL_LL(LL_LL list){
    NODE_LL current = list->head;
    NODE_LL next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}




LL_ELE createNewList_Ele(){
    LL_ELE list = malloc(sizeof(ll_ele));
    list->head = NULL;
    list->count = 0;
    return list;
}
NODE_ELE createNewNode_Ele(Elements data){
    NODE_ELE new_node = malloc(sizeof(node_Ele));
    new_node->next = NULL;
    new_node->item = data;
    return new_node;
}
void insertNode_EleFirst(NODE_ELE node, LL_ELE list){
    node->next = list->head;
    list->head = node;
    list->count++;
}
void insertNode_EleLast(NODE_ELE node, LL_ELE list){
    if (!node || !list) return;

    if (list->head == NULL) list->head = node;
    else {
        NODE_ELE temp = list->head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
    node->next = NULL;
    list->count++;
}
void freeNode_Ele(NODE_ELE node){
    free(node);
}
void removeNode_EleFirst(LL_ELE list){
    if (!list->head) 
        return;

    NODE_ELE temp = list->head->next;
    NODE_ELE rem = list->head;
    list->head = temp;
    rem->next = NULL;
    list->count--;
    freeNode_Ele(rem);
}
void removeNode_EleLast(LL_ELE list){
    if (!list->head) 
        return;

    NODE_ELE temp = list->head;
    NODE_ELE prev;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    freeNode_Ele(temp);
    list->count--;
}
void freeLL_ELE(LL_ELE list){
    NODE_ELE current = list->head;
    NODE_ELE next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
