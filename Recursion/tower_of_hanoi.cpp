#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// Procedures are more algo in chars
//
void toh(int n, vector<int> src_tower, vector<int> &dst_tower, vector<int> aux_tower)
{
    if (n == 1)
    {
        dst_tower.push_back(src_tower[n - 1]);
    }
    else
    {
        toh(n - 1, src_tower, dst_tower, aux_tower);
        dst_tower.push_back(src_tower[n - 1]);
        toh(n - 1, aux_tower, dst_tower, src_tower);
    }
}
int main()
{
    vector<int> src_tower = {9, 8, 5, 4, 2, 1};
    vector<int> dst_tower;
    vector<int> aux_tower;

    toh(src_tower.size() - 1, src_tower, dst_tower, aux_tower);
    for (auto i : dst_tower)
    {
        cout << i << " ";
    }
}
