what is bipartite graph ? https://www.geeksforgeeks.org/what-is-bipartite-graph/
 1. two coloring method..
 2. even/odd cycle. if graph has odd lenght cycle then its bipartite.

 what is logic to check cycle?
 1. visited and its not a parent. to check the cycle.
 2. number of edges are greater than vertices

BFS helps in finding shortest distance from any node from source.
BFS complexity is V+E 

/*https://leetcode.com/problems/max-area-of-island/

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.


 Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Logic: Use algorithm to find number of graph in graph set....
do dfs in each graph and keep count of max nodes...
so visit matrix[r][c] if not visited do int count <--- bfs(r,c,)
then we can do max(count,maxcount..)

threre is difference between matrix, adjMatrix and adjList...?? think..

*/

/*

Flood fill....

using map<key,frequency> for flood fill...

*/

/*
Create adjList...

//Pre/post/in...



DFS...
0. mark myself as visited
1. Pick any branch
2.

dfs(adjList,startnode,visited)
{
    //create visited array of size n
    vector<int> visited(n,0);
    visited[startnode]=0;
    //recursive implementation...not stack'''
    //pre-order traversal if we are printing node here
    //explore neiboring nodes
    for(niebousts: adjList)
    {
        if(!visited[neibours])
        dfs(adjlist,startnode,visited)

    }

    //post-order traversal if we are printing node here.
}

//iterative method implementation...

dfs(adjList,startnode,visited)
{
    //create visited array of size n
    vector<int> visited(n,0);
    visited[startnode]=0;
    //use stack
    stack<int> st;
    st.push(startnode);
    //explore neiboring nodes
    while(st.empty())
    {
       tp= st.top();
       st.pop()

       for(int i=0;i<adjList[tp].size();i++)
       {
           int nieghbour = adjList[tp][i];

           if(!visited[nieghbour])
           {
              visited[nieghbour] = 1;
              st.push(nieghbour);
           }
       }

    }
}
*/

/*

detecting cycle in directed graph...

using stack and hashmap...to detect the cycle..

what is back-edge??

cycle detecion using dfs...
and also using book keeping...


bool dfs(adjList,hashMap,visited,startnode)
{
    visited[startnode]=true; //node visit
    hashMap[startnode]=true; //tracking ancestors

    for(vertex:adjList)
    {
        if(!visited[vertex]){
            isCycle = dfs(adjList,hashMap,visited,startnode);
            if (isCycle) return true;

        }
        else
        {
            if(hashMap[startnode])
            return true;
        }

    }

    //backtracking step...
    hashMap[startnode] = false;

}

another method of detecting cycle...
book keeping method...

it uses --> arrival ds --> time at which arrive at node
---------> departure ds --> time at which depart from node..

if you arrving at node, from which you never deplarted (ie depart time is not set )
then it is a cycle...

int timestamp = 1;
bool dfs(adjList,arrival.departure,visited,startnode)
*/

/*
https://leetcode.com/problems/course-schedule/description/
course schedule problem...

if graph has cycle , then you will not be able to finish all courses...



*/

/*
topological sorting....

search --> using dfs/bfs...
can we sort graph ?? we have to actually sort the nodes. what if graph is cyclic..
sorting in graph works only for acyclic.

shortest path --> use bfs
============================================================
sorting graph means....sorting the nodes??

it does not work on graph having cycle...

we will focus only on DAG...for sorting purpose.
only DAG are used for sorting...
DAG  --> directed acyclic graph...also known as dependency mapping/graph

topological sorting can only work if input is DAG...
google fav topic...

topological sorting can be done using bfs by inserting node for each level.
its majorly done using DFS...and then reversing the resultant array.

write simple DFS recursive implementation...
then do post-order processing...

topological sorting is post-order travesal using DFS...

also need to make sure that, we have correct starting node for calling DFS..starting node should not come in any adjList of DAG.
for that we will keep track of starting node while creating adjList.

course schedule problem from leet-code, we need to add cycle check.
=====================================================================
Now there will be one case above will not solve.
to solve that we calculate indegress, instead of starting node.
if indegrees is 0 for node then trigger DfS.
1. compute in-degrees and trigger if in-degrees dfs/bfs....
can use stack, in pre/post-order way...
push in pre-order...pop in post-order...

FOR DFS based topological sorting, it has to be DAG....if graph has cycle then DFS cannot be used...

KAHN algorithm..

*/
