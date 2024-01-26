#include<stdlib.h>
#include<stdio.h>
#include <unity.h>
#include "datastructures/trie.h"  // Include the header file for your Trie implementation
#include "tokens/tokens.h"  // Include the header file for your Trie implementation

void test_populateTrie(void){
    TRIE r;
    r = populateTrie();
    TEST_ASSERT_NOT_NULL(r);

    free(r);
}

void test_lookupTrie(void){
    TRIE r;
    r = populateTrie();
    TEST_ASSERT_NOT_NULL(r);
    enum Token tk1 = lookupTrie(r, "endwhile");
    enum Token tk2 = lookupTrie(r, "parameter");
    enum Token tk3 = lookupTrie(r, "definetype");
    enum Token tk4 = lookupTrie(r, "output");
    enum Token tk5 = lookupTrie(r, "else");
    TEST_ASSERT_EQUAL(TK_ENDWHILE, tk1);
    TEST_ASSERT_EQUAL(TK_PARAMETER, tk2);
    TEST_ASSERT_EQUAL(TK_DEFINETYPE, tk3);
    TEST_ASSERT_EQUAL(TK_OUTPUT, tk4);
    TEST_ASSERT_EQUAL(TK_ELSE, tk5);

    free(r);
}

void test_trie(){
    RUN_TEST(test_populateTrie);
    RUN_TEST(test_lookupTrie);
}
