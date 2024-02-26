#include "test_first_and_follow.h"
#include <unity.h>

void test_first_and_follow_func(void) {
    char filename[] = "/Users/adityadandwate/Desktop/acads/codes/coco/Compiler-Construction-Project/src/parser/ModifiedGrammar.txt";

    GRAMMAR G = parseFile(filename);
    TEST_ASSERT_NOT_NULL(G);
    FIRSTANDFOLLOW fnf = ComputeFirstAndFollowSets(G);
    TEST_ASSERT_NOT_NULL(fnf);

    NODE_ELE cdtype = fnf->firstSet[constructedDatatype]->head;
    TEST_ASSERT_EQUAL(T_RECORD, cdtype->item);
    cdtype = cdtype->next;
    TEST_ASSERT_EQUAL(T_UNION, cdtype->item);
    cdtype = cdtype->next;
    TEST_ASSERT_EQUAL(T_RUID, cdtype->item);
    cdtype = cdtype->next;
    TEST_ASSERT_NULL(cdtype);

}

void test_first_and_follow(void) { 
    RUN_TEST(test_first_and_follow_func); 
    }
