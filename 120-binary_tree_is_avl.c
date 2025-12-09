#include "binary_trees.h"
#include <limits.h>

/**
 * avl_helper - Helper to check if a tree is a valid AVL tree
 * @tree: Pointer to the root node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: Height of tree if AVL, -1 otherwise
 */
static int avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_h, right_h, diff;

	if (!tree)
		return (0);

	if (tree->n <= min || tree->n >= max)
		return (-1);

	left_h = avl_helper(tree->left, min, tree->n);
	if (left_h == -1)
		return (-1);

	right_h = avl_helper(tree->right, tree->n, max);

