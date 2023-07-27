/*
in a connected G, if degree ofevery vertex is even then there is eulerian cycle...

eulerian path...start and endvertices can have odd degrees, all other vertices need to have
even degrees

if number or vertices with odd degree are 0, then there would be eulerian cycle...
if there are 2 vertices with odd degree then there must be a eulerian path..

if # of vertices in graph having odd degree is grater than 2, then there is neither eulerian path
nor eulerian cycle..


*/

bool check_if_eulerian_cycle_exists(int n, vector<vector<int>> &edges)
{
    // for eulerian cycle to exist, all vertices in a graph must have even degree.
    // We just need to get the degree of each vertices and check if it is even.

    vector<int> degree(n);
    for (int i = 0; i < edges.size(); i++)
    {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            return false;
        }
    }

    return true;
}

bool check_if_eulerian_path_exists(int n, vector<vector<int>> &edges)
{
    vector<int> degree(n);
    for (int i = 0; i < edges.size(); i++)
    {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    int vertices_with_odd_degree = 0;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            vertices_with_odd_degree++;
        }
    }

    if (vertices_with_odd_degree == 0 || vertices_with_odd_degree == 2)
    {
        return true;
    }
    return false;
}
