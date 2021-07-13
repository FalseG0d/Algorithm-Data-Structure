# Prims Algorithm

Prims Algorithm is used for finding out the Minimum Spanning Tree in Tree.

**Pseudo-Code**

1. Create an Array parent[] of size V and initialize it with NULL.
2. Create a Min Heap(Or Priority Queue) of size V. Let the min Heap be H.
3. Insert all Vertices into H such that key values of starting vertex is 0 and Key Values of other vertices is infinite.
4. While H is Not Empty do:
    1. u=extractMin(H)
    2. For every adjascent v of u do:
        1. if v is in H do:
            1. Update Key Values of v in H if weight of dge u-v is smaller than current key value of v.
            2. parent[v]=u.

