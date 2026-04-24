#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *left, *right;

	if (list == NULL)
		return (NULL);

	left = list;
	right = list;

	while (right->express != NULL && right->n < value)
	{
		left = right;
		right = right->express;
		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
		if (right->n >= value)
			break;
	}

	if (right->express == NULL && right->n < value)
	{
		left = right;
		while (right->next != NULL)
			right = right->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       left->index, right->index);

	while (left != NULL && left->index <= right->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		if (left->n == value)
			return (left);
		if (left->n > value)
			return (NULL);
		left = left->next;
	}

	return (NULL);
}

