# Advanced Binary Search

This project implements a binary search that returns the **first occurrence** of a value in a sorted array of integers.

## Files

- `0-advanced_binary.c`
- `search_algos.h`

## Prototype

```c
int advanced_binary(int *array, size_t size, int value);
```

## Requirements

- `array` is sorted in ascending order.
- Returns the index of the **first** matching value.
- Returns `-1` if `array` is `NULL`, empty, or value is not found.
- Prints the current search range on every split.
- Uses recursion (only one loop allowed, used for printing).

## Example

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary
./0-advanced_binary
```
