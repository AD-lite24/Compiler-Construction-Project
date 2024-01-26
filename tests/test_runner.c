#include <unity.h>
#include "test_linked_list.h"
#include "test_hashtable.h"

void setUp(void) {

}

void tearDown(void) {

}

int main(void) {
    UNITY_BEGIN();

    test_linkedlist();
    test_hash_table();

    return UNITY_END();
}
