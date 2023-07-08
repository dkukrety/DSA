#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// generate all unique permutations of {1,1,2}
// 1,1,2, 2,1,1  1,2,1  -->  _ _ _
// generateUniquePerms(arr)
// using pruning technique...or branch bound...do not process...
// like if index == prev index...ignore that branch...
// similar to generate unique subsets...only num is used as slate..
// here we are including everything in a num array, but skipping processing
// of repeated numbers...

// next problem --> letter combination of phone keypad
// n choose k problem...nokia keypad mapped to letters like "ABC"
// so what all output can be when user press "23"
// map each number key to list of characters..
// 2 --> ABC
// 3 --> DEF
// 4 --> GHI
// and so on.

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/
// we can have only max 4 as length on input...then it is 4 to power 4.
// space complex ...will be 4*(4 to the power of 4)
// and at each level we can have m choices and if we have n as max styles...
// then its m to the power n.
// copying to resultant array will have n*(m to the power n)
// if problem size is small, like in this problem, then time complexity of exponention
// time is fine..
// letterNumberCombinations()
// helper(digits,index,slate,result)
//

// N-queen problem -- kind of board problem...
// chess board of size 4..place 4 queeen such that no two queen should be able to
// attack each other...
// we need to place 4 queen..

/*helper(board, row, result)
{
    if (row == board.size())
    {
        result.add(board[:]) return;
    }



    for
        col in range(0, len(board)) :
        //why row is not considered??
        if (isValid(board, row, col))
        {
            board[row][col] = "Q";
            helper(board, row +1, result);
            board[row][col] = ".";
        }
}

isValid(board, row, col)
{
    // check for Q in row above

    // check for Q in left-diag above

    // check of Q in right-diag above..
}*/

void genUniquePermHelper(vector<int> nums, int index, vector<int> slate, vector<vector<int>> &res)
{
    if (index == nums.size())
    {
        // res.push_back(slate);
        res.push_back(nums);
        return;
    }

    // Skip index if it is same as previus index...

    // Pick all numbers for index position...
    for (int pick = index; pick < nums.size(); pick++)
    {
        // skipping index in advance as, swap happens below.

        if (index < nums.size() && nums[pick] == nums[pick + 1])
        {
            continue;
            index++;
        }
        // slate.push_back(nums[pick]);
        swap(nums[pick], nums[index]);
        genUniquePermHelper(nums, index + 1, slate, res);
        // slate.pop_back();
        swap(nums[pick], nums[index]);
    }
}
vector<vector<int>> genUniquePerm(vector<int> nums)
{
    vector<vector<int>> res;
    vector<int> slate;
    genUniquePermHelper(nums, 0, slate, res);

    return res;
}

void letterCombinationHelper(string str, int index, string slate, vector<string> &result, map<int, string> mp)
{
    if (index = str.length())
    {
        result.push_back(slate);
    }

    for (int pick = index; pick < str.length(); pick++)
    {
        slate.push_back(str[pick]);
    }
}
vector<string> letterCombination(string str)
{
    vector<string> result;
    string slate;
    map<int, string> mp = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}};

    letterCombinationHelper(str, 0, slate, result, mp);

    return result;
}

int main()
{
    /*for (auto i : genUniquePerm({1, 3, 4, 2}))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }*/

    // https://leetcode.com/problems/letter-combinations-of-a-phone-number/

    for (auto i : letterCombination("23"))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}