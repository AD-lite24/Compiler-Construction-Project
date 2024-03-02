#include "test_parse_tree.h"
#include "datastructures/stack_parser.h"
#include <unity.h>
#include <stdlib.h>
#include <stdio.h>

void test_create_parse_tree() {
    char * file = "t2.txt";
    parseFile(file);
    FIRSTANDFOLLOW ff = ComputeFirstAndFollowSets();
    createParseTable(ff);
    TREE_NODE root = parseInputSourceCode();

    TEST_ASSERT_NOT_NULL(root);
    TEST_ASSERT_NULL(root->parent);
    TEST_ASSERT_NOT_NULL(root->children[0]);
    TEST_ASSERT_NOT_NULL(root->children[1]);
    TEST_ASSERT_EQUAL(root->count_children,2);

}

void test_insert() {
    RUN_TEST(test_create_parse_tree);
}