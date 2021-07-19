# Dijikstra's Shortest Path Algo

It is used to find the shortest path between any vertex in the Tree with any other Vertex.

**Pseudo-Code**

1. S=NULL
2. Q=V[G]
3. while Q!=NULL
    1. u=extractMin(Q)
    2. S=S U {u}
    3. For each v of Adj[u] & Not in Q
        1. if d[v]>d[u]+w
            d[v]=d[u]+w
            parent[v]=u
