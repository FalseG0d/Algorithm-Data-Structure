# Huffmann Code

1. A lossless data compression algorithm
2. We assign variable length code to characters, depending on their frequency

## Pseudo Code To Build the Huffmann Tree

1. Create a leaf node for each unique character and build a min heap of all leaf nodes
2. Extract 2 nodes with min frequency from the Heap
3. Create a new internal node with frequency equal to the sum of the previous 2(first extracted node as Left Child and the other as Right Child)
4. Repeat step#2 and step#3 until the heap contains only one node. The remaining node is the Root Node and the tree is complete

Uses: Min Heap 