# GRAPHS Introduction

Graphs represents a pair-wise relationship between a set of objects. They contains:
    1. Vertex
    2. Edges

There are two types of Graphs:
    1. Directed:    Relation holds in one Direction
    2. Un-Directed: Relation holds in both Directions

## Applications

1. Social Networks
2. City-Road Map
3. Precendence Contraints

## Representation

1. **Adjacency Matrix**:    A 2-D matrix of VxV size containing only 0s and 1s, where V represents the Number of Vertex.

|Pros|Cons|
|:---|:---|
|Easy to implement|Consumes more space O(V^2)|
|O(1) time to remove and edge|Adding a vertex costs O(V^2) time|
|Efficient Queries||

2. **Adjacency List**:      An array of LL is used. Size of the array is equal to the number of vertices and each entry of array corresponds to a linked list of vertices adjacent to the index.

|Pros|Cons|
|:---|:---|
|Saves space, O(V+E), worst case O(V^2)|In-efficient queries|
|Adding a Vertex is simple||
