#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_min - Finds the minimum node in a subtree
 * @node: Pointer to subtree root
 *
 * Return: Pointer to minimum node, or NULL
 */
static avl_t *avl_min(avl_t *node)
{
	while (node && node->left)
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
 * rebalance_left - Rebalance when subtree is left heavy
 * @root: Pointer to subtree root
 *
 * Return: New subtree root
 */
static avl_t *rebalance_left(avl_t *root)
{
	int child_bal;

	child_bal = binary_tree_balance(root->left);
	if (child_bal >= 0)
		return ((avl_t *)binary_tree_rotate_right(root));

	root->left = (avl_t *)binary_tree_rotate_left(root->left);
	fix_children_parents(root);
	return ((avl_t *)binary_tree_rotate_right(root));
}

/**
 * rebalance_right - Rebalance when subtree is right heavy
 * @root: Pointer to subtree root
 *
 * Return: New subtree root
 */
static avl_t *rebalance_right(avl_t *root)
{
	int child_bal;

	child_bal = binary_tree_balance(root->right);
	if (child_bal <= 0)
		return ((avl_t *)binary_tree_rotate_left(root));

	root->right = (avl_t *)binary_tree_rotate_right(root->right);
	fix_children_parents(root);
	return ((avl_t *)binary_tree_rotate_left(root));
}

/**
 * rebalance_after_delete - Rebalances AVL subtree after deletion
 * @root: Pointer to subtree root
 *
 * Return: New root of subtree after rotations
 */
static avl_t *rebalance_after_delete(avl_t *root)
{
	int bal;

	if (!root)
		return (NULL);

	bal = binary_tree_balance(root);
	if (bal > 1)
		root = rebalance_left(root);
	else if (bal < -1)
		root = rebalance_right(root);

	fix_children_parents(root);
	return (root);
}

/**
 * delete_found_node - Deletes a found node and returns new subtree root
 * @root: Node to delete (subtree root)
 *
 * Return: New subtree root after deletion (before rebalancing)
 */
static avl_t *delete_found_node(avl_t *root)
{
	avl_t *tmp;

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
	return (root);
}

/**
 * replace_with_successor - Replaces node value with in-order successor
 * @root: Node with two children
 *
 * Return: Root node (same pointer)
 */
static avl_t *replace_with_successor(avl_t *root)
{
	avl_t *succ;

	succ = avl_min(root->right);
	root->n = succ->n;
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
		root = delete_found_node(root);
		if (!root || (!root->left || !root->right))
			return (rebalance_after_delete(root));

		root = replace_with_successor(root);
		root->right = avl_remove_rec(root->right, root->n);
		if (root->right)
			root->right->parent = root;
	}

	return (rebalance_after_delete(root));
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to root node
 * @value: Value to remove
 *
 * Return: Pointer to new root after removal and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = avl_remove_rec(root, value);
	if (root)
		root->parent = NULL;
	return (root);
}
