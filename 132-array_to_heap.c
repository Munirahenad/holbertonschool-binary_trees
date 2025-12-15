#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created Binary Heap,
 *         or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	/* Check for invalid input */
	if (array == NULL || size == 0)
		return (NULL);

	/* Insert each element from array into the heap */
	for (i = 0; i < size; i++)
	{
		/* heap_insert handles memory allocation and returns new node */
		if (heap_insert(&root, array[i]) == NULL)
		{
			/* In case of failure, clean up and return NULL */
			binary_tree_delete(root);
			return (NULL);
		}
	}

	return (root);
}
