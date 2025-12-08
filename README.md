# holbertonschool-binary_treeis

Binary Trees Project 📖 Description This project is a comprehensive implementation of binary tree data structures in C, developed as part of the Holberton School curriculum. The goal is to implement various operations and algorithms related to binary trees, binary search trees, and balanced trees.

📁 Project Structure text binary_trees/ ├── binary_trees.h ├── 0-binary_tree_node.c ├── 1-binary_tree_insert_left.c ├── 2-binary_tree_insert_right.c ├── 3-binary_tree_delete.c ├── 4-binary_tree_is_leaf.c ├── 5-binary_tree_is_root.c ├── 6-binary_tree_preorder.c ├── 7-binary_tree_inorder.c ├── 8-binary_tree_postorder.c ├── 9-binary_tree_height.c ├── 10-binary_tree_depth.c ├── 11-binary_tree_size.c ├── 12-binary_tree_leaves.c ├── 13-binary_tree_nodes.c ├── 14-binary_tree_balance.c ├── 15-binary_tree_is_full.c ├── 16-binary_tree_is_perfect.c ├── 17-binary_tree_sibling.c ├── 18-binary_tree_uncle.c └── README.md 📋 File Descriptions File Description binary_trees.h Header file containing structure definitions and function prototypes 0-binary_tree_node.c Function to create a binary tree node 1-binary_tree_insert_left.c Function to insert a node as left-child 2-binary_tree_insert_right.c Function to insert a node as right-child 3-binary_tree_delete.c Function to delete an entire binary tree 4-binary_tree_is_leaf.c Function to check if a node is a leaf 5-binary_tree_is_root.c Function to check if a node is a root 6-binary_tree_preorder.c Function for pre-order traversal 7-binary_tree_inorder.c Function for in-order traversal 8-binary_tree_postorder.c Function for post-order traversal 9-binary_tree_height.c Function to measure height of a binary tree 10-binary_tree_depth.c Function to measure depth of a node 11-binary_tree_size.c Function to measure size of a binary tree 12-binary_tree_leaves.c Function to count leaves in a binary tree 13-binary_tree_nodes.c Function to count nodes with at least 1 child 14-binary_tree_balance.c Function to measure balance factor of a binary tree 15-binary_tree_is_full.c Function to check if a binary tree is full 16-binary_tree_is_perfect.c Function to check if a binary tree is perfect 17-binary_tree_sibling.c Function to find the sibling of a node 18-binary_tree_uncle.c Function to find the uncle of a node README.md Project documentation ⚙️ General Requirements Requirement Specification Allowed editors vi, vim, emacs Code style Betty style (checked with betty-style.pl and betty-doc.pl) Global variables Not allowed Functions per file Maximum 5 functions Header file binary_trees.h with include guards File endings All files must end with a new line ✅ Authorized Functions and Macros malloc (man 3 malloc)

free (man 3 free)

printf (for debugging purposes only)

🎯 Tasks Task 0: New node Function: binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)

Creates a binary tree node

Returns pointer to new node, or NULL on failure

Task 1: Insert left Function: binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)

Inserts a node as the left-child of another node

If parent already has a left-child, new node takes its place

Task 2: Insert right Function: binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)

Inserts a node as the right-child of another node

If parent already has a right-child, new node takes its place

Task 3: Delete Function: void binary_tree_delete(binary_tree_t *tree)

Deletes an entire binary tree

Uses post-order traversal

Task 4: Is leaf Function: int binary_tree_is_leaf(const binary_tree_t *node)

Checks if a node is a leaf

Returns 1 if node is a leaf, 0 otherwise

Task 5: Is root Function: int binary_tree_is_root(const binary_tree_t *node)

Checks if a node is a root

Returns 1 if node is a root, 0 otherwise

Task 6: Pre-order traversal Function: void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))

Goes through a binary tree using pre-order traversal

Applies function to each node's value

Task 7: In-order traversal Function: void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))

Goes through a binary tree using in-order traversal

Applies function to each node's value

Task 8: Post-order traversal Function: void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))

Goes through a binary tree using post-order traversal

Applies function to each node's value

Task 9: Height Function: size_t binary_tree_height(const binary_tree_t *tree)

Measures the height of a binary tree

Height of NULL tree is 0

Height of leaf node is 0

Task 10: Depth Function: size_t binary_tree_depth(const binary_tree_t *node)

Measures the depth of a node in a binary tree

Depth of root is 0

Task 11: Size Function: size_t binary_tree_size(const binary_tree_t *tree)

Measures the size of a binary tree

Size = number of nodes in tree

Task 12: Leaves Function: size_t binary_tree_leaves(const binary_tree_t *tree)

Counts the leaves in a binary tree

Leaves = nodes with no children

Task 13: Nodes Function: size_t binary_tree_nodes(const binary_tree_t *tree)

Counts the nodes with at least 1 child in a binary tree

Task 14: Balance factor Function: int binary_tree_balance(const binary_tree_t *tree)

Measures the balance factor of a binary tree

Balance factor = height(left) - height(right)

Task 15: Is full Function: int binary_tree_is_full(const binary_tree_t *tree)

Checks if a binary tree is full

Full tree: every node has 0 or 2 children

Task 16: Is perfect Function: int binary_tree_is_perfect(const binary_tree_t *tree)

Checks if a binary tree is perfect

Perfect tree: all levels completely filled

Task 17: Sibling Function: binary_tree_t *binary_tree_sibling(binary_tree_t *node)

Finds the sibling of a node

Returns pointer to sibling node, or NULL

Task 18: Uncle Function: binary_tree_t *binary_tree_uncle(binary_tree_t *node)

Finds the uncle of a node

Returns pointer to uncle node, or NULL

🛡️ Edge Cases Handled NULL pointers: Functions handle NULL input gracefully

Empty trees: Operations on empty trees return appropriate values

Single node trees: Functions work correctly with single nodes

Invalid operations: Appropriate return values for invalid operationsi

🔄 Tree Types Supported Tree Type Definition Binary Tree Each node has at most 2 children Full Binary Tree Every node has 0 or 2 children Perfect Binary Tree All levels completely filled Complete Binary Tree All levels except possibly last are filled 🔮 Future Enhancements Potential Extensions Binary Search Trees (BST): Insert, search, delete operations

AVL Trees: Self-balancing binary search trees

Heap Operations: Max-heap and min-heap implementations

Additional Functions:

Lowest Common Ancestor (LCA)

Level-order traversal

Check if tree is BST

Convert array to binary tree

Serialize/deserialize binary trees

Advanced Algorithms:

Diameter of binary tree

Maximum path sum

Construct tree from traversals

Morris traversal (O(1) space)
