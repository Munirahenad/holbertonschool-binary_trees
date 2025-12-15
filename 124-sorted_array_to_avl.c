#include "binary_trees.h"

/**
 * build_avl - Builds a balanced AVL tree from a sorted array (helper)
 * @array: Pointer to first element of the array
 * @start: Start index (signed)
 * @end: End index (signed)
 * @parent: Pointer to parent node
 *
 * Return: Pointer to subtree root, or NULL
 */
static avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;
	root = (avl_t *)binary_tree_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = build_avl(array, start, mid - 1, root);
	root->right = build_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
