#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *node;

	if (!tree || !func)
		return;

	queue = queue_create();
	if (!queue)
		return;

	queue_enqueue(queue, (void *)tree);
	while (!queue_is_empty(queue))
	{
		node = (binary_tree_t *)queue_dequeue(queue);
		func(node->n);
		if (node->left)
			queue_enqueue(queue, node->left);
		if (node->right)
			queue_enqueue(queue, node->right);
	}
	queue_delete(queue);
}
