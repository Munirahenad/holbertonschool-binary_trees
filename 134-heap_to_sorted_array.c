#include "binary_trees.h"

/**
 * heap_size - Computes the number of nodes in a heap
 * @heap: Pointer to the root node of the heap
 *
 * Return: Number of nodes in the heap
 */
static size_t heap_size(const heap_t *heap)
{
	if (heap == NULL)
		return (0);

	return (1 + heap_size(heap->left) + heap_size(heap->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to sorted array in descending order, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t i, count;

	if (heap == NULL || size == NULL)
		return (NULL);

	/* Calculate heap size */
	count = heap_size(heap);
	*size = count;

	if (count == 0)
		return (NULL);

	/* Allocate memory for sorted array */
	sorted_array = malloc(sizeof(int) * count);
	if (sorted_array == NULL)
		return (NULL);

	/* Extract elements from heap - they come out in descending order */
	for (i = 0; i < count; i++)
	{
		/* heap_extract will modify the heap */
		sorted_array[i] = heap_extract(&heap);
	}

	return (sorted_array);
}
