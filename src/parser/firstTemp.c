#include "grammar.h"
#include "parser.h"
#include "parser.c"
#include<stdlib.h>
#include<stdio.h>

void findFirst(Elements n1, LL rule, FIRSTANDFOLLOW FnF){
    NODE curNode = rule->head;
    Elements* ret = (Elements*)malloc(sizeof(Elements)*40);
    memset(ret, 200, 40*sizeof(Elements));
    int retIndex = 0;
    while(curNode!=NULL){
        Elements* curElem = curNode->item;
        int index = 0;
        while(curElem[index]!=200){
            int val = curElem[index++];
            if(val >= 52){
                ret[retIndex++] = val;
            }
            else{
                Elements* src = FnF->firstSet[val];
                retIndex = addElem(ret, src, retIndex);
                // fill all elements of that non terminal
            }
            // index++;
        }
        curNode = curNode->next;
    }
    FnF->firstSet[n1] = ret;
}


int addElem(Elements* dest, Elements* src, int destIndex){
    int srcIndex = 0;
    while(src[srcIndex] != 200){
        dest[destIndex++] = src[srcIndex];
        srcIndex++;
    }
    return destIndex;
}


int main () {
    GRAMMAR GG = malloc (sizeof(grammar));
    for (int i = 0 ; i < NUM_NONTERMS ; i++)
        GG->rules[i] = createNewList();
    Elements arr1[] = {TK_AND, TK_ASSIGNOP, TK_NULL, TK_LE};
    Elements arr2[] = {TK_CALL, TK_NULL, TK_LE};
    Elements arr3[] = {TK_DIV, TK_ASSIGNOP, TK_NULL, TK_LE};
    Elements arr4[] = {TK_MINUS, TK_ASSIGNOP, TK_NULL, TK_LE};
    Elements arr5[] = {TK_AND, TK_MUL, TK_NULL, TK_LE};
    insertNodeLast(createNewNode(arr1), GG->rules[0]);
    insertNodeLast(createNewNode(arr2), GG->rules[0]);
    insertNodeLast(createNewNode(arr3), GG->rules[3]);
    insertNodeLast(createNewNode(arr4), GG->rules[6]);
    insertNodeLast(createNewNode(arr5), GG->rules[7]);
    FIRSTANDFOLLOW* FnF = (FIRSTANDFOLLOW*)malloc(sizeof(struct FirstAndFollow));
    return 0;
}