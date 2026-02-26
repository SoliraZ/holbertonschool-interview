# Heap Insert

Binary tree node creation and insertion into a Max Binary Heap.

## Description

This directory implements:

1. **binary_tree_node** – create a new binary tree node (used by the heap).
2. **heap_insert** – insert a value into a Max Binary Heap while keeping the complete-tree shape and max-heap property (parent ≥ children). New nodes are added in level order; the inserted node is then sifted up until the heap property is restored.

## Prototypes

### binary_tree_node

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

- **parent**: pointer to the parent node (can be `NULL` for the root)
- **value**: value to put in the new node
- **Return**: pointer to the new node, or `NULL` on failure

### heap_insert

```c
heap_t *heap_insert(heap_t **root, int value);
```

- **root**: double pointer to the root of the heap (if `*root` is `NULL`, the new node becomes the root)
- **value**: value to store in the new node
- **Return**: pointer to the inserted node, or `NULL` on failure

## Files

- `binary_trees.h`: `binary_tree_t` / `heap_t` and declarations
- `0-binary_tree_node.c`: implementation of `binary_tree_node`
- `1-heap_insert.c`: implementation of `heap_insert` (and helpers, up to 6 functions)
 
