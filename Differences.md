# Differences Between Concepts

1. Dijikstra vs Prims Algo

|Dijikstra Algo|Prims Algo|
|:---|:---|


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

4. BFS vs DFS

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