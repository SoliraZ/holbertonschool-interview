# Heap Extract

This project implements extraction of the root value from a Max Binary Heap.

## Files

- `0-heap_extract.c`
- `binary_trees.h`

## Prototype

```c
int heap_extract(heap_t **root);
```

## Behavior

- Returns the root value of the heap.
- Replaces the root with the last node in level-order.
- Frees the old last node.
- Restores max-heap property with sift-down.
- Returns `0` if extraction fails (`root == NULL` or `*root == NULL`).

