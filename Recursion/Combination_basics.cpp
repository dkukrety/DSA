#include <iostream>
#include <vector>
using namespace std;

// write recursive implementation of C(n,k)
// if there are n people and you want to form k commities out of that.
// in combination once we decide not to choose or not the pick does not picked again.
// Since there are 2 choices...T(C) is 2 raise to power n.

// choice is n-1,k-1 and n-1,k
// need to find bug in below code..

vector<vector<int>> combination(int n, int k, vector<int> slate, vector<vector<int>> &result)
{
    if (n == k || k == 0)
    {
        cout << "n=" << n << "  k=" << k << endl;
        result.push_back(slate);
        return result;
    }
    else // either choose a people part of commity or do not choose
    {
        // choose  and add it to slate
        slate.push_back(n);
        combination(n - 1, k - 1, slate, result);
        slate.pop_back();
        combination(n - 1, k, slate, result);
    }
    return result;
}

/*

https://www.geeksforgeeks.org/make-combinations-size-k/

void rec(int i, int k, int n, vector<int>& cur, vector<vector<int>>& res){
    if(cur.size()==k) {
        res.push_back(cur);
    } else {
        for(int j=i;j<=n;j++) {
            cur.push_back(j);
            rec(j+1, k, n, cur, res);
            cur.pop_back();
        }
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    rec(1, k, n, cur, res);
    return res;
}
*/

int main()
{
    vector<int> slate;
    vector<vector<int>> result;
    combination(5, 2, slate, result);
    for (auto i : result)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
}