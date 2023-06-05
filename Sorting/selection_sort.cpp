#include <iostream>
#include <vector>

using namespace std;

// Logic is to select the minimum element from the array
// and move it to first position. Then choose 2nd min from
// array and move it to 2nd position and so on.

void selection_sort(vector<int> &arr)
{
    // Write your code here.
    int len = arr.size();
    for (int i = 0; i < len - 1; i++)
    {
        int minindex = 0;
        int minvalue = 0;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                minvalue = arr[j];
                minindex = j;
                std::swap(arr[i], arr[minindex]);
            }
        }
    }
}

// Overall logic is in first pass arr[0] should contain minimum
// element of array. In second pass arr[1] should have second minimum

// Correct logic is swap only the element present in j range
// which is less than i. If there is no element less than ith index
// no need of swap. Unnecessary swaping is reduced here.

void selection_sort_correct_one(vector<int> &arr)
{
    // Write your code here.
    int len = arr.size();
    int minindex = 0;
    for (int i = 0; i < len - 1; i++)
    {
        minindex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        if (minindex != i)
            std::swap(arr[i], arr[minindex]);
    }
}

// Logic is to bubble down minimum element to arr[0]
// so keep on comparing with nighbour element.
// scan of arr starts from end of array.

void bubble_sort(vector<int> &arr)
{
    // Write your code here.
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

int main()
{
    vector<int> arr = {8, 7, 6, 5, 4, 3};
    bubble_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    for (auto &element : arr)
    {
        cout << element << " ";
    }
}