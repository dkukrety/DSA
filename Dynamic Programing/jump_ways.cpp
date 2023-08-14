/*

Jump Ways
There is a one-dimensional axis. In one turn, you can take a jump of length 1 or 2. Find the total number of distinct ways using which you can reach from 0th coordinate to n-th coordinate?

Example One
{
"n": 3
}
Output:

3
There are 3 distinct ways in which you can move from 0 to 3.

1 length jump + 1 length jump + 1 length jump.
1 length jump + 2 length jump.
2 length jump + 1 length jump.

*/
long long jump_ways(int n)
{
    // Write your code here.
    vector<long long> memo(n + 1, -1);

    memo[0] = 1;
    memo[1] = 1;

    if (memo[n] != -1)
        return memo[n];

    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}
