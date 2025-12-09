#include "binary_trees.h"

/**
 * bst_insert_recursive - Helper to insert a value in a BST
 * @root: Pointer to the current node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure or duplicate
 */
static bst_t *bst_insert_recursive(bst_t *root, int value)
{
	bst_t *new_node;

	if (value < root->n)
	{
		if (root->left)
			return (bst_insert_recursive(root->left, value));

		new_node = binary_tree_node(root, value);
		if (!new_node)
			return (NULL);
		root->left = new_node;
		return (new_node);
	}
	if (value > root->n)
	{
		if (root->right)
			return (bst_insert_recursive(root->right, value));

		new_node = binary_tree_node(root, value);
		if (!new_node)
			return (NULL);
		root->right = new_node;
		return (new_node);
	}
	/* value == root->n → duplicate, ignore */
	return (NULL);
}

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure or duplicate
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (bst_insert_recursive(*tree, value));
}

