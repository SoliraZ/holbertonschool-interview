#include <stdlib.h>
#include "binary_trees.h"

static size_t heap_size(heap_t *root);
static heap_t *node_at_position(heap_t *root, size_t pos);

/**
 * create_new_node - create a new heap node with value and parent
 * @value: value to store
 * @parent: parent node
 *
 * Return: pointer to new node or NULL
 */
heap_t *create_new_node(int value, heap_t *parent)
{
	heap_t *node;

	node = (heap_t *)binary_tree_node((binary_tree_t *)parent, value);
	if (node)
		node->n = value;
	return (node);
}

/**
 * bubble_up - restore max-heap by sifting node up (structural swap)
 * @node: node to sift up
 */
void bubble_up(heap_t *node)
{
	heap_t *parent;
	heap_t *grandparent;
	heap_t *sibling;
	heap_t *node_left;
	heap_t *node_right;

	while (node->parent && node->n > node->parent->n)
	{
		parent = node->parent;
		grandparent = parent->parent;
		sibling = (parent->left == node) ? parent->right : parent->left;
		node_left = node->left;
		node_right = node->right;

		if (grandparent)
		{
			if (grandparent->left == parent)
				grandparent->left = node;
			else
				grandparent->right = node;
		}
		node->parent = grandparent;
		parent->parent = node;

		if (parent->left == node)
		{
			node->left = parent;
			node->right = sibling;
		}
		else
		{
			node->right = parent;
			node->left = sibling;
		}
		if (sibling)
			sibling->parent = node;
		parent->left = node_left;
		parent->right = node_right;
		if (node_left)
			node_left->parent = parent;
		if (node_right)
			node_right->parent = parent;
	}
}

/**
 * node_at_position - get node at 1-based position in complete tree
 * @root: root of tree
 * @pos: 1-based position (1 = root)
 *
 * Return: pointer to node at position
 */
static heap_t *node_at_position(heap_t *root, size_t pos)
{
	size_t depth = 0;
	size_t p = pos;
	int d;
	heap_t *current;

	if (!root || pos <= 1)
		return (root);
	for (p = pos; p; p >>= 1)
		depth++;
	current = root;
	for (d = (int)depth - 2; d >= 0; d--)
		current = ((pos >> d) & 1) ? current->right : current->left;
	return (current);
}

/**
 * heap_size - count nodes in heap
 * @root: root of heap
 *
 * Return: number of nodes
 */
static size_t heap_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * find_insertion_parent - find parent for next node (complete tree order)
 * @root: root of heap
 *
 * Return: parent to attach new node to, or NULL if empty heap
 */
heap_t *find_insertion_parent(heap_t *root)
{
	size_t size;
	size_t parent_pos;

	if (!root)
		return (NULL);
	size = heap_size(root);
	if (size == 0)
		return (NULL);
	parent_pos = (size + 1) / 2;
	return (node_at_position(root, parent_pos));
}

/**
 * heap_insert - insert value into a max binary heap
 * @root: double pointer to root of heap
 * @value: value to insert
 *
 * Return: pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *new_node;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = create_new_node(value, NULL);
		return (*root);
	}
	parent = find_insertion_parent(*root);
	if (!parent)
		return (NULL);
	new_node = create_new_node(value, parent);
	if (!new_node)
		return (NULL);
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;
	bubble_up(new_node);
	return (new_node);
}
