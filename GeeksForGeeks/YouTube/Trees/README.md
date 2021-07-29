# Tree

## Tree Traversal
Reading/Processing the data of a node exactly once in some order in a tree.

### Type

1. BFS: Also called Level Order Traversal, traverse the nodes in layers.
2. DFS:
    1. Preorder Traversal
    2. Inorder Traversal
    3. Postorder Traversal

**Time Complexity**: O(N)

## AVL Trees

AVL trees are self ballancing Binary Search Trees(BST). The diff between the heights of the left and right subtrees cannot be more than one for all nodes.

Height: O(Log(N)) where N is the number of Nodes.

For Insertion into the AVL tree one must perform the standard insertion of the Node and then reballance the BST be Left-Right Rotation.

There are 4 Possible cases:

1. Left Left Case
2. Left Right Case
3. Right Right Case
4. Right Left Case