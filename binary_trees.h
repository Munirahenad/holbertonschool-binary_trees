#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/* Type aliases */
typedef binary_tree_t bst_t;
typedef binary_tree_t avl_t;
typedef binary_tree_t heap_t;

/* Printing */
void binary_tree_print(const binary_tree_t *tree);

/* Basic binary tree */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);

/* Binary tree measures */
int binary_tree_balance(const binary_tree_t *tree);

/* Binary tree rotations */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* Binary Search Tree (BST) */
bst_t *bst_insert(bst_t **tree, int value);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

/* AVL Tree */
avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_remove(avl_t *root, int value);

/* Array to trees */
bst_t *array_to_bst(int *array, size_t size);
avl_t *array_to_avl(int *array, size_t size);
avl_t *sorted_array_to_avl(int *array, size_t size);

#endif /* BINARY_TREES_H */
