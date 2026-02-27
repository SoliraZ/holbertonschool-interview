## Linked List Palindrome

This project implements a function that checks whether a singly linked list of integers is a palindrome.

### Data Structure

The list nodes are defined as:

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

### Function

- **Prototype**: `int is_palindrome(listint_t **head);`
- **Return**:
  - `1` if the list is a palindrome.
  - `0` otherwise.
  - An empty list is considered a palindrome.

The implementation runs in linear time and uses O(1) extra space by:

- Using a slow/fast pointer technique to find the middle.
- Reversing the second half of the list in place.
- Comparing the first half with the reversed second half node by node.

