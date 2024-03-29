// https: // leetcode.com/problems/combinations/
/*

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.



Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

*/

class Solution
{
public:
    void helper(int n, int k, int start, vector<int> &slate, vector<vector<int>> &result)
    {
        if (k == 0)
        {
            result.push_back(slate);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            slate.push_back(i);
            helper(n, k - 1, i + 1, slate, result);
            slate.pop_back();
        }

        return;
    }
    vector<vector<int>> combine(int n, int k)
    {

        vector<vector<int>> result;
        vector<int> slate;
        int start = 1;
        helper(n, k, start, slate, result);
        return result;
    }
};