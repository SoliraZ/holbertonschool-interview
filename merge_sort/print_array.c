#include <stdio.h>
#include "sort.h"

/**
 * print_array - prints an array of integers
 * @array: array of integers
 * @size: number of elements
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
}
