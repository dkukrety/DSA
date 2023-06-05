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

int main()
{
    vector<int> arr = {1, 4, 2, 3, 8, 7};
    selection_sort(arr);
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