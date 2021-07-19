# Prims Algorithm

Prims Algorithm is used for finding out the Minimum Spanning Tree in Weighted Undirected Graph.

Spanning Tree       = A collection of edges of a graph connecting all the Vertices using min number of Edges.
Min Spanning Tree   = A spanning Tree such that the sum of weights of each of the edge is Min.

**Algorithm**

1. Create an empty Tree, add any vertex to it.
2. Add the vertex to our tree which is connected by the Least weighted Edge such that their are no Loops until all the Vertices are in the Tree.

**Pseudo-Code**

1. Create an Array parent[] of size V and initialize it with NULL.
2. Create a Min Heap(Or Priority Queue) of size V. Let the min Heap be H.
3. Insert all Vertices into H such that key values of starting vertex is 0 and Key Values of other vertices is infinite.
4. While H is Not Empty do:
    1. u=extractMin(H) # u will be the new distance between the Starting Vertex and Current Vertex
    2. For every adjascent v of u do:
        1. if v is in H do:
            1. Update Key Values of v in H if weight of dge u-v is smaller than current key value of v.
            2. parent[v]=u.

**Time Complexity**

O((V+E)*log(V))

**Applications**

1. Telephone Lines
2. Electrical Lines
3. Hydraulic Lines
4. Computer Networks
5. Road Networks

**6. Approximation Problems**
    1. Travelling Salesman Problem(TSP)
    2. Steiner Tree: Given a graph and a subset of vertices in that graph a steiner tree is one that spans through the given subset of vertices. Steiner Tree may use some vertices which are not in the Subset but are used to connect the others, these(Connecting) are Steiner Vertices while the rest are called Terminal Vertices.
    3. Max Bottleneck Paths