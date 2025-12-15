# BINARY TREES PROJECT
# ====================

# DESCRIPTION
# ------------
# Binary trees are hierarchical data structures where each node has at most 
# two children (left and right). They serve as fundamental building blocks 
# for advanced algorithms and have real-world applications in databases, 
# AI systems, compilers, and file systems.

# LEARNING OBJECTIVES
# -------------------
# - Understand binary trees and their basic properties
# - Differentiate between binary trees and Binary Search Trees (BST)
# - Analyze time complexity advantages over linked lists
# - Calculate depth, height, and size of binary trees
# - Master tree traversal methods (pre-order, in-order, post-order)
# - Identify tree types: complete, full, perfect, and balanced

# REQUIREMENTS
# ------------
# - OS: Ubuntu 20.04 LTS
# - Compiler: gcc with flags: -Wall -Werror -Wextra -pedantic -std=gnu89
# - Style: Betty coding style compliance
# - Restrictions: No global variables, max 5 functions per file
# - Header: All prototypes in binary_trees.h with include guards
# - Files: All files must end with new line

# FILE STRUCTURE
# --------------
# binary_trees.h      # Header file with prototypes
# 0-binary_tree_node.c      # Create binary tree node
# 1-binary_tree_insert_left.c  # Insert as left-child
# 2-binary_tree_insert_right.c # Insert as right-child
# 3-binary_tree_delete.c       # Delete entire tree
# 4-binary_tree_is_leaf.c      # Check if node is leaf
# 5-binary_tree_is_root.c      # Check if node is root
# 6-binary_tree_preorder.c     # Pre-order traversal
# 7-binary_tree_inorder.c      # In-order traversal
# 8-binary_tree_postorder.c    # Post-order traversal
# 9-binary_tree_height.c       # Measure tree height
# 10-binary_tree_depth.c       # Measure node depth
# 11-binary_tree_size.c        # Measure tree size
# 12-binary_tree_leaves.c      # Count leaves
# 13-binary_tree_nodes.c       # Count nodes with children
# 14-binary_tree_balance.c     # Calculate balance factor
# 15-binary_tree_is_full.c     # Check if tree is full
# 16-binary_tree_is_perfect.c  # Check if tree is perfect
# 17-binary_tree_sibling.c     # Find node's sibling
# 18-binary_tree_uncle.c       # Find node's uncle
# README.md            # This documentation file

# TASKS IMPLEMENTATION
# --------------------
# Task 0: binary_tree_node()      - Create new node
# Task 1: binary_tree_insert_left() - Insert left child
# Task 2: binary_tree_insert_right() - Insert right child
# Task 3: binary_tree_delete()    - Delete entire tree
# Task 4: binary_tree_is_leaf()   - Check if node is leaf
# Task 5: binary_tree_is_root()   - Check if node is root
# Task 6: binary_tree_preorder()  - Pre-order traversal
# Task 7: binary_tree_inorder()   - In-order traversal
# Task 8: binary_tree_postorder() - Post-order traversal
# Task 9: binary_tree_height()    - Measure tree height
# Task 10: binary_tree_depth()    - Measure node depth
# Task 11: binary_tree_size()     - Measure tree size
# Task 12: binary_tree_leaves()   - Count leaves
# Task 13: binary_tree_nodes()    - Count nodes with children
# Task 14: binary_tree_balance()  - Calculate balance factor
# Task 15: binary_tree_is_full()  - Check if tree is full
# Task 16: binary_tree_is_perfect() - Check if tree is perfect
# Task 17: binary_tree_sibling()  - Find sibling
# Task 18: binary_tree_uncle()    - Find uncle

# COMPILATION
# -----------
# gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o binary_trees
# ./binary_trees

# TREE TYPES
# ----------
# Binary Tree:        Each node has ≤2 children
# Full Binary Tree:   Every node has 0 or 2 children
# Perfect Binary Tree: All levels completely filled
# Complete Binary Tree: All levels except possibly last filled

# EDGE CASES HANDLED
# ------------------
# ✓ NULL pointer inputs
# ✓ Empty trees
# ✓ Single node trees
# ✓ Invalid operations

# KEY CONCEPTS
# ------------
# - Time Complexity: O(log n) vs O(n) in linked lists
# - Traversal Methods: Pre-order, In-order, Post-order
# - Tree Properties: Various structural classifications
# - Memory Efficiency: Hierarchical organization

# AUTHORS
# -------
# Munirah Alotaibi
# Hamsa Alamar
# 
# Holberton School Project - Data Structures & Algorithms# BINARY TREES PROJECT
# ====================

# DESCRIPTION
# ------------
# Binary trees are hierarchical data structures where each node has at most 
# two children (left and right). They serve as fundamental building blocks 
# for advanced algorithms and have real-world applications in databases, 
# AI systems, compilers, and file systems.

# LEARNING OBJECTIVES
# -------------------
# - Understand binary trees and their basic properties
# - Differentiate between binary trees and Binary Search Trees (BST)
# - Analyze time complexity advantages over linked lists
# - Calculate depth, height, and size of binary trees
# - Master tree traversal methods (pre-order, in-order, post-order)
# - Identify tree types: complete, full, perfect, and balanced

# REQUIREMENTS
# ------------
# - OS: Ubuntu 20.04 LTS
# - Compiler: gcc with flags: -Wall -Werror -Wextra -pedantic -std=gnu89
# - Style: Betty coding style compliance
# - Restrictions: No global variables, max 5 functions per file
# - Header: All prototypes in binary_trees.h with include guards
# - Files: All files must end with new line

# FILE STRUCTURE
# --------------
# binary_trees.h      # Header file with prototypes
# 0-binary_tree_node.c      # Create binary tree node
# 1-binary_tree_insert_left.c  # Insert as left-child
# 2-binary_tree_insert_right.c # Insert as right-child
# 3-binary_tree_delete.c       # Delete entire tree
# 4-binary_tree_is_leaf.c      # Check if node is leaf
# 5-binary_tree_is_root.c      # Check if node is root
# 6-binary_tree_preorder.c     # Pre-order traversal
# 7-binary_tree_inorder.c      # In-order traversal
# 8-binary_tree_postorder.c    # Post-order traversal
# 9-binary_tree_height.c       # Measure tree height
# 10-binary_tree_depth.c       # Measure node depth
# 11-binary_tree_size.c        # Measure tree size
# 12-binary_tree_leaves.c      # Count leaves
# 13-binary_tree_nodes.c       # Count nodes with children
# 14-binary_tree_balance.c     # Calculate balance factor
# 15-binary_tree_is_full.c     # Check if tree is full
# 16-binary_tree_is_perfect.c  # Check if tree is perfect
# 17-binary_tree_sibling.c     # Find node's sibling
# 18-binary_tree_uncle.c       # Find node's uncle
# README.md            # This documentation file

# TASKS IMPLEMENTATION
# --------------------
# Task 0: binary_tree_node()      - Create new node
# Task 1: binary_tree_insert_left() - Insert left child
# Task 2: binary_tree_insert_right() - Insert right child
# Task 3: binary_tree_delete()    - Delete entire tree
# Task 4: binary_tree_is_leaf()   - Check if node is leaf
# Task 5: binary_tree_is_root()   - Check if node is root
# Task 6: binary_tree_preorder()  - Pre-order traversal
# Task 7: binary_tree_inorder()   - In-order traversal
# Task 8: binary_tree_postorder() - Post-order traversal
# Task 9: binary_tree_height()    - Measure tree height
# Task 10: binary_tree_depth()    - Measure node depth
# Task 11: binary_tree_size()     - Measure tree size
# Task 12: binary_tree_leaves()   - Count leaves
# Task 13: binary_tree_nodes()    - Count nodes with children
# Task 14: binary_tree_balance()  - Calculate balance factor
# Task 15: binary_tree_is_full()  - Check if tree is full
# Task 16: binary_tree_is_perfect() - Check if tree is perfect
# Task 17: binary_tree_sibling()  - Find sibling
# Task 18: binary_tree_uncle()    - Find uncle

# COMPILATION
# -----------
# gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o binary_trees
# ./binary_trees

# TREE TYPES
# ----------
# Binary Tree:        Each node has ≤2 children
# Full Binary Tree:   Every node has 0 or 2 children
# Perfect Binary Tree: All levels completely filled
# Complete Binary Tree: All levels except possibly last filled

# EDGE CASES HANDLED
# ------------------
# ✓ NULL pointer inputs
# ✓ Empty trees
# ✓ Single node trees
# ✓ Invalid operations

# KEY CONCEPTS
# ------------
# - Time Complexity: O(log n) vs O(n) in linked lists
# - Traversal Methods: Pre-order, In-order, Post-order
# - Tree Properties: Various structural classifications
# - Memory Efficiency: Hierarchical organization

# AUTHORS
# -------
# Munirah Alotaibi
# Hamsa Alammar
# 
# Holberton School Project - Data Structures & Algorithms
