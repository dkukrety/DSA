#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// using decrease and conquer
// using recursion

int helper_foraddition(vector<int> nums, int i)
{
    if (i == nums.size() - 1)
        return nums[i];

    return nums[i] + helper_foraddition(nums, i + 1);
}

int additions(vector<int> nums)
{
    if (nums.size() == 0)
        return 0;
    return helper_foraddition(nums, 0);
}

// fibonacci series
// general additive sequence..
// which is better in time complexity ?
// recursive with 2 childs(o2n) or iterative o(n)?
// what about recursive with one child??
// what if we combine concept of recursion with single child with tail recursion
// will that help? will that convert

// worse code

int find_fibonacci0(int n)
{
    if (n == 0 || n == 1)
        return n;
    return find_fibonacci0(n - 1) + find_fibonacci0(n - 2);
}

// Much better code in linear time.

int fib(int n, int b1, int b2)
{
    if (n == 0)
    {
        return b1;
    }
    else
    {
        return fib(n - 1, b2, b1 + b2);
    }
    return 0;
}

int find_fibonacci1(int n)
{
    // Write your code here.
    return fib(n, 0, 1);
    return 0;
}

// iterative

int find_fibonacci2(int n)
{
    // Write your code here.

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int zeroth = 0;
    int first = 1;
    for (int i = 2; i <= n; ++i)
    {
        int next = zeroth + first;
        zeroth = first;
        first = next;
    }
    return first;
}

// Decrease and conquer
// to calculate fatorial

int fact(int n)
{
    if (n == 0)
        return 1;
    else
    {
        return n * fact(n - 1);
    }
}

// Compute n to the power k
int power(int n, int k)
{
    if (k == 1)
        return n;
    else
    {
        return n * power(n, k - 1);
    }
}

/*
// using divide and conquer
// using recursion
// merge sort and quick sort



// Solving A or B problem with recursion

// Solving A and B problem with recursion

// Enumeration recursively, exhausitive enumerations...

// LetterCase permutations. str=a1b2 is given...
// generate all possible combinations by transforming every alphabet to uppercase or lowercase chars
// out can be a1b2, A1b2,A1B2, and a1B2,,, only alphabets can be changed...digit should remain same...
// if str=12345...output will be 12345 only...
// solve using recursion...
// time space complexity...we have n blanks variable....and for evry blank we have 2 choices...
// so it will be 2 to the power n...
// but to copy the slate to the bad it will take n time...
// so total time will be n*2 to the power n.
// space required....is o(n2) for internal nodes..
// as first level it is 1,2,3,......is n(n+1)/2....
// so space complexity was implicit stack space, which is o(n square)
// total space required for global is 2 to the power n * n
// so total space complexit is 2 to the power n * n
*/

void letterCasehelper(string str, string &slate, int index, vector<string> &res)
{

    // base case
    if (index == str.size())
    {
        res.push_back(slate);
        return;
    }

    // Internal nodes
    // there are only 2 choices
    // we can go to lowercase path or uppercase path.
    // for numbers we will just add it to slate and go to
    // next char

    if (isdigit(str[index]))
    {
        slate += str[index];
        letterCasehelper(str, slate, index + 1, res);
        slate.pop_back();
    }
    else
    {
        // lowercase
        slate.push_back(tolower(str[index]));
        letterCasehelper(str, slate, index + 1, res);

        // we need to restore the content of slate back
        // so we need to do slate.pop_back()
        // this is what is backtracking, basically restoring to slate to original position..
        slate.pop_back();

        // uppercase
        slate.push_back(toupper(str[index]));
        letterCasehelper(str, slate, index + 1, res);

        // we need to restore the content of slate back
        // so we need to do slate.pop_back()
        // this is what is backtracking, basically restoring to slate to original position..
        slate.pop_back();
    }
}

vector<string> letterCasePerm(string istr)
{
    vector<string> res; // This will hold the result
    string slate;       // this will hold the result till leaf node
    int index = 0;      // Index of processing the string

    letterCasehelper(istr, slate, index, res);

    return res;
}

// Given array of unique numbers ...generate all possible subsets...
// [1,2,3] --> [],[1],[2],[3],[1,2]
// use include or exclude choices...keep a number or not keep the number...
// rest logic is same as above...
//

void helperSubsets(vector<int> arr, vector<int> &slate, int index, vector<vector<int>> &res)
{
    if (index == arr.size())
    {
        res.push_back(slate);
        return;
    }

    // make choice

    // exclude a number, that means nothing needs to be added to slate
    helperSubsets(arr, slate, index + 1, res);

    // include
    slate.push_back(arr[index]);
    helperSubsets(arr, slate, index + 1, res);

    slate.pop_back();
    // just to put slate in original state...
}

vector<vector<int>> generateSubset(vector<int> arr)
{
    vector<int> slate;
    vector<vector<int>> res;
    helperSubsets(arr, slate, 0, res);
    return res;
}

// given a array of numbers containing duplicates..., generate all unique subsets...
//  are input..numbers in the array always going to be sorted format ??
//  same as above if numbers are sorted...
void generateUniqueSubsetHelper(vector<int> arr, vector<int> &slate, int index, vector<vector<int>> &res)
{
    if (index == arr.size())
    {
        res.push_back(slate);
        return;
    }

    // Since numbers array is already sorted
    // skip duplicate entries
    while (index < arr.size() && index > 0 && arr[index] == arr[index - 1])
    {
        index++;
    }
    // exclude a number, that means nothing needs to be added to slate
    // helper(arr, slate, index + 1, res) not sure why this was not taken...
    generateUniqueSubsetHelper(arr, slate, index + 1, res);

    // include
    slate.push_back(arr[index]);
    generateUniqueSubsetHelper(arr, slate, index + 1, res);

    slate.pop_back(); // just to put slate in original state...
}
vector<vector<int>> generateUniqueSubset(vector<int> arr)
{
    vector<int> slate;
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    generateUniqueSubsetHelper(arr, slate, 0, res);
    return res;
}

// This logic does not work if there is repeated or duplicate elements.

int numberOfSubsets(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return 2 * numberOfSubsets(n - 1);
}

// given array of numbers generate all permutations...
// fill in blanks kind of qiestions...
// if there are n number how many permutation we can have...
// it will be n!
// so TC: is n!...if we assum we are taking n time to insert in bag or result set , then its n*n!
// SC: stack space is o(n), o(n*n!)

// now code...

void genPermHelper(vector<int> nums, vector<int> &slate, int index, vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        // result.push_back(slate);
        // slate is not needed as we are swapping and impacting directly
        // nums array.
        result.push_back(nums);
        return;
    }

    for (int pick = index; pick < nums.size(); pick++)
    {
        cout << index << "   " << pick << "  pushing " << nums[index] << endl;
        // slate.push_back(nums[pick]);
        // slate not needed as we are swapping.
        swap(nums[pick], nums[index]);
        genPermHelper(nums, slate, index + 1, result);
        // slate.pop_back();
        swap(nums[pick], nums[index]);
    }
}

vector<vector<int>> genPerm(vector<int> nums)
{
    vector<vector<int>> result;
    vector<int> slate;
    genPermHelper(nums, slate, 0, result);
    return result;
}

int main()
{
    vector<int> arr = {-1, 1, -2, 2, -3};
    cout << "Addition of numbers using recurstion " << additions(arr) << endl;

    // generate all possible combinations by transforming every alphabet to uppercase or lowercase chars
    // out can be a1b2, A1b2,A1B2, and a1B2,,, only alphabets can be changed...digit should remain same...
    // if str=12345...output will be 12345 only...

    // string input = "a1b2c3d5";
    string input = "12345";
    for (auto i : letterCasePerm(input))
    {
        cout << i << "  " << endl;
    }

    cout << endl;

    // Given array of unique numbers ...generate all possible subsets...
    // [1,2,3] --> [],[1],[2],[3],[1,2]
    // use include or exclude choices...keep a number or not keep the number...
    // rest logic is same as above...
    //

    vector<int> in = {1, 2, 3};
    for (auto i : generateSubset(in))
    {
        for (auto j : i)
            cout << j << "  ";
        cout << endl;
    }

    cout << "Generating Unique subsets\n";

    vector<int> in1 = {1, 2, 3, 2, 4, 3, 5, 6, 7, 6};

    for (auto i : generateUniqueSubset(in1))
    {
        for (auto j : i)
            cout << j << "  ";
        cout << endl;
    }

    cout << "Number of repeated and unique subsets in above Set is " << numberOfSubsets(in1.size()) << endl;

    for (auto i : genPerm({1, 2, 3}))
    {
        for (auto j : i)
            cout << j << "  ";
        cout << endl;
    }
}