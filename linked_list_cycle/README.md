## Linked List Cycle

This project implements a function that checks whether a singly linked list has a cycle.

### Data Structure

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

### Function

- **Prototype**: `int check_cycle(listint_t *list);`
- **Return**:
  - `1` if the list contains a cycle.
  - `0` otherwise.

The implementation uses a two-pointer technique (slow and fast pointers) to detect cycles in linear time and constant extra space, adhering to the allowed C library functions.
