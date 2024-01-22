#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHTABLE_SIZE 5000

typedef struct h_item {
    long long int key;
    char value[30];
} h_item;

typedef struct hashtable {
    h_item **items;
    int size;
    int count;
} htable;

h_item *create_item(long long int key, char *value);

htable *create_table(int size);

void print_table(htable *table);

void ht_insert(htable *table, long long int key, char *value);

void free_item(h_item *item);

void free_table(htable *table);

int hashfunction(long long int key, int size);

#endif 