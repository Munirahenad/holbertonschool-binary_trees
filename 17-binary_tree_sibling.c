#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling of
 *
 * Return: Pointer to the sibling node, or NULL if no sibling exists
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is left child, return right child of parent */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If node is right child, return left child of parent */
	if (node->parent->right == node)
		return (node->parent->left);

	/* Node is not a child of its parent (should not happen in valid tree) */
	return (NULL);
}
