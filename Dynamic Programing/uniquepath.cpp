/*Given a grid of size n x m and a robot initially staying at the
top-left position, return the number of unique paths for the robot to reach the bottom-right corner of the grid. The robot is allowed to move either down or right at any point in time.

Example One
{
"n": 3,
"m": 2
}
Output:

3
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:

Right -> Down -> Down
Down -> Down -> Right
Down -> Right -> Down
Example Two
{
    "n" : 4,
        "m" : 1
}
*/
// This solution is not correct...

int unique_paths(int n, int m)
{
    // Write your code here.
    unsigned long big = 1000000007;
    vector<vector<unsigned long>> table(n, vector<unsigned long>(m, 0));

    for (int i = 0; i < n; i++)
    {
        table[i][0] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        table[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }

    return table[n - 1][m - 1] % big;
}

// This is correct

/*
Asymptotic complexity in terms of the size of the grid `n` * `m`:
* Time: O(n * m).
* Auxiliary space: O(n * m).
* Total space: O(n * m).
*/

int unique_paths(int n, int m)
{
    // dp[i][j] denotes the number of unique paths from [1, 1] to the [i, j]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    const int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                dp[i][j] = 1;
            }
            else if (i == 1)
            {
                dp[i][j] += dp[i][j - 1];
            }
            else if (j == 1)
            {
                dp[i][j] += dp[i - 1][j];
            }
            else
            {
                dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
            }
            dp[i][j] %= mod;
        }
    }
    return dp[n][m];
}