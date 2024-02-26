#include "datastructures/linked_list.h"
#include "test_linked_list.h"
#include "symbol_table/symbol_table.h"
#include <unity.h>
#include <stdlib.h>
#include <stdio.h>


void test_createNewList(void) {
    LL testList;
    testList = createNewList();

    TEST_ASSERT_NOT_NULL(testList);
    TEST_ASSERT_NULL(testList->head);
    TEST_ASSERT_EQUAL_INT(0, testList->count);

    freeLL(testList);
}

void test_insertNodeFirst(void) {
    LL testList;
    testList = createNewList();

    node_item data1 = {};
    node_item data2 = {};
    node_item data3 = {};
    node_item data4 = {};
    node_item data5 = {};

    NODE newNode1 = createNewNode(data1);
    insertNodeFirst(newNode1, testList);
    TEST_ASSERT_EQUAL_PTR(newNode1, testList->head);
    TEST_ASSERT_EQUAL_INT(1, testList->count);

    NODE newNode2 = createNewNode(data2);
    insertNodeFirst(newNode2, testList);
    TEST_ASSERT_EQUAL_PTR(newNode2, testList->head);
    TEST_ASSERT_EQUAL_INT(2, testList->count);

    NODE newNode3 = createNewNode(data3);
    insertNodeFirst(newNode3, testList);
    TEST_ASSERT_EQUAL_PTR(newNode3, testList->head);
    TEST_ASSERT_EQUAL_INT(3, testList->count);

    NODE newNode4 = createNewNode(data4);
    insertNodeFirst(newNode4, testList);
    TEST_ASSERT_EQUAL_PTR(newNode4, testList->head);
    TEST_ASSERT_EQUAL_INT(4, testList->count);

    NODE newNode5 = createNewNode(data5);
    insertNodeFirst(newNode5, testList);
    TEST_ASSERT_EQUAL_PTR(newNode5, testList->head);
    TEST_ASSERT_EQUAL_INT(5, testList->count);

    freeLL(testList);
}

void test_insertNodeLast(void) {

    LL testList = createNewList();
    node_item data1 = createNewItem("val1");
    node_item data2 = createNewItem("val2");

    NODE newNode1 = createNewNode(data1);
    NODE newNode2 = createNewNode(data2);

    insertNodeFirst(newNode1, testList);
    insertNodeLast(newNode2, testList);

    TEST_ASSERT_EQUAL_PTR(newNode1, testList->head);
    TEST_ASSERT_EQUAL_PTR(newNode2, testList->head->next);
    TEST_ASSERT_EQUAL_INT(2, testList->count);

    freeLL(testList);
}

void test_removeNodeFirst(void) {

    LL testList = createNewList();

    node_item data1 = createNewItem("val1");
    node_item data2 = createNewItem("val2");

    NODE newNode1 = createNewNode(data1);
    NODE newNode2 = createNewNode(data2);

    insertNodeFirst(newNode1, testList);
    insertNodeLast(newNode2, testList);

    // Ensure the nodes are correctly added
    TEST_ASSERT_EQUAL_PTR(newNode1, testList->head);
    TEST_ASSERT_EQUAL_PTR(newNode2, testList->head->next);
    TEST_ASSERT_EQUAL_INT(2, testList->count);

    // Test: Remove the first node
    removeNodeFirst(testList);

    // Ensure the first node is removed
    TEST_ASSERT_EQUAL_PTR(newNode2, testList->head);
    TEST_ASSERT_EQUAL_INT(1, testList->count);

    freeLL(testList);
}

void test_removeNodeLast(void) {
    // Similar to test_removeNodeFirst, but test removeNodeLast
}

void test_linkedlist() {
    RUN_TEST(test_createNewList);
    RUN_TEST(test_insertNodeFirst);
    RUN_TEST(test_insertNodeLast);
    RUN_TEST(test_removeNodeFirst);
    RUN_TEST(test_removeNodeLast);
}