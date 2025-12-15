#include "binary_trees.h"

/**
 * get_last_parent - Finds the parent for new node using BFS
 * @root: Pointer to root node
 *
 * Return: Pointer to parent node
 */
static heap_t *get_last_parent(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;
	heap_t *parent = root;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		parent = queue[front++];
		
		/* If parent has an empty child slot, return it */
		if (!parent->left || !parent->right)
			return (parent);
			
		queue[rear++] = parent->left;
		queue[rear++] = parent->right;
	}
	
	return (parent);
}

/**
 * swap_values - Swaps values between two nodes
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
 * heapify_up - Bubbles up node to maintain max heap property
 * @node: Node to bubble up
 *
 * Return: Pointer to node after heapify
 */
static heap_t *heapify_up(heap_t *node)
{
	if (!node)
		return (NULL);

	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to root node
 * @value: Value to insert
 *
 * Return: Pointer to created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	/* Create new node */
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	/* If heap is empty, new node becomes root */
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	/* Find parent for new node (first node with empty child slot) */
	parent = get_last_parent(*root);

	/* Attach new node to parent */
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	/* Heapify up to maintain max heap property */
	return (heapify_up(new_node));
}
