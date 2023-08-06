/*

shortest path with equal weight --> BFS
shortest path with different weight --> djecktra's
negative weight --> bellman ford
multiple source/multiple destination --> Flyod marshall..

representation:
1. adjlist
2. adjmatrix
3. BFS/DFS thoroghly known...
4. Distance based alogorithms
   --> Dijiktra
   --> Bellman ford
   --> Floyd warshall

5. Union/Find algorith
6. Cycle detection (directed/undirected) usign BFS and DFS...
7. Topological sorting --> BFS on directed graph.



Akshat Gupta  to  Everyone 20:57
Graphs

Representation :

1. Adj List -> BFS, DFS
2. Adj Matrix -> BFS, DFS

Distance Based Algo's :

* BFS (Edge weight has to be the same)
1. Dijikstra's
2. Bellman Ford
3. Floyd Warshall


Union/Find ->

Cycle Detections

1. Undirected
 -> BFS & DFS
2. Directed
 -> BFS, DFS

Topological Sorting -> BFS on Directed.
DAG -> N-ary tree.

Connected Components.

[
    1 0 0 1
    0 1 1 1
    0 1 0 1
]

[
    1: 2,3
    2: 3
    3: -
    4: 5,6
]

Kosaraju's Algorithm -> Strongly connnected component
*/