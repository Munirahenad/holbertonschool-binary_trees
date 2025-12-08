#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: The value in the node is passed as a parameter to func
 * If tree or func is NULL, do nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check for NULL pointers */
	if (tree == NULL || func == NULL)
		return;

	/* Pre-order: Root -> Left -> Right */
	func(tree->n);				/* Process current node */
	binary_tree_preorder(tree->left, func);	/* Traverse left subtree */
	binary_tree_preorder(tree->right, func);	/* Traverse right subtree */
}
