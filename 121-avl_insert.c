#include "binary_trees.h"

/**
 * rebalance - Rebalances an AVL subtree after insertion
 * @root: Pointer to the root of the subtree
 * @value: Inserted value
 *
 * Return: New root of the subtree
 */
static avl_t *rebalance(avl_t *root, int value)
{
	int balance = binary_tree_balance(root);

	/* Left Left case */
	if (balance > 1 && value < root->left->n)
		return ((avl_t *)binary_tree_rotate_right(root));

	/* Left Right case */
	if (balance > 1 && value > root->left->n)
	{
		root->left = (avl_t *)binary_tree_rotate_left(root->left);
		return ((avl_t *)binary_tree_rotate_right(root));
	}

	/* Right Right case */
	if (balance < -1 && value > root->right->n)
		return ((avl_t *)binary_tree_rotate_left(root));

	/* Right Left case */
	if (balance < -1 && value < root->right->n)
	{
		root->right = (avl_t *)binary_tree_rotate_right(root->right);
		return ((avl_t *)binary_tree_rotate_left(root));
	}

	return (root);
}

/**
 * avl_insert_rec - Recursive helper to insert in an AVL tree
 * @root: Pointer to the root of the subtree
 * @value: Value to insert
 * @new_node: Address of pointer to store created node
 *
 * Return: New root of the subtree
 */
static avl_t *avl_insert_rec(avl_t *root, int value, avl_t **new_node)
{
	if (!root)
	{
		*new_node = (avl_t *)binary_tree_node(NULL, value);
		return (*new_node);
	}

	if (value < root->n)
	{
		root->left = avl_insert_rec(root->left, value, new_node);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = avl_insert_rec(root->right, value, new_node);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		*new_node = NULL; /* Duplicate, ignore */
		return (root);
	}

	return (rebalance(root, value));
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = (avl_t *)binary_tree_node(NULL, value);
		return (*tree);
	}

	*tree = avl_insert_rec(*tree, value, &new_node);
	if (*tree)
		(*tree)->parent = NULL;

	return (new_node);
}

