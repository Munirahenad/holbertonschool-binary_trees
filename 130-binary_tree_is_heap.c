#include "binary_trees.h"

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes
 */
static size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete_recursive - Helper to check if tree is complete
 * @tree: Pointer to current node
 * @index: Index of current node (0-based)
 * @node_count: Total number of nodes in tree
 *
 * Return: 1 if complete, 0 otherwise
 */
static int is_complete_recursive(const binary_tree_t *tree,
				 size_t index, size_t node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
		is_complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to root node
 *
 * Return: 1 if complete, 0 otherwise
 */
static int is_complete(const binary_tree_t *tree)
{
	size_t node_count;

	if (tree == NULL)
		return (0);

	node_count = count_nodes(tree);
	return (is_complete_recursive(tree, 0, node_count));
}

/**
 * is_max_heap_recursive - Recursive helper to check max heap property
 * @tree: Pointer to current node
 *
 * Return: 1 if max heap property holds, 0 otherwise
 */
static int is_max_heap_recursive(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	/* Check if current node is greater than or equal to children */
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);

	/* Recursively check subtrees */
	return (is_max_heap_recursive(tree->left) &&
		is_max_heap_recursive(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* A max heap must be a complete tree */
	if (!is_complete(tree))
		return (0);

	/* Check max heap property (parent >= children) */
	return (is_max_heap_recursive(tree));
}
