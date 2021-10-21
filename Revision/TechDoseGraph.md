# Tech Dose Graph Playlist

## DFS - Depth First Search
## BFS - Breadth First Search

## Detect A Cycle - Directed Graph

Create a Boolean Array to keep track of Visited Nodes, start from the Any Node mark it as Visited = true, push all the adjascent nodes and call the recursive or iteration on these Nodes, come back to the node set visited Array as False again, if you find any previously Visited Node that would mean that a cycle is present in the Graph.

## Detect A Cycle - Un Directed Graph

Using Graph Coloring : We will use 3 colors, Not Visited = 0, Processing = 1, Visited = 2.

Initially all Nodes are set to 0. Start from any Node increment by 1 if their current values are 0 or 1, then recursively Call all it's Neighbours, if the Recursion stack Exhausts decrement the changes while going back, now move to the next nodes, at any point if the Color of the Graph is 2 then it would mean that a cycle is present in the Graph.

O (V + E)

## Possible Bipartition

Bipartite Graph - A Graph whose vertices can be divided into 2 Disjoint and Independent Sets U and V such that every Node in U connects to a Vertex in V.

A Bipartite Graph can only have Even Edge Length Cycle.

Graph Coloring : There will be 3 Colors, 0 = No Colors, 1 = Red, 2 = Blue. Start from any Node set it to any Color(1/2). Then Move to it's Adjascent Nodes, set them with the Complement Color and Continue. At any point if the Node is already of a color other than the required color then the Graph is not Bipartite.

Use DFS, and use 1 - CurrColor for finding the Color of Adjascent Nodes.

## Course Schedule

Similar To Cycle Detection, Using Graph Coloring

O (V + E)

Declare a 2 D array of Visited all set to 0

0 - Not Visited
1 - Processed
2 - Processing

When you visit a Node set it from 0 to 2, recursively call all of it's Neighbours if the Recursion Exhausts go back and set the Node's value to 1. At any point if we were to come across a Processing Node, it would mean that there was a Cycle otherwise No Cycle.

