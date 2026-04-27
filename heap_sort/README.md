# Heap Sort

This project implements Heap Sort in C using the **sift-down** method to sort an array of integers in ascending order.

## Project Info

- **Repository:** `holbertonschool-interview`
- **Directory:** `heap_sort`
- **Files:** `0-heap_sort.c`, `0-O`

## Function Prototype

```c
void heap_sort(int *array, size_t size);
```

## Requirements Covered

- Sort an array in ascending order using **Heap Sort**.
- Use the **sift-down** heap construction/maintenance strategy.
- Print the array after each swap of two elements.

## How It Works

1. Build a **max heap** from the input array.
2. Repeatedly swap the root (largest element) with the last element in the heap.
3. Shrink the heap boundary.
4. Sift down the new root to restore max-heap property.
5. Continue until the heap has one element left.

## Complexity

The file `0-O` contains:

- Best case: `O(n log n)`
- Average case: `O(n log n)`
- Worst case: `O(n log n)`

## Build Example

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
./0-heap
```

