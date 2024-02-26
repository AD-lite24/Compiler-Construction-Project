// #include "test_symbol_table_tree.h"
// #include "symbol_table/symbol_table_tree.h"
// #include "datastructures/hashtable.h"
// #include "unity.h"

// // Test case for create_tree_node function
// void test_create_tree_node(void) {
//     NODETREESYM node = create_tree_node();

//     // Use Unity assertion macros to check if the node and its components are
//     // correctly initialized
//     TEST_ASSERT_NOT_NULL(node);
//     TEST_ASSERT_NULL(node->par);
//     TEST_ASSERT_NOT_NULL(node->curr_table);
//     // Add more assertions if needed
// }

// // Test case for insert_node_tree function
// void test_insert_node_tree(void) {
//     TREESYM tree = create_tree();
//     NODETREESYM node1 = create_tree_node();
//     NODETREESYM node2 = create_tree_node();

//     insert_node_tree(tree, node1);

//     TEST_ASSERT_EQUAL_PTR(node1, tree->curr_tree_node);
//     TEST_ASSERT_EQUAL_PTR(tree->root, tree->curr_tree_node->par);

//     insert_node_tree(tree, node2);

//     TEST_ASSERT_EQUAL_PTR(node2, tree->curr_tree_node);
// }

// // Test case for remove_node_tree function
// void test_remove_node_tree(void) {
//     TREESYM tree = create_tree();
//     NODETREESYM node1 = create_tree_node();
//     NODETREESYM node2 = create_tree_node();

//     insert_node_tree(tree, node1);
//     insert_node_tree(tree, node2);

//     remove_node_tree(tree);

//     TEST_ASSERT_EQUAL_PTR(node1, tree->curr_tree_node);
// }

// void test_lookup_id(void) {
//     TREESYM tree = create_tree();
//     NODETREESYM node = create_tree_node();
//     node_item item = createNewItem("val1");
//     insert_node_tree(tree, node);
//     htInsert(tree->curr_tree_node->curr_table, item);

//     node_item *result = lookup_id("val1", tree);
//     TEST_ASSERT_NOT_NULL(result); // Modify this based on the expected behavior

//     node_item *result1 = lookup_id("val2", tree);
//     TEST_ASSERT_NULL(result1);

// }

// void test_symbol_table_tree() {

//     RUN_TEST(test_create_tree_node);
//     RUN_TEST(test_insert_node_tree);
//     RUN_TEST(test_remove_node_tree);
//     RUN_TEST(test_lookup_id);

// }