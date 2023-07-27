
// All 8 directions. Consider as pair: {add_r[i], add_r[i]}.
const int add_r[4] = {0, -1, 0, 1};
const int add_c[4] = {-1, 0, 1, 0};

void bfs(int row, int column, vector<vector<int>> &matrix, int &islands)
{
    queue<pair<int, int>> q;
    q.push({row, column});
    matrix[row][column] = 0;
    islands = 1;

    while (q.empty() == false)
    {
        pair<int, int> head = q.front();
        q.pop();
        int current_row = head.first;
        int current_column = head.second;

        for (int i = 0; i < 4; i++)
        {
            // Try to visit all 4 neighbours.
            int new_row = current_row + add_r[i];
            int new_column = current_column + add_c[i];

            // Out of the matrix.
            if (new_row < 0 || new_row >= matrix.size() || new_column < 0 || new_column >= matrix[0].size())
            {
                continue;
            }

            if (matrix[new_row][new_column])
            {
                /*
                We could have marked as 0 when we pop-up the element from the queue and not here.
                This will also give correct answer, but that is not the correct way! If we do
                that, same element will be pushed multiple times in the queue (that will increase
                running time and queue size unnecessarily)! Take some examples and try to figure
                it out.
                */
                matrix[new_row][new_column] = 0;
                q.push({new_row, new_column});
                islands++;
            }
        }
    }
}

int max_island_size(vector<vector<int>> &grid)
{
    int islands = 0;
    int maxIs = 0;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // When we find unvisited node, visit it and visit all the reachable nodes.
            if (grid[i][j])
            {

                bfs(i, j, grid, islands);
                maxIs = max(maxIs, islands);
            }
        }
    }
    return maxIs;
}
