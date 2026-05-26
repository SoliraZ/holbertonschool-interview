#include <stdio.h>
#include "search_algos.h"

/**
 * print_subarray - prints the current search range
 * @array: pointer to array
 * @low: start index
 * @high: end index
 */
static void print_subarray(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	i = low;
	while (array && i <= high)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * _advanced_binary - recursive advanced binary search
 * @array: pointer to array
 * @low: lower bound index
 * @high: upper bound index
 * @value: value to search for
 *
 * Return: index of first occurrence, or -1
 */
static int _advanced_binary(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_subarray(array, low, high);

	mid = low + (high - low) / 2;

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] < value)
			return ((int)mid);
		return (_advanced_binary(array, low, mid, value));
	}
	if (array[mid] < value)
		return (_advanced_binary(array, mid + 1, high, value));
	return (_advanced_binary(array, low, mid - 1, value));
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

	return (_advanced_binary(array, 0, size - 1, value));
}
