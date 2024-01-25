#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linked_list.h"

#define HASHTABLE_SIZE 5000

typedef struct hashtable {
    LL* items;
    int count;
} htable;

typedef htable* HTABLE;

HTABLE createTable();

void htInsert(HTABLE table,char *value);

void freeTable(HTABLE table);

void freeList(LL list);

int hashfunction(char* name);

#endif

