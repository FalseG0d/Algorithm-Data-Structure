# Differences Between Concepts

1. Dijikstra vs Bellman Ford Algo

For Calculating the Shortest Path

|Dijikstra Algo|Bellman Ford Algo|
|:---|:---|
|Doesn't work for Negative Weights|Works for Negative Weights|
|V x V|E x V|
|Greedy Approach|Dynamic Programming|

2. Abstract Class vs Interfaces

|Abstract Class|Interface|
|:---|:---|
|Can have both abstract and non-abstract methods|Can only have abstract methods|
|Doesn't support multiple inheritence|Supports multiple inheritence|
|Can have final, non-final, static and non-static variables|Only static and final variables|
|Can provide implementation of inheritence|Can't provide implementation of abstract class|
|Uses abstract keyword|Uses interface keyword|
|Inheritence uses extends|Inheritence uses implements|

3. Prim's vs Kruskal Algo

Spanning Tree : Sub Graph of Graph(Edges), such that there are All Vertices(N) and (N-1) Edges, connecting all the Vertices.

```
Number Of Possible ST : |E| C |V|-1 - |Cycles Present|
```

Min Spanning Tree : For Weighted Graph, a Spanning Tree such that the total Weight is Minimum.

Both are Greedy

|Prim's Algorithm|Kruskal's Algorithm|
|:---|:---|
|Starts from Min Vertex|Starts from the Vertex carrying the Min weight|
|O(V^2)|O(E Log V)|
|Works for only Connected graph|Can Work for disconnected graphs|
|Faster in Dense graph|Faster in Sparse Graph|

4. BFS vs DFS

Graph Traversal Techniques

|BFS|DFS|
|:---|:---|
|Visit the Nodes closest root First|Visit the Nodes farther from root First|
|Uses Queue|Uses Stack|
|O(V+E)|O(V+E)|
|Optimal/Shortest Path|Not Optimal Solution|

5. Comparable vs Comparator: Java provides two interfaces to sort the data members of the class.

|Comparables|Comparator|
|:---|:---|
|Capable of comparing itself with another object|Comparator is external to the element type we are comparing, it has a second sort function|
|Class must implement java.lang.Comparable||
|We override the method compareTo()||

6. (equals) vs (==)

|equals()|==|
|:---|:---|
|Method of Object Class|A Binary Operator|
|Checks Equality of Content|Check/Compares the addresses/references|

7. Topological Order Vs