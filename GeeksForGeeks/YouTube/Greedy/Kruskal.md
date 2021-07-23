# Kruskal Algorithm-Minimum Spanning Tree

Spanning Tree: Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and is connected to all the vertices together.

Minimum Spanning Tree: The spanning tree of the graph whose sum of all edge cost is minimum.

## Steps

1. Sort all the edges in a non-decreasing order of weights.
2. Pick the smallest edge. Check if it forms a cycle with the Spanning Tree. If the cycle is not formed, include the edge into the graph. Discard the edge.
3. Repeat the Step 2 until |V-1| edges are in the spanning tree.