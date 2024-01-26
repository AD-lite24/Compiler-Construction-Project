#include <unity.h>
#include <stdio.h>
#include "datastructures/hashtable.h"

void test_create_table(void) {
    HTABLE table = createTable();

    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_NOT_NULL(table->items);

    freeTable(table);
}

void test_insert_and_retrieve(void) {
    HTABLE table = createTable();

    char* values[] = {"value1", "value2", "value3", "value4", "value5", "value6", "value7", "value8", "value9", "value10",
                      "value11", "value12", "value13", "value14", "value15", "value16", "value17", "value18", "value19", "value20"};

    for (int i = 0; i < 20; i++) {
        htInsert(table, values[i]);
    }

    for (int i = 0; i < 20; i++) {
        int key = hashfunction(values[i]);
        LL list = table->items[key];
        NODE retrievedNode = list->head;
        TEST_ASSERT_NOT_NULL(retrievedNode);
        TEST_ASSERT_EQUAL_STRING(values[i], retrievedNode->item.val);
    }

    freeTable(table);
}

void test_insert_collision(void) {
    HTABLE table = createTable();

    char* values1[] = {"value1", "value2", "value3", "value4", "value5"};
    char* values2[] = {"value6", "value7", "value8", "value9", "value10"};

    for (int i = 0; i < 5; i++) {
        htInsert(table, values1[i]);
        htInsert(table, values2[i]);
    }

    for (int i = 0; i < 5; i++) {
        int key1 = hashfunction(values1[i]);
        int key2 = hashfunction(values2[i]);

        LL list1 = table->items[key1];
        LL list2 = table->items[key2];

        NODE retrievedNode1 = list1->head;
        NODE retrievedNode2 = list2->head;

        TEST_ASSERT_NOT_NULL(retrievedNode1);
        TEST_ASSERT_NOT_NULL(retrievedNode2);

        TEST_ASSERT_EQUAL_STRING(values1[i], retrievedNode1->item.val);
        TEST_ASSERT_EQUAL_STRING(values2[i], retrievedNode2->item.val);
    }

    freeTable(table);
}
void test_hash_table() {
    RUN_TEST(test_create_table);
    RUN_TEST(test_insert_and_retrieve);
    RUN_TEST(test_insert_collision);
}
