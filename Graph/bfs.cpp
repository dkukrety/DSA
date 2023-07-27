

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
            // cout << j << " ";
        }
        // cout << endl;
    }
    return adjList;
}

void bfs_traversal_helper(int start, vector<int> &result, vector<bool> &visited, vector<vector<int>> adjList)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    result.push_back(start);
    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        for (int vertex : adjList[fr])
        {
            if (!visited[vertex])
            {
                result.push_back(vertex);
                q.push(vertex);
                // cout<<adjList[fr][count-1]<<endl;
                visited[vertex] = true;
            }
        }
    }
    return;
}

vector<int> bfs_traversal(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList = convert_edge_list_to_adjacency_list(n, edges);

    vector<bool> visited(n, false);
    vector<int> result;

    // Following loop is there if graph has diconnected components
    // we can use same logic for detecting islands also

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            bfs_traversal_helper(i, result, visited, adjList);
    }
    return result;
}
