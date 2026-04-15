#include <sys/types.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * build_avl - builds a balanced AVL tree from a sorted subarray
 * @array: pointer to first element of the full sorted array
 * @left: left bound index (inclusive)
 * @right: right bound index (inclusive)
 * @parent: parent node for the subtree root
 *
 * Return: pointer to subtree root, or NULL on failure
 */
static avl_t *build_avl(int *array, ssize_t left, ssize_t right, avl_t *parent)
{
	ssize_t mid;
	avl_t *node;

	if (left > right)
		return (NULL);

	mid = left + (right - left) / 2;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;
	node->left = build_avl(array, left, mid - 1, node);
	node->right = build_avl(array, mid + 1, right, node);

	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to first element of the array
 * @size: number of elements in array
 *
 * Return: pointer to root node of created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, (ssize_t)size - 1, NULL));
}

