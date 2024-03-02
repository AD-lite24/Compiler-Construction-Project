#include <stdio.h>
#include <stdlib.h>
#include <unity.h>
#include "test_parse_table.h"

void test_parse_table_entry_func(void) {
//     char filename[] = "/Users/adityadandwate/Desktop/acads/codes/coco/Compiler-Construction-Project/src/parser/ModifiedGrammar.txt";

//     GRAMMAR G = parseFile(filename);
//     TEST_ASSERT_NOT_NULL(G);
//     FIRSTANDFOLLOW fnf = ComputeFirstAndFollowSets(G);
//     TEST_ASSERT_NOT_NULL(fnf);

//     // ProdRule parseTable[NUM_NONTERMS][NUM_ELEMENTS - NUM_NONTERMS - 1];
//     // ProdRule*** parseTable =
     
//     createParseTable(fnf);

//     for (int i = 0; i < NUM_ELEMENTS - NUM_NONTERMS - 1; i++) {
//         if (i == T_FUNID - NUM_NONTERMS || i == T_MAIN - NUM_NONTERMS) {
//             TEST_ASSERT_EQUAL((*parseTable)[0][i].LHS, program);
//             TEST_ASSERT_EQUAL((*parseTable)[0][i].RHS[0],otherFunctions);
//             TEST_ASSERT_EQUAL((*parseTable)[0][i].RHS[1],mainFunction);
//                     } 
//         else {
//             TEST_ASSERT_EQUAL((*parseTable)[0][i].LHS, -1);
//         }
//     }
}

void test_parse_table_entry(void) { RUN_TEST(test_parse_table_entry_func); }