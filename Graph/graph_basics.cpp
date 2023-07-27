
/*
This will convert edges list into a sorted adjancy list

Convert the given edge list to the adjacency list of an undirected connected graph.
An adjacency list represents a graph as a list of lists. The list index represents a vertex, and each element in its inner list represents the other vertices that form an edge with the vertex.

Example
{
"n": 5,
"edges": [
[0, 1],
[1, 4],
[1, 2],
[1, 3],
[3, 4]
]
}

we can represent adjancy list as
1. vector<vector<int>> v(n);
2. vector<int> adj[n];
3. list<int> adj[n];

*/
vector<vector<int>> convert_edge_list_to_adjacency_list(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adjList(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        // adjList[i].push_back(edges[i][1]);
    }

    for (int i = 0; i < n; i++)
    {
        sort(adjList[i].begin(), adjList[i].end());
    }

    for (auto i : adjList)
    {
        // sort(i.begin(),i.end());
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return adjList;
}

// converting to adjacent matrix...

vector<vector<bool>> convert_edge_list_to_adjacency_matrix(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<bool>> adjacency_matrix(n, vector<bool>(n, false));

    for (int i = 0; i < edges.size(); i++)
    {
        adjacency_matrix[edges[i][0]][edges[i][1]] = true;
        adjacency_matrix[edges[i][1]][edges[i][0]] = true;
    }

    return adjacency_matrix;
}