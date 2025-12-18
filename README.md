# Binary Trees

## 📌 Description
Binary Trees are data structures where each node has at most two children.  
They enable efficient data operations and serve as foundational building blocks for advanced algorithms and real-world applications such as databases and AI systems.

---

## 🧠 Learning Objectives
By completing this project, you should be able to:

- Understand what a binary tree is
- Differentiate between a binary tree and a Binary Search Tree (BST)
- Identify time complexity gains compared to linked lists
- Define the depth, height, and size of a binary tree
- Use different tree traversal methods
- Understand complete, full, perfect, and balanced binary trees

---

## ⚙️ Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- Compiled on **Ubuntu 20.04 LTS** using:
- All files must end with a new line
- A `README.md` file at the root is mandatory
- Code must follow **Betty style**
- No global variables allowed
- No more than **5 functions per file**
- Standard library allowed
- `main.c` files are for testing only and must not be pushed
- All function prototypes must be in `binary_trees.h`
- Header files must be include guarded

---

## 📋 File Descriptions

| File | Description | Time Complexity |
|-----|------------|----------------|
| binary_trees.h | Header file with structures and prototypes | - |
| 0-binary_tree_node.c | Creates a binary tree node | O(1) |
| 1-binary_tree_insert_left.c | Inserts node as left child | O(1) |
| 2-binary_tree_insert_right.c | Inserts node as right child | O(1) |
| 3-binary_tree_delete.c | Deletes entire binary tree | O(n) |
| 4-binary_tree_is_leaf.c | Checks if node is a leaf | O(1) |
| 5-binary_tree_is_root.c | Checks if node is a root | O(1) |
| 6-binary_tree_preorder.c | Pre-order traversal | O(n) |
| 7-binary_tree_inorder.c | In-order traversal | O(n) |
| 8-binary_tree_postorder.c | Post-order traversal | O(n) |
| 9-binary_tree_height.c | Measures tree height | O(n) |
| 10-binary_tree_depth.c | Measures node depth | O(n) |
| 11-binary_tree_size.c | Measures tree size | O(n) |
| 12-binary_tree_leaves.c | Counts leaf nodes | O(n) |
| 13-binary_tree_nodes.c | Counts nodes with children | O(n) |
| 14-binary_tree_balance.c | Measures balance factor | O(n) |
| 15-binary_tree_is_full.c | Checks if tree is full | O(n) |
| 16-binary_tree_is_perfect.c | Checks if tree is perfect | O(n) |
| 17-binary_tree_sibling.c | Finds sibling of a node | O(1) |
| 18-binary_tree_uncle.c | Finds uncle of a node | O(1) |
| README.md | Project documentation | - |

---

## ⚠️ Edge Cases Handled

- **NULL pointers:** Functions handle NULL input gracefully
- **Empty trees:** Operations on empty trees return appropriate values
- **Single node trees:** Functions work correctly with single nodes
- **Invalid operations:** Appropriate return values for invalid operations


## 🌳 Tree Types Supported

| Tree Type | Definition |
|----------|------------|
| Binary Tree | Each node has at most 2 children |
| Full Binary Tree | Every node has 0 or 2 children |
| Perfect Binary Tree | All levels are completely filled |
| Complete Binary Tree | All levels except possibly the last are filled |




## 🧩 Data Structure

```c
typedef struct binary_tree_s
{
  int n;
  struct binary_tree_s *parent;
  struct binary_tree_s *left;
  struct binary_tree_s *right;
} binary_tree_t;

```
## 👩‍💻 Authors
- Munirah Enad
- Hamsa Alammar
