## Sorted Array to AVL

This project implements a function that builds an AVL tree from a sorted array.

### Prototype

```c
avl_t *sorted_array_to_avl(int *array, size_t size);
```

### Notes

- The input array is sorted and contains no duplicates.
- The tree is built directly as balanced by selecting the middle element as root recursively.
- No rotations are used.
- Returns `NULL` on failure.

