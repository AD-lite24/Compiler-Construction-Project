#include "test_parser_file.h"
#include <unity.h>

void test_parser_file(char *filename) {

    GRAMMAR G = parseFile(filename);
    TEST_ASSERT_NOT_NULL(G);

    // otherFunctions - input_par function ; dataType
    NODE_LL var1 = G->rules[otherFunctions]->head;
    NODE_ELE ele = var1->item->head;

    TEST_ASSERT_EQUAL(ele->item, input_par);
    ele = ele->next;
    TEST_ASSERT_EQUAL(ele->item, function);

    var1 = var1->next;
    ele = var1->item->head;

    TEST_ASSERT_EQUAL(ele->item, dataType);


    // moreFields - TK_EPSILON ; TK_DOT declaration TK_WRITE TK_EQ

    var1 = G->rules[moreFields]->head;
    ele = var1->item->head;
    TEST_ASSERT_EQUAL(ele->item, TK_EPSILON);

    var1 = var1->next;
    ele = var1->item->head;

    TEST_ASSERT_EQUAL(ele->item, TK_DOT);
    ele = ele->next;
    TEST_ASSERT_EQUAL(ele->item, declaration);
    ele = ele->next;
    TEST_ASSERT_EQUAL(ele->item, TK_WRITE);
    ele = ele->next;
    TEST_ASSERT_EQUAL(ele->item, TK_EQ);
    
        

}
