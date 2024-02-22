#include "test_hashtable.h"
#include "test_linked_list.h"
#include "test_parser_file.h"
#include "test_symbol_table_tree.h"
#include "test_trie.h"
#include <unity.h>

void setUp(void) {}

void tearDown(void) {}

int main(void) {

    char* filename = "Grammar.txt";
    
    UNITY_BEGIN();

    // test_linkedlist();
    // test_hash_table();
    test_trie();
    // test_symbol_table_tree();
    test_parser_file(filename);


    return UNITY_END();
}
