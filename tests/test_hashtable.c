#include <unity.h>
#include <stdio.h>
#include "datastructures/hashtable.h"
#include "test_hashtable.h"

void test_create_table(void)
{
    HTABLE table = createTable();

    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_NOT_NULL(table->items);

    freeTable(table);
}

void test_insert_and_retrieve(void)
{
    HTABLE table = createTable();

    htInsert(table, "value123");

    int key = hashfunction("value123");
    LL list = table->items[key];
    NODE retrievedNode = list->head;

    TEST_ASSERT_NOT_NULL(retrievedNode);
    TEST_ASSERT_EQUAL_STRING("value123", retrievedNode->item);

    freeTable(table);
}


void test_insert_collision(void) {
    htable *table = create_table(10);


    htInsert(table, "value123");
    htInsert(table, "value133");

    int key1 = hashfunction("value123");
    int key2 = hashfunction("value133");

    LL list1 = table->items[key1];
    LL list2 = table->items[key2];

    NODE retrievedNode1 = list1->head;
    NODE retrievedNode2 = list2->head;

    TEST_ASSERT_NOT_NULL(retrievedNode1);
    TEST_ASSERT_NOT_NULL(retrievedNode2);

    TEST_ASSERT_EQUAL_STRING("value123", retrievedNode1->item);
    TEST_ASSERT_EQUAL_STRING("value133", retrievedNode2->item);

    freeTable(table);
}

void test_hash_table() {
    RUN_TEST(test_create_table);
    RUN_TEST(test_insert_and_retrieve);
    RUN_TEST(test_insert_collision);
}