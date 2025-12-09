#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_min - Finds the node with minimum value in a BST
 * @root: Pointer to the root node
 *
 * Return: Pointer to the minimum node
 */
static bst_t *bst_min(bst_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * bst_remove_recursive - Removes a value from a BST (helper)
 * @root: Pointer to the root of the subtree
 * @value: Value to remove
 *
 * Return: New root of the subtree
 */
static bst_t *bst_remove_recursive(bst_t *root, int value)
{
	bst_t *tmp, *succ;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove_recursive(root->left, value);
	else if (value > root->n)
		root->right = bst_remove_recursive(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			tmp = root->left ? root->left : root->right;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}
		succ = bst_min(root->right);
		root->n = succ->n;
		root->right = bst_remove_recursive(root->right, succ->n);
	}

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove
 *
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	root = bst_remove_recursive(root, value);

	if (root)
		root->parent = NULL;

	return (root);
}

