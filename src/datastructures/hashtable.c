#include "datastructures/hashtable.h"
#include "datastructures/linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

LL createNewList(){
    LL list = malloc(sizeof(ll));
    list->head = NULL;
    list->count = 0;
    return list;
}

NODE createNewNode(char* data) {
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
    free(rem);
    list->count--;
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

//Using polynomial rolling hashing function
//Change to long long later if required.
int hashfunction(char* name) {
    int hashval=0;
    int pow=1;
    int ln=strlen(name);
    for(int i=0;i<ln;i++){
        hashval=(hashval+((*(name+i)-'0'+1)%HASHTABLE_SIZE)*pow)%HASHTABLE_SIZE;
        pow=(pow*31)%HASHTABLE_SIZE;
    }
    return hashval;
}

HTABLE createTable(){
    HTABLE table=malloc(sizeof(htable));
    table->items = calloc(HASHTABLE_SIZE,sizeof(LL));
    for(int i=0;i < HASHTABLE_SIZE;i++)table->items[i]=NULL;
    return table;
}

void freeItem(H_ITEM item) {
    // free(item->value);
    free(item);
}

void htInsert(HTABLE table,char* value){
    int key=hashfunction(value);
    NODE newNode=createNewNode(value);
    if(!table->items[key])table->items[key]=createNewList();
    insertNodeFirst(newNode,table->items[key]);
}

void freeList(LL list){
    free(list);
}

void freeTable(HTABLE table) {
    for(int i=0;i< HASHTABLE_SIZE ;i++)freeList(table->items[i]);
    free(table->items);
    free(table);
}

