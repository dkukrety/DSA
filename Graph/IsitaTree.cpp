
bool bfs_traversal_helper(int start, vector<bool> &visited, vector<int> &parent, vector<vector<int>> adjList)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        for (int vertex : adjList[fr])
        {
            if (!visited[vertex])
            {
                q.push(vertex);
                // cout<<adjList[fr][count-1]<<endl;
                visited[vertex] = true;
                parent[vertex] = fr;
            }
            else
            {
                if (parent[fr] != vertex)
                    return false;
            }
        }
    }
    return true;
}

bool is_it_a_tree(int node_count, vector<int> &edge_start, vector<int> &edge_end)
{
    // Write your code here.

    // Lets first create a adjuncy List

    vector<vector<int>> adjList(node_count);
    for (int i = 0; i < edge_start.size(); i++)
    {
        int a = edge_start[i];
        int b = edge_end[i];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<bool> visited(node_count, false);
    int result = 0;
    vector<int> parent(node_count, -1);

    // Following loop is there if graph has diconnected components
    // we can use same logic for detecting islands also

    for (int i = 0; i < node_count; i++)
    {
        if (!visited[i])
        {
            result++;
            if (!bfs_traversal_helper(i, visited, parent, adjList))
                return 0;
            if (result > 1)
                return 0;
        }
    }
    return (result == 1) ? 1 : 0;
}
