Task 1: Insert Left
c
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
Description: Inserts a new node as the left-child of the given parent node. If the parent already has a left-child, the new node takes its place, and the old left-child becomes the left-child of the new node.

Task 2: Insert Right
c
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
Description: Inserts a new node as the right-child of the given parent node. If the parent already has a right-child, the new node takes its place, and the old right-child becomes the right-child of the new node.

Task 3: Delete
c
void binary_tree_delete(binary_tree_t *tree);
Description: Deletes an entire binary tree using post-order traversal (children before parent) to safely free all allocated memory.

Task 4: Is Leaf
c
int binary_tree_is_leaf(const binary_tree_t *node);
Description: Checks if a node is a leaf (has no children). Returns 1 if leaf, 0 otherwise.

Task 5: Is Root
c
int binary_tree_is_root(const binary_tree_t *node);
Description: Checks if a node is a root (has no parent). Returns 1 if root, 0 otherwise.

Task 6: Pre-order Traversal
c
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
Description: Performs pre-order traversal (Root → Left → Right) and applies the given function to each node's value.

Task 7: In-order Traversal
c
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
Description: Performs in-order traversal (Left → Root → Right) and applies the given function to each node's value.

Task 8: Post-order Traversal
c
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
Description: Performs post-order traversal (Left → Right → Root) and applies the given function to each node's value.

Task 9: Height
c
size_t binary_tree_height(const binary_tree_t *tree);
Description: Measures the height of a binary tree. Height of NULL tree = 0, height of leaf node = 0.

Task 10: Depth
c
size_t binary_tree_depth(const binary_tree_t *node);
Description: Measures the depth of a node in a binary tree. Depth of root node = 0.

Task 11: Size
c
size_t binary_tree_size(const binary_tree_t *tree);
Description: Measures the size of a binary tree (total number of nodes).

Task 12: Leaves
c
size_t binary_tree_leaves(const binary_tree_t *tree);
Description: Counts the number of leaf nodes in a binary tree (nodes with no children).

Task 13: Nodes
c
size_t binary_tree_nodes(const binary_tree_t *tree);
Description: Counts the number of nodes with at least 1 child in a binary tree.

Task 14: Balance Factor
c
int binary_tree_balance(const binary_tree_t *tree);
Description: Calculates the balance factor of a binary tree: height(left subtree) - height(right subtree).

Task 15: Is Full
c
int binary_tree_is_full(const binary_tree_t *tree);
Description: Checks if a binary tree is full (every node has either 0 or 2 children).

Task 16: Is Perfect
c
int binary_tree_is_perfect(const binary_tree_t *tree);
Description: Checks if a binary tree is perfect (all levels are completely filled).

Task 17: Sibling
c
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
Description: Finds the sibling of a node (other child of the same parent). Returns pointer to sibling or NULL.

Task 18: Uncle
c
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
Description: Finds the uncle of a node (parent's sibling). Returns pointer to uncle or NULL.Task 1: Insert Left
c
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
Description: Inserts a new node as the left-child of the given parent node. If the parent already has a left-child, the new node takes its place, and the old left-child becomes the left-child of the new node.

Task 2: Insert Right
c
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
Description: Inserts a new node as the right-child of the given parent node. If the parent already has a right-child, the new node takes its place, and the old right-child becomes the right-child of the new node.

Task 3: Delete
c
void binary_tree_delete(binary_tree_t *tree);
Description: Deletes an entire binary tree using post-order traversal (children before parent) to safely free all allocated memory.

Task 4: Is Leaf
c
int binary_tree_is_leaf(const binary_tree_t *node);
Description: Checks if a node is a leaf (has no children). Returns 1 if leaf, 0 otherwise.

Task 5: Is Root
c
int binary_tree_is_root(const binary_tree_t *node);
Description: Checks if a node is a root (has no parent). Returns 1 if root, 0 otherwise.

Task 6: Pre-order Traversal
c
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
Description: Performs pre-order traversal (Root → Left → Right) and applies the given function to each node's value.

Task 7: In-order Traversal
c
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
Description: Performs in-order traversal (Left → Root → Right) and applies the given function to each node's value.

Task 8: Post-order Traversal
c
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
Description: Performs post-order traversal (Left → Right → Root) and applies the given function to each node's value.

Task 9: Height
c
size_t binary_tree_height(const binary_tree_t *tree);
Description: Measures the height of a binary tree. Height of NULL tree = 0, height of leaf node = 0.

Task 10: Depth
c
size_t binary_tree_depth(const binary_tree_t *node);
Description: Measures the depth of a node in a binary tree. Depth of root node = 0.

Task 11: Size
c
size_t binary_tree_size(const binary_tree_t *tree);
Description: Measures the size of a binary tree (total number of nodes).

Task 12: Leaves
c
size_t binary_tree_leaves(const binary_tree_t *tree);
Description: Counts the number of leaf nodes in a binary tree (nodes with no children).

Task 13: Nodes
c
size_t binary_tree_nodes(const binary_tree_t *tree);
Description: Counts the number of nodes with at least 1 child in a binary tree.

Task 14: Balance Factor
c
int binary_tree_balance(const binary_tree_t *tree);
Description: Calculates the balance factor of a binary tree: height(left subtree) - height(right subtree).

Task 15: Is Full
c
int binary_tree_is_full(const binary_tree_t *tree);
Description: Checks if a binary tree is full (every node has either 0 or 2 children).

Task 16: Is Perfect
c
int binary_tree_is_perfect(const binary_tree_t *tree);
Description: Checks if a binary tree is perfect (all levels are completely filled).

Task 17: Sibling
c
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
Description: Finds the sibling of a node (other child of the same parent). Returns pointer to sibling or NULL.

Task 18: Uncle
c
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
Description: Finds the uncle of a node (parent's sibling). Returns pointer to uncle or NULL.
