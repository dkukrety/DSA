#include <iostream>
#include <vector>
#include <random>

using namespace std;

/*Some notes about quick-sort
1. Find a pivot by looking into the array. This pivot can be generated randomly to avoid worse case
2. Exchange pivot with a[start]
3. Divide the array based on a[start], left side of array caller smaller part should be less than a[start]
4. right side of array called bigger part should be greater than a[start]
5. then call quick-sort recursively like qsort(arr,start,end_of_smaller_part),
qsort(arr,start_of_bigger_part,end).
6. No need to combine results, as it is already sorted, because pivot element is always place at its right
position.
7. Efficient than merge-sort as it does not use auxillary space to combine
8. But its not a stable sort as swapping of element happens in large range
9. worse case is o(n2), as input array can be already sorted, and it will skew the quick_sort
10. average and best case is o(nlogn)
*/

/*
How to divide array based on pivot.

In place partitioning. (Lomuto)
This is --> Decrease and Conquer approach
1. take start index as pivot
2. assume array from 1...to n-1 is a bigger element array.
3. Now you have to form smaller element array from this bigger element array.
   so you need to compare arr[pivot] with 1...to n-1.
4. lets say smaller is smaller array index and bigger is bigger array index
   smaller -->0 bigger -->1

    for bigger index 1 to n-1
          if arr[pivot]>arr[bigger] then do
                smaller++
                 swap(arr[smaller],arr[bigger]
    at end when loop ends
    swap(arr[smaller],arr[pivot])
*/

/*
How to divide array into 2 parts using pivot.
Decrease and conquer approach--> using 2 pointers or both direction approach...
Here we assume that smaller number array starts from left and bigger number array starts from right...

smaller = a[0+1]
bigger=a[n-1]
start=pivot = a[0]
now while(smaller <= bigger ){
// dont believe in smaller<=bigger but will see writing code
    if(a[start]>a[smaller])
        smaller++;
    else if(a[start]<a[bigger])
        bigger--
    else
      swap(a[smaller],a[bigger])
      smaller++;
      bigger--;
}

at the end i assume smaller will equal to == bigger...now this is a problem
so i think i will correct while loop logic....because we want to know
if smaller==bigger is less than pivot or greater than pivot...
now bigger  will point to last smaller number
and smaller will point to starting of bigger...

so i can swap pivot...
swap(a[start],a[bigger])

quicksort(arr,start,bigger-1)
quicksort(arr,bigger+1,end)
*/

int getRandomNumber(int start, int n)
{
    // Seed the random number generator with a time-based seed
    std::mt19937 rng(std::random_device{}());

    // Define the range of the random number
    std::uniform_int_distribution<int> distribution(start, n);

    // Generate a random number within the defined range
    int randomNum = distribution(rng);

    return randomNum;
}

void LomutoPartition(vector<int> &arr, int start, int end, int &smaller)
{
    int pivot = getRandomNumber(start, end - 1);
    cout << "Pivot  " << pivot << endl;

    // swap with pivot
    swap(arr[start], arr[pivot]);

    pivot = start;
    smaller = start;

    for (int bigger = pivot + 1; bigger < end; bigger++)
    {
        if (arr[bigger] <= arr[pivot])
        {
            smaller++;
            if (smaller != bigger)
                swap(arr[smaller], arr[bigger]);
        }
    }
    swap(arr[smaller], arr[pivot]);
}


void quickSortHelper(vector<int> &arr, int start, int end)
{
    if (start >= end - 1)
        return;

    // This will point to pivot element places at right position
    // after Lomuto partition
    int smaller = -1;

    // Now use Lomuto partition
    LomutoPartition(arr, start, end, smaller);

    quickSortHelper(arr, start, smaller);
    quickSortHelper(arr, smaller + 1, end);
}

void quickSort(vector<int> &arr)
{
    // we can add logic here to detect if it is already sorted.

    quickSortHelper(arr, 0, arr.size());
}

int main()
{
    vector<int> arr = {5, 6, 3, 2, 1, 9, 7, 6};
    quickSort(arr);
    // cout << getRandomNumber(2, 2) << endl;

    for (auto &i : arr)
    {
        cout << i << " ";
    }

    return 0;
}