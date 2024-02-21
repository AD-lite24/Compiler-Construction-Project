#include <unity.h>
#include <stdio.h>
#include "test_first_follow_set.h"

void test_first_retrieval(void) {

    TEST_ASSERT_EQUAL(firstSet[stringToEnumNonTerm(mainFunction)]);

}


// mainFunction={DOLLAR}
// function={TK_FUNID,TK_MAIN}
// input_par={TK_OUTPUT,TK_SEM}
// output_par={TK_SEM}
// parameter_list={TK_SQR}
// dataType={TK_ID,TK_COLON}
// primitiveDatatype={TK_ID,TK_COLON}
// constructedDatatype={TK_ID,TK_COLON}
// remaining_list={TK_SQR}

void test_follow_retrieval(void) {

    Terminals arr1[1] = {DOLLAR};
    Terminals arr1[2] = {DOLLAR};
    Terminals arr1[2] = {DOLLAR};
    Terminals arr1[1] = {DOLLAR};
    Terminals arr1[] = {DOLLAR};
    Terminals arr1[1] = {DOLLAR};
    Terminals arr1[1] = {DOLLAR};
    Terminals arr1[1] = {DOLLAR};

    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
    TEST_ASSERT_EQUAL();
}