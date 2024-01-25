#include "datastructures/hashtable.h"
#include "datastructures/linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

