#include <iostream>
#include <vector>

using namespace std;
/*
Climb staircase problem.

1 step , 2 step....n steps


Top down approach

f(n) --> 1-way + f(n-1)ways + f(n-2)ways

f(1) = 1way
f(2) = 1+f(1)+f(0) = 3 ways
f(0) = 1 way.


Bottom up approach...

f(0) is 1 way or 0 way? i think its 0.
f(1) is 1 way only
f(2) is 1+ f(1) +f(0) --> so its 2
and so on
for(i = 2;i<=n;i++)
{
    f[i] = 1+f[i-1]+f[i-2];
}

*/

class Solution
{
public:
    int climbStairs(int n)
    {
        cout << "n=" << n << endl;
        static vector<int> memo(n + 2, -1);
        if (memo[n] != -1)
            return memo[n];

        if (n == 0 || n == 1)
        {
            memo[n] = 1;
            return memo[n];
        }
        cout << "memo " << n << " value " << memo[n] << endl;
        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        cout << "memo " << n << " value " << memo[n] << endl;

        return memo[n];
    }
};

int main()
{
    Solution obj;
    cout << "And answer is ===> " << obj.climbStairs(4);
    return 0;
}