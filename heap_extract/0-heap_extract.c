#include "binary_trees.h"

/**
 * tree_size - computes number of nodes in a binary tree
 * @root: root node
 *
 * Return: number of nodes
 */
static size_t tree_size(const heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + tree_size(root->left) + tree_size(root->right));
}

/**
 * node_at_index - gets node at 1-based level-order index
 * @root: tree root
 * @index: 1-based index in complete-tree array representation
 *
 * Return: pointer to node or NULL
 */
static heap_t *node_at_index(heap_t *root, size_t index)
{
	heap_t *parent;

	if (root == NULL)
		return (NULL);
	if (index == 1)
		return (root);

	parent = node_at_index(root, index / 2);
	if (parent == NULL)
		return (NULL);

	if (index % 2 == 0)
		return (parent->left);
	return (parent->right);
}

/**
 * sift_down - restores max-heap property from root downward
 * @root: heap root to sift
 */
static void sift_down(heap_t *root)
{
	heap_t *largest;
	int tmp;

	while (root != NULL)
	{
		largest = root;

		if (root->left != NULL && root->left->n > largest->n)
			largest = root->left;
		if (root->right != NULL && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;
		root = largest;
	}
}

/**
 * heap_extract - extracts the root value of a max binary heap
 * @root: address of root pointer
 *
 * Return: extracted root value, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	size_t size;
	int extracted;

	if (root == NULL || *root == NULL)
		return (0);

	extracted = (*root)->n;
	size = tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (extracted);
	}

	last = node_at_index(*root, size);
	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;
	free(last);

	sift_down(*root);

	return (extracted);
}

