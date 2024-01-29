#include <unity.h>
#include "test_linked_list.h"
#include "test_hashtable.h"
#include "test_trie.h"
#include "test_symbol_table_tree.h"

void setUp(void) {

}

void tearDown(void) {

}

int main(void) {
    UNITY_BEGIN();

    test_linkedlist();
    test_hash_table();
    test_trie();
    test_symbol_table_tree();
    
    return UNITY_END();
}
