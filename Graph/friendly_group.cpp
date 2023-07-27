
bool bfs_traversal_helper(int start, vector<int> &color, vector<int> &parent, vector<vector<int>> &adjList)
{
    queue<int> q;
    q.push(start);
    color[start] = 1;
    parent[start] = -1;

    cout << "setting vertex --> " << start << " to color  " << color[start] << endl;

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        for (int vertex : adjList[fr])
        {
            if (color[vertex] == 0)
            {
                q.push(vertex);
                // cout<<adjList[fr][count-1]<<endl;
                color[vertex] = (color[fr] == 1) ? 2 : 1;
                parent[vertex] = fr;
                cout << "setting vertex --> " << vertex << " to color  " << color[vertex] << endl;
            }
            else
            {
                // if (parent[fr] != vertex)
                //   return false;
                if (color[vertex] == color[fr])
                {
                    cout << "vertex color " << color[vertex] << " parent color " << color[fr] << endl;
                    return false;
                }
            }
        }
    }
    return true;
}

bool can_be_divided(int num_of_people, vector<int> &dislike1, vector<int> &dislike2)
{
    // Write your code here.
    if (dislike1.size() == 0 || dislike2.size() == 0)
        return 1;

    vector<vector<int>> adjList(num_of_people);
    for (int i = 0; i < dislike1.size(); i++)
    {
        int a = dislike1[i];
        int b = dislike2[i];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // now we will 2 coloring method to detect if graph can
    // be divided into two parts.

    // 0 means no color, also it means not visited.
    // 1 means read
    // 2 means blue

    vector<int> color(num_of_people, 0);
    vector<int> parent(num_of_people, -1);
    int result = 0;

    // cout<<"printing list sizes  " <<adjList[1].size();

    for (int i = 0; i < num_of_people; i++)
    {
        // Need to make sure if there any vertices on index i
        //  and if that is not colored

        if (adjList[i].size() != 0 && color[i] == 0)
        {
            cout << "result =" << result << " color of vertex --> " << i << "  " << color[i] << endl;
            if (!bfs_traversal_helper(i, color, parent, adjList))
                return 0;

            if (result > 1)
                return 0;

            result++;
        }
    }

    return 1;
}
