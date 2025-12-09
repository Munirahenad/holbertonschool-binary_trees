#include "binary_trees.h"
#include <stdlib.h>

/**
 * check_complete - Helper that verifies if a tree is complete
 * @tree: Pointer to the root node
 * @queue: Array used as a queue for level-order traversal
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
static int check_complete(const binary_tree_t *tree,
		const binary_tree_t **queue)
{
	int front = 0, rear = 0, flag = 0;
	const binary_tree_t *node;

	queue[rear++] = tree;

	while (front < rear)
	{
		node = queue[front++];

		if (node->left)
		{
			if (flag)
				return (0);
			queue[rear++] = node->left;
		}
		else
			flag = 1;

		if (node->right)
		{
			if (flag)
				return (0);
			queue[rear++] = node->right;
		}
		else
			flag = 1;
	}

	return (1);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	int capacity = 1024;
	int result;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * capacity);
	if (!queue)
		return (0);

	result = check_complete(tree, queue);

	free(queue);
	return (result);
}

