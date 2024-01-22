#include <unity.h>
#include <stdio.h>
#include "datastructures/hashtable.h"

void setUp(void)
{
    // set up test environment, if needed
}

void tearDown(void)
{
    // clean up test environment, if needed
}

void test_create_table(void)
{
    htable *table = create_table(10);

    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_EQUAL_INT(10, table->size);
    TEST_ASSERT_NOT_NULL(table->items);

    free_table(table);
}

void test_insert_and_retrieve(void)
{
    htable *table = create_table(10);

    ht_insert(table, 123, "value123");

    h_item *retrieved_item = table->items[hashfunction(123, table->size)];
    TEST_ASSERT_NOT_NULL(retrieved_item);
    TEST_ASSERT_EQUAL_INT(123, retrieved_item->key);
    TEST_ASSERT_EQUAL_STRING("value123", retrieved_item->value);

    free_table(table);
}

void test_insert_collision(void)
{
    htable *table = create_table(10);

    ht_insert(table, 123, "value123");
    ht_insert(table, 133, "value133");

    h_item *item1 = table->items[hashfunction(123, table->size)];
    h_item *item2 = table->items[hashfunction(133, table->size)];
    TEST_ASSERT_NOT_NULL(item1);
    TEST_ASSERT_NOT_NULL(item2);
    TEST_ASSERT_EQUAL_INT(123, item1->key);
    TEST_ASSERT_EQUAL_STRING("value123", item1->value);
    TEST_ASSERT_EQUAL_INT(133, item2->key);
    TEST_ASSERT_EQUAL_STRING("value133", item2->value);

    free_table(table);
}

int main(void)
{
    UNITY_BEGIN();

    // Run the test cases
    RUN_TEST(test_create_table);
    RUN_TEST(test_insert_and_retrieve);
    RUN_TEST(test_insert_collision);

    return UNITY_END();
}
