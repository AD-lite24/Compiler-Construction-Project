#include "datastructures/hashtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

h_item *create_item(long long int key, char *value) {
    h_item* item = malloc(sizeof(h_item));
    item->key = key;
    strcpy(item->value, value);
    return item;
}

int hashfunction(long long int key, int size) {
    return key%size;
}

htable *create_table(int size) {
    if (size == -1) 
        size = HASHTABLE_SIZE;

    htable* table = malloc(sizeof(htable));
    table->size = size;
    table->items = calloc(table->size, sizeof(h_item*));

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;
}

void free_item(h_item *item) {
    // free(item->value);
    free(item);
}

void free_table(htable *table) {
    for (int i = 0; i < table->size; i++)
    {
        // if (table == NULL) {
        //     int b = 0;
        // }
        // h_item** test = table->items;
        h_item* item = table->items[i];

        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

void print_table(htable *table) {
    for (int i = 0; i < table->size; i++)
        if (table->items[i])
            printf("Index:%d, Key:%lld, Value:%s\n", i, table->items[i]->key, table->items[i]->value);   
}

void ht_insert(htable *table, long long int key, char *value)
{

    h_item *item = create_item(key, value);

    int index = hashfunction(key, table->size);

    h_item* curr_item = table->items[index];

    // No collision resolution applied here

    if (curr_item == NULL)
    {
        // Key does not exist.
        if (table->count == table->size)
        {
            // HashTable is full.
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }
        // Insert directly.
        table->items[index] = item;
        table->count++;
    }

    else
    {
        if (curr_item->key == key)
        {
            strcpy(table->items[index]->value, value);
            return;
        }
    }
}
