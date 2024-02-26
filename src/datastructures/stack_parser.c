#include "../../include/datastructures/stack_parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Stack* createnewStack(){
    Stack* st=(Stack*)malloc(sizeof(Stack));
    st->list=createNewList_Ele();
    return st;
}

void push(Stack* st,Elements element){
    NODE_ELE node=createNewNode_Ele(element);
    insertNode_EleLast(node,st->list);
}

Elements top(Stack* st){
    return ((st->list)->head)->item;
}

void pop(Stack* st){
    if(!st || st->list->count==0 || !st->list){
        return;
    }else{
        removeNode_EleLast(st->list);
    }
}

bool isEmpty(Stack* st){
    if(st->list->count==0)return true;
    else return false;
}
