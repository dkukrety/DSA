/*
Given a set of integers and a target value k, find whether there is a non-empty subset that sums up to k.

Example One
{
"arr": [2, 4, 8],
"k": 6
}
Output:

1
Because 2 + 4 = 6.

Example Two
{
"arr": [2, 4, 6],
"k": 5
}
Output:

0
Because no subset of numbers from the input sums up to 5.

use, count also to check do not pick any number...

if slate == target
  if count!=0
    return true;

if (index == arr.size())
return false

return helper(arr,target,index+1,sum,count)||helper(arr,target,index+1,sum+arr[index],count+1)
*/

bool helper(vector<long long> arr, int index, long long target, vector<long long> slate)
{
    if (index == arr.size())
    {
        if (slate.empty())
            return false;
        if (slate.front() == target)
            return true;
        else
            return false;
    }

    // choose the index value
    long long temp;
    bool slateWasNotEmpty = false;
    if (!slate.empty())
    {
        temp = slate.front();
        slate.pop_back();
        slate.push_back(arr[index] + temp);
        slateWasNotEmpty = true;
    }
    else
    {
        slate.push_back(arr[index]);
    }

    bool chosen = helper(arr, index + 1, target, slate);
    slate.pop_back();
    if (slateWasNotEmpty)
    {
        slate.push_back(temp);
    }

    bool notchosen = helper(arr, index + 1, target, slate);

    return chosen || notchosen;
}

bool check_if_sum_possible(vector<long long> &arr, long long k)
{

    vector<long long> slate;
    return helper(arr, 0, k, slate);
}

/*
Given a positive integer n, return ALL strings of length 2 * n with well-formed round brackets.

Example
{
"n": 3
}
Output:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
Any array containing these five strings in any order is a correct output.

Notes
Order of strings in the returned array is insignificant, e.g. for n = 2 both ["(())", "()()"] and ["()()", "(())"] will be accepted.
Constraints:

1 <= n <= 12
Only use round brackets. '(' and ')'


keep track of opening and closing bracket...
opening < n
closing should be always < opening..

catalan number as time complexity...

*/
