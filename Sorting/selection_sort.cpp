#include <iostream>
#include <vector>

using namespace std;

// Summary:
// Selection and Bubble sort sort the array as they go along
// their best,average and worse case are o(n2)
// Pattern#1 is brute force

// Insertion sort assumes that there is one sorted array
// and it has to insert a new element in that sorted array
// best case is o(n) rest is o(n2)
/// Pattern#2 is decrease the problem space step by step and then conquer.

// #########################################################
//  Logic is to select the minimum element from the array
//  and move it to first position. Then choose 2nd min from
//  array and move it to 2nd position and so on.

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
// So scan array from begining to end, find smallest element
// exchange that element with a[0]. Then scan again from 1 to n-1
// find next smallest element and exchange with a[1]

// Correct logic is swap only the element present in j range
// which is less than i. If there is no element less than ith index
// no need of swap. Unnecessary swaping is reduced here.

// Decrease and Conquer design strategy....

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
// scan of arr starts from end of array and it keeps
// on bubbling up minimum element at the begining or
// array

// Decrease the problem space one by one and Conquer it --> design strategy....
// basically solve for a[0], and delegate a[n-1]
// to someone else

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

// Here we assume that n-1 array is already sorted. So we need
// to insert nth element in that n-1 sorted array.
// So we start comparing nth element from n-1 to 0, shifting
// element along with it and at end exchange the element....

// So assumption is left end of array is always sorted
// and we are inserting a new element in sorted array.
// new element to be inserted is stored in temp.
// Pattern is decrease the problem space step by step and then conquer.

void insertion_sort(vector<int> &arr)
{
    // Write your code here.
    int len = arr.size();
    int temp = 0;
    int redIndex = 0;
    for (int i = 0; i < len; i++)
    {
        temp = arr[i];
        // redIndex points to already sorted array
        // this array is at left of not sorted part of
        // array
        redIndex = i - 1;
        while (redIndex >= 0 && arr[redIndex] > temp)
        {
            arr[redIndex + 1] = arr[redIndex];
            redIndex--;
        }
        // Position to insert is found in sorted array
        arr[redIndex + 1] = temp;
    }
}

/**
 * @brief Performs insertion sort on the given vector.
 * ChatGpt is used to add comments and make this
 * Doxygen-compatible
 * @param arr The vector to be sorted.
 */
void insertion_sort_chatgpt(std::vector<int> &arr)
{
    int len = arr.size();
    int temp = 0;
    int redIndex = 0;

    // Iterate through the unsorted portion of the array
    for (int i = 0; i < len; i++)
    {
        temp = arr[i];    // Current element to be inserted at the appropriate position
        redIndex = i - 1; // Index of the last element in the sorted portion

        // Shift elements to the right until the correct position for the current element is found
        while (redIndex >= 0 && arr[redIndex] > temp)
        {
            arr[redIndex + 1] = arr[redIndex]; // Shift elements to the right
            redIndex--;
        }

        // Insert the current element at the correct position in the sorted portion
        arr[redIndex + 1] = temp;
    }
}

int main()
{
    vector<int> arr = {8, 7, 6, 5, 4, 3};
    insertion_sort(arr);
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