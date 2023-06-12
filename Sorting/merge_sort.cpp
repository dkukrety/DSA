#include <iostream>
#include <vector>

using namespace std;
// merge sort best,worse,average runtime o(nlogn)
// if add a logic to check if array is already sorted
// then for any sorting algorithm the runtime will be o(n)

// can we reduce worse case time for any sorting algorithm ?

// for an already sorted array insertion sort will be faster than
// merge sort

// what is TimSort?
// Merge sort also need extra space which is function of input, so
// to optimize merge sort, a hybrid algorithm is used where
// for small input size insertion sort is used(also the best case of
// insertion sort is o(n)) and for large input
// merge sort is used.
// This algorithm is standard sorting algo in python and in java it is used
// to sort objects

bool check_if_already_sort(const vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return false;
        }
    }
    return true;
}

// vector<int> arr = {5, 6, 3, 2, 1, 9, 7, 6};
// mergSortHelper(arr,0,8)
// mid = 0+8/2;
// mergSortHelper(arr,0,4) and mergSortHelper(arr,4,8)

void mergeSortHelper(vector<int> &arr, int start, int end)
{
    if (start >= end - 1)
        return;

    int mid = (end + start) / 2;
    mergeSortHelper(arr, start, mid);
    mergeSortHelper(arr, mid, end);

    vector<int> mList(end - start + 1);
    int i = start;
    int k = 0;   // Index for merged List
    int j = mid; // Start index of 2nd list
    while (i < mid && j < end)
    {
        if (arr[i] <= arr[j])
        {
            mList[k++] = arr[i++];
        }
        else
        {
            mList[k++] = arr[j++];
        }
    }

    while (i < mid)
    {
        mList[k++] = arr[i++];
    }
    while (j < end)
    {
        mList[k++] = arr[j++];
    }

    for (int l = 0; l < k; l++)
    {
        arr[start + l] = mList[l];
    }
}
void mergeSort(vector<int> &arr)
{
    // idea of whole code below is make best case complexity as o(n)
    if (arr.size() < 2)
    {
        return; // An empty or single-element vector is considered sorted.
    }
    if (check_if_already_sort(arr))
        return;

    mergeSortHelper(arr, 0, arr.size());
}
int main()
{
    vector<int> arr = {5, 6, 3, 2, 1, 9, 7, 6};
    mergeSort(arr);

    /*
        //Use stable sort alogithm as sort() uses quick sort
        //merge sort is stable algorithm and keeps the input data
        // in order
        stable_sort(arr.begin(),arr.end());

    */

    for (auto &i : arr)
    {
        cout << i << " ";
    }

    return 0;
}