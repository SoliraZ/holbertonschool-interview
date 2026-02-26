 # Heap Insert
 
 Create a binary tree node for use in a binary heap or generic binary tree structure.
 
 ## Description
 
 This directory contains code that implements a function to create a new binary tree node.  
 The node stores an integer value, a pointer to its parent, and pointers to its left and right children.
 
 ## Prototype
 
 ```c
 binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
 ```
 
 - **parent**: pointer to the parent node of the node to create (can be `NULL` for the root)
 - **value**: value to put in the new node
 - **Return**: pointer to the new node, or `NULL` on failure
 
 When created, a node does not have any children (`left` and `right` are set to `NULL`).
 
 ## Files
 
 - `0-binary_tree_node.c`: implementation of `binary_tree_node`
 
 ## Notes
 
 This function is typically used together with a shared `binary_trees.h` header and helper functions
 like `binary_tree_print` in higher-level binary tree / heap projects.
 
