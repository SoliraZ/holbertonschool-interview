#include "binary_trees.h"
#include <limits.h>

/**
 * check_height_avl - Validate BST/AVL properties and return subtree height
 * @tree: pointer to the root node of the tree to check
 * @min: minimum allowed value in this subtree
 * @max: maximum allowed value in this subtree
 *
 * Return: height of the subtree, or -1 if the subtree is invalid
 */
static int check_height_avl(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, balance;

	if (!tree)
		return (0);

	if (tree->n < min || tree->n > max)
		return (-1);

	left_height = check_height_avl(tree->left, min, tree->n - 1);
	if (left_height == -1)
		return (-1);

	right_height = check_height_avl(tree->right, tree->n + 1, max);
	if (right_height == -1)
		return (-1);

	balance = left_height - right_height;
	if (balance < -1 || balance > 1)
		return (-1);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_height_avl(tree, INT_MIN, INT_MAX) != -1);
}
