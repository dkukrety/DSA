#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> find2SumUsingHashMap(vector<int> &arr, int target)
{
    unordered_map<int, bool> umap;
    vector<pair<int, int>> p = {};
    for (int i = 0; i < arr.size(); i++)
    {
        if (umap.find(target - arr[i]) == umap.end())
        {
            umap[arr[i]] = true;
        }
        else
        {
            p.emplace_back(arr[i], target - arr[i]);
        }
    }

    return p;
}

/*
vector<int> two_sum(vector<int> &numbers, int target) {
    unordered_map<int, int> umap;
    vector<int> result = {-1,-1};
    for (int i = 0; i < numbers.size(); i++)
    {
        if (umap.find(target - numbers[i]) == umap.end())
        {
            umap[numbers[i]] = i;
        }
        else
        {
            result.clear();
            result.emplace_back(i);
            result.emplace_back(umap[target - numbers[i]]);
            return result;
        }
    }

    return result;
}
*/
// This has bug that it is searching in entire array, so there will be repeat of same pair
//(1, 9) (2, 8) (5, 5) (8, 2) (9, 1)
// how to fix above
vector<pair<int, int>> find2SumUsingSortingAndBinarySearch(vector<int> &arr, int target)
{
    vector<pair<int, int>> p = {};
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (binary_search(arr.begin(), arr.end(), target - arr[i]))
        {
            p.emplace_back(arr[i], target - arr[i]);
        }
    }

    return p;
}

vector<pair<int, int>> find2SumUsingTwoPointer(vector<int> &arr, int target)
{
    vector<pair<int, int>> p = {};
    sort(arr.begin(), arr.end());

    int p1 = 0;
    int p2 = arr.size() - 1;

    while (p1 < p2)
    {
        if (arr[p1] + arr[p2] == target)
        {
            p.emplace_back(arr[p1], arr[p2]);
            p1++;
            p2--;
        }

        if (arr[p1] + arr[p2] > target)
        {
            p2--;
        }

        if (arr[p1] + arr[p2] < target)
        {
            p1++;
        }
    }

    return p;
}

/*vector<int> pair_sum_sorted_array(vector<int> &numbers, int target) {
    vector<int> result = {-1,-1};
    int p1 = 0;
    int p2 = numbers.size() - 1;

    while (p1 < p2)
    {
        if (numbers[p1] + numbers[p2] == target)
        {
            result.clear();
            result.emplace_back(p1);
            result.emplace_back(p2);
            return result;
        }

        if (numbers[p1] + numbers[p2] > target)
        {
            p2--;
        }

        if (numbers[p1] + numbers[p2] < target)
        {
            p1++;
        }
    }

    return result;
}*/

bool find2SumExploration(vector<int> &arr, int target)
{
    // Brute force?? n2

    // sorting and then searching? nlogn

    // use set to find??
    // Sets are implemented using a binary search tree. Insert element in set
    // and then search

    // two pointer approach ??
    /*sort(arr)
    if p1+p2 < T --> p1++
       p1+p2 > T --> p2++
       p1+p2 == T return true
    */
    // Can we follow two pointer approach without sorting the array? No
    // Better to use hashmap --> unordered array
    // Also if there are multiple answers are present
    //(multiple unique pairs) then how to print that?
    // what to do when we have multiple pairs which same values??
    // what if we used hashmap search is o(1)? search for counter-part in hashmap
    // Internally unordered_map is implemented using Hash Table,
    // the key provided to map is hashed into indices of a hash table which is why the performance of data structure depends on the hash
    // function a lot but on average, the cost of search, insert, and delete from the hash table is O(1).

    int p1 = 0;
    int p2 = arr.size() - 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[p1] + arr[p2] == target)
            return true;

        if (arr[p1] + arr[p2] < target && arr[p1] < arr[p2])
        {
            p1++;
        }
        else
        {
            p2--;
        }

        if (arr[p1] + arr[p2] > target && arr[p1] > arr[p2])
        {
            p1++;
        }
        else
        {
            p2--;
        }
    }

    return false;
}
int main()
{
    vector<int> arr = {6, 5, 1, 2, 3, 8, 0, 9};

    std::vector<std::pair<int, int>> pairs = find2SumUsingTwoPointer(arr, 11);
    for (auto p : pairs)
    {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    return 0;
}