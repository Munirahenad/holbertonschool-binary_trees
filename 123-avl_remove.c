#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_min - Finds the minimum node in an AVL subtree
 * @node: Pointer to subtree root
 *
 * Return: Pointer to minimum node, or NULL
 */
static avl_t *avl_min(avl_t *node)
{
	if (!node)
		return (NULL);

	while (node->left)
		node = node->left;

	return (node);
}

/**
 * fix_children_parents - Fixes parent pointers of root children
 * @root: Pointer to subtree root
 */
static void fix_children_parents(avl_t *root)
{
	if (!root)
		return;

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
}

/**
 * rebalance_after_delete - Rebalances AVL subtree after deletion
 * @root: Pointer to subtree root
 *
 * Return: New root of subtree after rotations (or same root)
 */
static avl_t *rebalance_after_delete(avl_t *root)
{
	int bal, child_bal;

	if (!root)
		return (NULL);

	bal = binary_tree_balance(root);

	/* Left heavy */
	if (bal > 1)
	{
		child_bal = binary_tree_balance(root->left);

		/* Left-Left */
		if (child_bal >= 0)
			root = (avl_t *)binary_tree_rotate_right(root);
		else
		{
			/* Left-Right */
			root->left = (avl_t *)binary_tree_rotate_left(root->left);
			fix_children_parents(root);
			root = (avl_t *)binary_tree_rotate_right(root);
		}
	}
	/* Right heavy */
	else if (bal < -1)
	{
		child_bal = binary_tree_balance(root->right);

		/* Right-Right */
		if (child_bal <= 0)
			root = (avl_t *)binary_tree_rotate_left(root);
		else
		{
			/* Right-Left */
			root->right = (avl_t *)binary_tree_rotate_right(root->right);
			fix_children_parents(root);
			root = (avl_t *)binary_tree_rotate_left(root);
		}
	}

	fix_children_parents(root);
	return (root);
}

/**
 * avl_remove_rec - Recursive helper to remove a value from AVL tree
 * @root: Pointer to subtree root
 * @value: Value to remove
 *
 * Return: New subtree root after deletion + rebalancing
 */
static avl_t *avl_remove_rec(avl_t *root, int value)
{
	avl_t *tmp, *succ;

	if (!root)
		return (NULL);

	if (value < root->n)
	{
		root->left = avl_remove_rec(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = avl_remove_rec(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		/* Node found */
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		if (!root->left || !root->right)
		{
			tmp = root->left ? root->left : root->right;
			tmp->parent = root->parent;
			free(root);
			return (tmp);
		}

		/* Two children: replace with in-order successor */
		succ = avl_min(root->right);
		root->n = succ->n;
		root->right = avl_remove_rec(root->right, succ->n);
		if (root->right)
			root->right->parent = root;
	}

	return (rebalance_after_delete(root));
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value to remove
 *
 * Return: Pointer to new root node after removal and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = avl_remove_rec(root, value);

	if (root)
		root->parent = NULL;

	return (root);
}
