#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: Number of nodes with at least 1 child, 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t nodes = 0;

if (tree == NULL)
return (0);

/* If node has at least one child, count it */
if (tree->left != NULL || tree->right != NULL)
nodes = 1;

/* Recursively count nodes in left and right subtrees */
nodes += binary_tree_nodes(tree->left);
nodes += binary_tree_nodes(tree->right);

return (nodes);
}
