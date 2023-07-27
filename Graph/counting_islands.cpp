
vector<pair<int, int>> getNeighbours(pair<int, int> p, vector<vector<int>> &matrix, int rowLen, int colLen)
{
    vector<pair<int, int>> result;

    if (p.second + 1 < colLen && matrix[p.first][p.second + 1] == 1)
    {
        result.push_back(make_pair(p.first, p.second + 1));
    }
    if (p.second - 1 >= 0 && matrix[p.first][p.second - 1] == 1)
    {
        result.push_back(make_pair(p.first, p.second - 1));
    }

    if (p.first + 1 < rowLen && matrix[p.first + 1][p.second] == 1)
    {
        result.push_back(make_pair(p.first + 1, p.second));
    }
    if (p.first - 1 >= 0 && matrix[p.first - 1][p.second] == 1)
    {
        result.push_back(make_pair(p.first - 1, p.second));
    }

    if (p.first - 1 >= 0 && p.second - 1 >= 0 && matrix[p.first - 1][p.second - 1] == 1)
    {
        result.push_back(make_pair(p.first - 1, p.second - 1));
    }

    if (p.first + 1 < rowLen && p.second + 1 < colLen && matrix[p.first + 1][p.second + 1] == 1)
    {
        result.push_back(make_pair(p.first + 1, p.second + 1));
    }

    if (p.first + 1 < rowLen && p.second - 1 >= 0 && matrix[p.first + 1][p.second - 1] == 1)
    {
        result.push_back(make_pair(p.first + 1, p.second - 1));
    }

    if (p.first - 1 >= 0 && p.second + 1 < colLen && matrix[p.first - 1][p.second + 1] == 1)
    {
        result.push_back(make_pair(p.first - 1, p.second + 1));
    }

    return result;
}

void bfs(int i, int j, vector<vector<int>> &matrix, int rowLen, int colLen)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    matrix[i][j] = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (auto pr : getNeighbours(p, matrix, rowLen, colLen))
        {
            q.push(pr);
            matrix[pr.first][pr.second] = 0;
            // cout<<"setting 0 --> "<<pr.first<< "  "<<pr.second<<endl;
        }
    }
}

int count_islands(vector<vector<int>> &matrix)
{
    // Write your code here.
    int count = 0;
    if (matrix.empty())
        return count;

    int rowLen = matrix.size();
    int colLen = matrix[0].size();

    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 0; j < colLen; j++)
        {
            cout << matrix[i][j] << "  ";
            if (matrix[i][j] == 1)
            {
                bfs(i, j, matrix, rowLen, colLen);
                count++;
            }
        }
        cout << endl;
    }
    return count;
}



/*
Asymptotic complexity in terms of `n` and `m` dimensions of the input matrix:
* Time: O(n * m).
* Auxiliary space: O(max(n, m)).
* Total space: O(n * m).
*/

// All 8 directions. Consider as pair: {add_r[i], add_r[i]}.
const int add_r[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int add_c[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void bfs(int row, int column, vector<vector<int>> &matrix) {
    queue<pair<int, int>> q;
    q.push({row, column});
    matrix[row][column] = 0;

    while (q.empty() == false) {
        pair<int, int> head = q.front();
        q.pop();
        int current_row = head.first;
        int current_column = head.second;

        for (int i = 0; i < 8; i++) {
            // Try to visit all 8 neighbours.
            int new_row = current_row + add_r[i];
            int new_column = current_column + add_c[i];

            // Out of the matrix.
            if (new_row < 0 || new_row >= matrix.size() || new_column < 0 || new_column >= matrix[0].size()) {
                continue;
            }

            if (matrix[new_row][new_column]) {
                /*
                We could have marked as 0 when we pop-up the element from the queue and not here.
                This will also give correct answer, but that is not the correct way! If we do
                that, same element will be pushed multiple times in the queue (that will increase
                running time and queue size unnecessarily)! Take some examples and try to figure
                it out.
                */
                matrix[new_row][new_column] = 0;
                q.push({new_row, new_column});
            }
        }
    }
}

int count_islands(vector<vector<int>> &matrix) {
    int islands = 0;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // When we find unvisited node, visit it and visit all the reachable nodes.
            if (matrix[i][j]) {
                islands++;
                bfs(i, j, matrix);
            }
        }
    }
    return islands;
}
