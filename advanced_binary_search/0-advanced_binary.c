#include <stdio.h>
#include "search_algos.h"

/**
 * print_subarray - prints the current search range
 * @array: pointer to subarray
 * @size: number of elements in subarray
 */
static void print_subarray(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	i = 0;
	while (array && i < size)
	{
		if (i)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * _advanced_binary - recursive advanced binary search
 * @array: pointer to subarray
 * @size: size of subarray
 * @value: value to search for
 * @offset: offset from original array start
 *
 * Return: index of first occurrence, or -1
 */
static int _advanced_binary(int *array, size_t size, int value, size_t offset)
{
	size_t mid;

	if (size == 0)
		return (-1);

	print_subarray(array, size);

	mid = (size - 1) / 2;
	if (size == 1)
		return (array[0] == value ? (int)offset : -1);

	if (array[mid] < value)
		return (_advanced_binary(array + mid + 1, size - mid - 1, value,
				offset + mid + 1));
	if (array[mid] > value)
		return (_advanced_binary(array, mid + 1, value, offset));
	if (mid == 0 || array[mid - 1] < value)
		return ((int)(offset + mid));
	return (_advanced_binary(array, mid + 1, value, offset));
}

/**
 * advanced_binary - searches for first occurrence in sorted array
 * @array: pointer to first element
 * @size: number of elements
 * @value: value to search for
 *
 * Return: index of value, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (_advanced_binary(array, size, value, 0));
}
