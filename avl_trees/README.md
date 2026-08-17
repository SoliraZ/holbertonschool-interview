# AVL Trees

This project implements a function that checks whether a binary tree is a valid AVL Tree.

## Files

- `0-binary_tree_is_avl.c`
- `binary_trees.h`

## Prototype

```c
int binary_tree_is_avl(const binary_tree_t *tree);
```

## Description

- `tree` is a pointer to the root node of the tree to check.
- Returns `1` if `tree` is a valid AVL Tree.
- Returns `0` otherwise.
- Returns `0` if `tree` is `NULL`.

## AVL Tree Properties

An AVL Tree must satisfy:

1. It is a Binary Search Tree (BST).
2. The height difference between left and right subtrees is at most 1.
3. Both left and right subtrees are also valid BSTs and AVL Trees.

## Approach

The solution uses a recursive helper that validates BST bounds while computing subtree heights:

- For each node, verify that its value lies within the allowed `[min, max]` range.
- Recursively validate the left subtree with `max = node->n - 1`.
- Recursively validate the right subtree with `min = node->n + 1`.
- Reject the tree if the absolute height difference between subtrees exceeds 1.
- Return the subtree height when valid, or `-1` when invalid.

Time complexity: `O(n)`  
Space complexity: `O(h)` (recursion depth, where `h` is tree height)

## Data Structures

```c
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
```

## Testing

A static library (`libavl.a`) is provided for local testing. It contains helper functions such as `binary_tree_node` used by the main test file.
