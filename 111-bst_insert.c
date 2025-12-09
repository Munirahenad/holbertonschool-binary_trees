#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure or duplicate
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new_node;

	if (tree == NULL)
		return (NULL);

	/* If tree is empty, new node becomes root */
	if (*tree == NULL)
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;

	while (current)
	{
		/* Duplicate value → ignore */
		if (value == current->n)
			return (NULL);

		if (value < current->n)
		{
			if (current->left == NULL)
			{
				new_node = (bst_t *)binary_tree_node(current, value);
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				new_node = (bst_t *)binary_tree_node(current, value);
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
	}

	return (NULL);
}

