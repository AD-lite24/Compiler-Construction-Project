#include "test_parser_file.h"
#include <unity.h>

void test_parser_file_func(void) {

    char *filename = "/Users/adityadandwate/Desktop/acads/codes/coco/Compiler-Construction-Project/tests/Grammar.txt";

    parseFile(filename);
    TEST_ASSERT_NOT_NULL(grammar_glob);

    // otherFunctions - input_par function ; dataType
    NODE_LL var1 = grammar_glob->rules[otherFunctions]->head;
    NODE_ELE ele = var1->item->head;

    TEST_ASSERT_EQUAL(ele->item, input_par);
    ele = ele->next;
    TEST_ASSERT_EQUAL(ele->item, function);

    var1 = var1->next;
    ele = var1->item->head;

    TEST_ASSERT_EQUAL(ele->item, dataType);


    // moreFields - T_EPSILON ; T_DOT declaration T_WRITE T_EQ

    var1 = grammar_glob->rules[moreFields]->head;
    ele = var1->item->head;
    TEST_ASSERT_EQUAL(ele->item, T_EPSILON);

    var1 = var1->next;
    ele = var1->item->head;

    TEST_ASSERT_EQUAL(ele->item, T_DOT);
    ele = ele->next;
    TEST_ASSERT_EQUAL(ele->item, declaration);
    ele = ele->next;
    TEST_ASSERT_EQUAL(ele->item, T_WRITE);
    ele = ele->next;
    TEST_ASSERT_EQUAL(ele->item, T_EQ);
    
}

void test_parser_file() {
    RUN_TEST(test_parser_file_func);
}
