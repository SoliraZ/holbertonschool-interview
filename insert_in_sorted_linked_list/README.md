# Insert in Sorted Linked List

Insert a number into a sorted singly linked list in C.

## Description

This project implements a function that inserts an integer into a **sorted** singly linked list while keeping the list sorted in ascending order.

## Prototype

```c
listint_t *insert_node(listint_t **head, int number);
```

- **head**: Double pointer to the head of the list
- **number**: The integer to insert
- **Return**: The address of the new node, or `NULL` if it failed (e.g. `malloc` fails or `head` is `NULL`)

## Files

| File                | Description                                        |
|---------------------|----------------------------------------------------|
| `lists.h`           | Header with `listint_t` and function declarations  |
| `0-insert_number.c` | Implementation of `insert_node`                    |

## Example

List before: `0 → 1 → 2 → 3 → 4 → 98 → 402 → 1024`  
After `insert_node(&head, 27)`:

```
0
1
2
3
4
27
98
402
1024
```

The new node is placed so that the list remains sorted.
