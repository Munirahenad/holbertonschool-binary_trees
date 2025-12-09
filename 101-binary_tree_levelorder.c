#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_height - Measures height of a binary tree
 * @tree: Pointer to root node
 *
 * Return: Height, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_h = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_h = 1 + binary_tree_height(tree->right);

	return (left_h > right_h ? left_h : right_h);
}

/**
 * print_level - Prints all nodes at a specific level
 * @tree: Pointer to root node
 * @level: Level to print
 * @func: Function pointer
 */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node
 * @func: Function pointer to call for each value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, level;

	if (!tree || !func)
		return;

	h = binary_tree_height(tree);

	for (level = 1; level <= h + 1; level++)
	{
		print_level(tree, level, func);
	}
}

