#include<stdlib.h>
#include<stdio.h>
#include <unity.h>
#include "datastructures/trie.h"  // Include the header file for your Trie implementation

void setUp(void) {
    // This function will be called before each test case
}

void tearDown(void) {
    // This function will be called after each test case
}

void test_insert_and_search(void) {
    TrieNode* root = createTrieNode();

    TEST_ASSERT_EQUAL_INT(0, searchTrie(root, "apple"));

    insertTrie(root, "apple");
    TEST_ASSERT_EQUAL_INT(1, searchTrie(root, "apple"));

    insertTrie(root, "app");
    TEST_ASSERT_EQUAL_INT(1, searchTrie(root, "app"));
    TEST_ASSERT_EQUAL_INT(0, searchTrie(root, "ap"));
    TEST_ASSERT_EQUAL_INT(0, searchTrie(root, "orange"));

    // Clean up
    freeTrie(root);
}

void test_delete(void) {
    TrieNode* root = createTrieNode();

    insertTrie(root, "apple");
    insertTrie(root, "app");
    insertTrie(root, "orange");

    TEST_ASSERT_EQUAL_INT(1, searchTrie(root, "apple"));
    TEST_ASSERT_EQUAL_INT(1, searchTrie(root, "app"));
    TEST_ASSERT_EQUAL_INT(1, searchTrie(root, "orange"));

    deleteTrie(root, "apple");
    TEST_ASSERT_EQUAL_INT(0, searchTrie(root, "apple"));
    TEST_ASSERT_EQUAL_INT(1, searchTrie(root, "app"));
    TEST_ASSERT_EQUAL_INT(1, searchTrie(root, "orange"));

    // Clean up
    freeTrie(root);
}

int main(void) {
    UNITY_BEGIN();  // Start the Unity testing framework

    RUN_TEST(test_insert_and_search);
    RUN_TEST(test_delete);

    return UNITY_END();  // End the Unity testing framework
}
