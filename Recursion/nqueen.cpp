/*

Asymptotic complexity in terms of the number of queens `n`:
* Time: Exponential, i.e. O(C^n) where C is a constant.
* Auxiliary space: Exponential.
* Total space: Exponential.

const char queen = 'q';
const char no_queen = '-';

/*
Checking if we can place a queen at position [row][col]
without attacking other queens already on the board.
We place queens from top (0-th row) down, so we only
check for existing queens above the current one.
*/
bool is_safe(vector<string> &candidate, int row, int col, int n)
{
    // Check the "backslash" diagonal.
    int cur_row = row, cur_col = col;
    while (cur_row >= 0 && cur_col >= 0)
    {
        if (candidate[cur_row--][cur_col--] == queen)
        {
            return false;
        }
    }
    // Check column.
    cur_row = row;
    while (cur_row >= 0)
    {
        if (candidate[cur_row--][col] == queen)
        {
            return false;
        }
    }
    // Check the "slash" diagonal.
    cur_row = row, cur_col = col;
    while (cur_row >= 0 && cur_col < n)
    {
        if (candidate[cur_row--][cur_col++] == queen)
        {
            return false;
        }
    }
    return true;
}

// The recursive function.
void find_all_arrangements_util(vector<vector<string>> &solutions,
                                vector<string> &candidate, int n, int row)
{
    // If all n queens are placed (is_safe() returned true for each queen),
    // this is one of the solutions.
    if (row == n)
    {
        // push_back() makes a (deep) copy; that is what we need.
        solutions.push_back(candidate);
        return;
    }
    // Try to place a queen in every column of current row:
    for (int col = 0; col < n; col++)
    {
        if (is_safe(candidate, row, col, n))
        {
            // Place a queen at (row, col).
            candidate[row][col] = queen;
            // Try to place any more queens (from the next row down).
            find_all_arrangements_util(solutions, candidate, n, row + 1);
            // We have explored all the solutions with current value of "candidate";
            // now we need to reset it in order to try the next candidate:
            candidate[row][col] = no_queen;
        }
    }
}

vector<vector<string>> find_all_arrangements(int n)
{
    vector<vector<string>> solutions;
    string chessboard_empty_row(n, no_queen);          // zero queens in a row.
    vector<string> candidate(n, chessboard_empty_row); // zero queens on a board.
    // Start with an empty board from the 0th row:
    find_all_arrangements_util(solutions, candidate, n, 0);
    return solutions;
}

* /