#include "binary_trees.h"

/**
 * binary_tree_height - Measures height (edges count)
 * @tree: Pointer to root node
 *
 * Return: Height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t l = 0, r = 0;

if (tree == NULL)
return (0);

l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

return (l > r ? l : r);
}

/**
 * binary_tree_balance - Measures balance factor
 * @tree: Pointer to root node
 *
 * Return: Balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int left_h, right_h;

if (tree == NULL)
return (0);

left_h = tree->left ? (int)binary_tree_height(tree->left) + 1 : 0;
right_h = tree->right ? (int)binary_tree_height(tree->right) + 1 : 0;

return (left_h - right_h);
}
