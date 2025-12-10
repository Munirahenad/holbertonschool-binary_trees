#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to first element of array
 * @size: Number of elements in the array
 *
 * Return: Pointer to root of AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
        avl_insert(&root, array[i]);

    return (root);
}

