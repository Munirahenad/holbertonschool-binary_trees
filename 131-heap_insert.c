#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
static size_t tree_height(const heap_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * tree_size - Counts the total nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes
 */
static size_t tree_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * find_parent - Finds the parent node for new insertion
 * @root: Pointer to the root node
 *
 * Return: Pointer to the parent node
 */
static heap_t *find_parent(heap_t *root)
{
	heap_t *parent = root;
	size_t left_size, right_size, left_height, right_height;

	if (root == NULL)
		return (NULL);

	/* Check if tree is perfect */
	left_size = tree_size(root->left);
	right_size = tree_size(root->right);
	
	if (left_size == right_size)
		return (root); /* Perfect tree, insert at leftmost */

	left_height = tree_height(root->left);
	right_height = tree_height(root->right);

	if (left_height > right_height)
	{
		/* Left subtree is taller, check if left is perfect */
		if (tree_size(root->left->left) == tree_size(root->left->right))
			parent = find_parent(root->right);
		else
			parent = find_parent(root->left);
	}
	else
	{
		/* Right subtree might be incomplete */
		parent = find_parent(root->left);
	}

	return (parent);
}

/**
 * swap_values - Swaps the values of two nodes
 * @a: First node
 * @b: Second node
 */
static void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_up - Bubbles up a node to maintain max heap property
 * @node: Node to bubble up
 *
 * Return: Pointer to the node after heapify
 */
static heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	/* Create new node */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* If heap is empty */
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* Find parent for new node */
	parent = find_parent(*root);

	/* Attach new node to parent */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	/* Heapify up to maintain max heap property */
	return (heapify_up(new_node));
}
