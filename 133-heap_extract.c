#include "binary_trees.h"

/**
 * tree_height - Measures height of a binary tree
 * @tree: Pointer to root node
 *
 * Return: Height of tree, 0 if NULL
 */
static size_t tree_height(const heap_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * tree_size - Counts nodes in binary tree
 * @tree: Pointer to root node
 *
 * Return: Number of nodes
 */
static size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * find_last_node - Finds last node in level-order traversal
 * @root: Pointer to root node
 *
 * Return: Pointer to last node
 */
static heap_t *find_last_node(heap_t *root)
{
	heap_t *last = NULL;
	heap_t *queue[1024];
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		last = queue[front++];

		if (last->left)
			queue[rear++] = last->left;
		if (last->right)
			queue[rear++] = last->right;
	}

	return (last);
}

/**
 * heapify_down - Moves node down to maintain max heap property
 * @root: Double pointer to root node
 */
static void heapify_down(heap_t **root)
{
	heap_t *node, *child;
	int temp;

	if (!root || !*root)
		return;

	node = *root;

	while (1)
	{
		child = NULL;

		/* Find larger child */
		if (node->left && node->right)
			child = (node->left->n > node->right->n) ? node->left : node->right;
		else if (node->left)
			child = node->left;
		else if (node->right)
			child = node->right;

		/* If no child or child is smaller, heap property satisfied */
		if (!child || child->n <= node->n)
			break;

		/* Swap values with larger child */
		temp = node->n;
		node->n = child->n;
		child->n = temp;

		/* Move down to child */
		node = child;
	}
}

/**
 * remove_last_node - Removes last node from heap
 * @root: Pointer to root node
 * @last: Pointer to last node
 */
static void remove_last_node(heap_t *root, heap_t *last)
{
	if (!root || !last)
		return;

	/* Disconnect last node from parent */
	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}

	free(last);
}

/**
 * heap_extract - Extracts root node of a Max Binary Heap
 * @root: Double pointer to root node of heap
 *
 * Return: Value stored in root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int root_value;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	/* Save root value */
	root_value = (*root)->n;

	/* If only one node in heap */
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

	/* Find last node in level-order */
	last_node = find_last_node(*root);

	/* Replace root value with last node value */
	(*root)->n = last_node->n;

	/* Remove last node */
	remove_last_node(*root, last_node);

	/* Restore max heap property */
	heapify_down(root);

	return (root_value);
}
