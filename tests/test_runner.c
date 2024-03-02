#include "test_hashtable.h"
#include "test_linked_list.h"
#include "test_symbol_table_tree.h"
#include "test_trie.h"
#include "test_first_and_follow.h"
#include "test_parse_tree.h"
#include "test_parser_file.h"
#include <unity.h>

void setUp(void) {}

void tearDown(void) {}

int main(void) {

    UNITY_BEGIN();

    test_linkedlist();
    test_hash_table();
    test_trie();
    test_symbol_table_tree();
    test_parser_file();
    test_first_and_follow();
    // test_parse_table_entry();
    test_create_parse_tree();

    return UNITY_END();
}
