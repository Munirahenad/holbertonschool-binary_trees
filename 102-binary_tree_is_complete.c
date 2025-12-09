#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	int front = 0, rear = 0;
	int flag = 0;
	int capacity = 1024;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * capacity);
	if (!queue)
		return (0);

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *node = queue[front++];

		/* Left child */
		if (node->left)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = node->left;
		}
		else
			flag = 1;

		/* Right child */
		if (node->right)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = node->right;
		}
		else
			flag = 1;
	}

	free(queue);
	return (1);
}

