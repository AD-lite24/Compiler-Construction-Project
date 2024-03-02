#include "test_parse_tree.h"
#include "parser/parser.h"
#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

void test_create_parse_tree() {
    char *file = "/Users/adityadandwate/Desktop/acads/codes/coco/"
                 "Compiler-Construction-Project/tests/t2.txt";

    char *grammar_file = "/Users/adityadandwate/Desktop/acads/codes/coco/"
                  "Compiler-Construction-Project/src/parser/"
                  "ModifiedGrammar.txt";

    initLexer();
    parseFile(grammar_file);
    FIRSTANDFOLLOW ff = ComputeFirstAndFollowSets();
    createParseTable(ff);
    TREE_NODE root = parseInputSourceCode();

    TEST_ASSERT_NOT_NULL(root);
    TEST_ASSERT_NULL(root->parent);
    TEST_ASSERT_NOT_NULL(root->children[0]);
    TEST_ASSERT_NOT_NULL(root->children[1]);
    TEST_ASSERT_EQUAL(root->count_children, 2);
}

void test_insert() { RUN_TEST(test_create_parse_tree); }