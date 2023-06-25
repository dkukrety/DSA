
#include <iostream>
#include <vector>
#include <random>

using namespace std;

/*
QUICK SELECT Implementation
1. sort the array, then kth larget element is n-k element...nlogn time complexity..
2. using decrease and conquer the technique? bubble sorting? so it will not
    work as it is o(n2)
3. Transform and conquer?
    can heap be used? max heap is easy...

    how can we use min heap...
    build a min heap of kth largest number...

    now compare min-heap and max-heap timecomplexuty...
    when k --> n...then min heap is good..
    when k --> n/2 then time complexity is same for both min-heap and max-heap..

    its worse than sorting array and searching...
4. Divide and conquer tech..
like quick sort...
quick-select techqniqu...
   pivot is at right place...after sorting..compare pivot element index with (n-k) index...
   if it is equal then you got the kth number...
   otherwise if g < n-k, then quicksort(arr,g+1,end)
   else quicksort(arr,start,g)

   worst case complexity is o(n2)
   average case is o(n)  --> n + .95n + .95*.95n ==> n(1+.95+.95*.95....)

    quickselect is most efficient way to select kth number in a non-sorted array..o(n) time..


    function helper()
    if start ==  end return

    pivotindex = random...
    partion it,

    after partition check if n-k == smaller_pointer ? then return
    else partition again

    same thing should be done for kth smallest number...


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
    // cout << "Pivot  " << pivot << endl;

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

int quickSortHelper(vector<int> &arr, int start, int end, int key)
{
    if (start >= end - 1)
        return arr[end - 1];

    // This will point to pivot element places at right position
    // after Lomuto partition
    int pivot = -1;

    // Now use Lomuto partition
    LomutoPartition(arr, start, end, pivot);

    if (pivot == key)
        return arr[key];

    else if (pivot < key)
    {

        return quickSortHelper(arr, pivot + 1, end, key);
    }
    // else if (pivot > key)
    //{
    return quickSortHelper(arr, start, pivot, key);
    //}
}

// Use quicksort to find out the number, while doing processing of sorting.
// we know that pivot index after rearragning does not changes its position...
// and we know kth largest number is at n-k position.
// so if n-k == pivot then we got the answer.

int kthLargestNumber(vector<int> &arr, int k)
{
    return quickSortHelper(arr, 0, arr.size(), arr.size() - k);
}

// for kth smallest number, it should be k-1 == pivot.
int kthSmallestNumber(vector<int> &arr, int k)
{
    return quickSortHelper(arr, 0, arr.size(), k - 1);
}

int main()
{
    vector<int> arr = {2, 3, 7, 1, 0, 9, 8};
    cout << "kthLargestNumber --> " << kthLargestNumber(arr, 5) << endl;
    cout << "kthSmallestNumber --> " << kthSmallestNumber(arr, 4);
    return 0;
}