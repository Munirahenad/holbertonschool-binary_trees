#include "binary_trees.h"
#include <stdlib.h>

/**
 * min_node - Finds the minimum node in a subtree
 * @node: Pointer to subtree root
 *
 * Return: Pointer to minimum node, or NULL
 */
static avl_t *min_node(avl_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * rebalance - Rebalances an AVL subtree
 * @root: Pointer to subtree root
 *
 * Return: New subtree root after rotations
 */
static avl_t *rebalance(avl_t *root)
{
	int bal, child_bal;

	if (!root)
		return (NULL);

	bal = binary_tree_balance(root);

	if (bal > 1)
	{
		child_bal = binary_tree_balance(root->left);
		if (child_bal < 0)
			root->left = (avl_t *)binary_tree_rotate_left(root->left);
		root = (avl_t *)binary_tree_rotate_right(root);
	}
	else if (bal < -1)
	{
		child_bal = binary_tree_balance(root->right);
		if (child_bal > 0)
			root->right = (avl_t *)binary_tree_rotate_right(root->right);
		root = (avl_t *)binary_tree_rotate_left(root);
	}

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (root);
}

/**
 * delete_node - Deletes a node (0/1 child), returns replacement subtree root
 * @node: Node to delete
 *
 * Return: Replacement node, or NULL
 */
static avl_t *delete_node(avl_t *node)
{
	avl_t *tmp;

	if (!node->left && !node->right)
	{
		free(node);
		return (NULL);
	}

	if (!node->left || !node->right)
	{
		tmp = node->left ? node->left : node->right;
		tmp->parent = node->parent;
		free(node);
		return (tmp);
	}

	return (node);
}

/**
 * avl_remove_rec - Recursive helper to remove a value from AVL
 * @root: Pointer to subtree root
 * @value: Value to remove
 *
 * Return: New subtree root after deletion and rebalancing
 */
static avl_t *avl_remove_rec(avl_t *root, int value)
{
	avl_t *succ;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove_rec(root->left, value);
	else if (value > root->n)
		root->right = avl_remove_rec(root->right, value);
	else
	{
		root = delete_node(root);
		if (!root || (!root->left || !root->right))
			return (rebalance(root));

		succ = min_node(root->right);
		root->n = succ->n;
		root->right = avl_remove_rec(root->right, succ->n);
	}

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (rebalance(root));
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to root node
 * @value: Value to remove
 *
 * Return: New root after deletion and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = avl_remove_rec(root, value);
	if (root)
		root->parent = NULL;
	return (root);
}
