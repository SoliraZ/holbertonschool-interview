#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @array: array containing elements
 * @i: index of first element
 * @j: index of second element
 * @size: total array size for printing
 */
static void swap_ints(int *array, size_t i, size_t j, size_t size)
{
	int tmp;

	if (i == j)
		return;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * sift_down - restores heap property from a root down
 * @array: array representing heap
 * @start: index of root to sift
 * @end: last valid index in current heap
 * @size: full array size for printing
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap_idx;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap_ints(array, root, swap_idx, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 *             using Heap sort algorithm (sift-down)
 * @array: array to sort
 * @size: number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	size_t start;
	size_t end;

	if (array == NULL || size < 2)
		return;

	start = size / 2;
	while (start > 0)
	{
		start--;
		sift_down(array, start, size - 1, size);
	}

	for (end = size - 1; end > 0; end--)
	{
		swap_ints(array, 0, end, size);
		sift_down(array, 0, end - 1, size);
	}
}

