#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the ancestor node, or NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *a, *b;

	if (!first || !second)
		return (NULL);

	a = first;
	while (a)
	{
		b = second;
		while (b)
		{
			if (a == b)
				return ((binary_tree_t *)a);
			b = b->parent;
		}
		a = a->parent;
	}
	return (NULL);
}
