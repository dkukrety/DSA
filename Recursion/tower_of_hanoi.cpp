#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// Procedures are more algo in chars
//
void toh(int n, vector<int> src_tower, vector<int> &dst_tower, vector<int> aux_tower)
{
    if (n == 0)
    {
        dst_tower.push_back(src_tower[n]);
    }
    else
    {
        toh(n - 1, src_tower, aux_tower, dst_tower);
        dst_tower.push_back(src_tower[n-1]);
        toh(n - 1, aux_tower, dst_tower, src_tower);
    }
}


//aux is helper or piller 2
void helper(int n,int s,int aux,int d,vector<vector<int>> &result)
{
    if(n==1)
    {
        result.push_back({s,d});
        return;
    }
    helper(n-1,s,d,aux, result);
    result.push_back({s,d});
    helper(n-1,aux,s,d, result);
}

//simple reduce and conquer problem
// 
vector<vector<int>> tower_of_hanoi(int n) {
    // Write your code here.
    vector<vector<int>> result;
    helper(n,1,2,3,result);
    return result;
}


int main()
{
    vector<int> src_tower = {9, 8, 5, 4, 2, 1};
    vector<int> dst_tower;
    vector<int> aux_tower;

    toh(src_tower.size(), src_tower, dst_tower, aux_tower);
    for (auto i : dst_tower)
    {
        cout << i << " ";
    }
}
