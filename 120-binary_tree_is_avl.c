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

	/* BST property check */
	if (tree->n <= min || tree->n >= max)
		return (-1);

	left_h = avl_helper(tree->left, min, tree->n);
	if (left_h == -1)
		return (-1);

	right_h = avl_helper(tree->right, tree->n, max);
	if (right_h == -1)
		return (-1);

	/* Balance factor check */
	diff = left_h - right_h;
	if (diff > 1 || diff < -1)
		return (-1);

	/* Return height */
	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h;

	if (!tree)
		return (0);

	h = avl_helper(tree, INT_MIN, INT_MAX);

	return (h == -1 ? 0 : 1);
}

