#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int index, int size)
{
    int lc = 2 * index + 1;
    int rc = 2 * index + 2;
    int len = size;

    if (lc < len)
        cout << index << " left child -->   " << arr[lc] << endl;
    if (rc < len)
        cout << index << " right child -->   " << arr[rc] << endl;

    if (index == 0)
    {
        if (lc < len && rc < len)
        {
            if (arr[lc] < arr[rc])
                swap(arr[lc], arr[rc]);
        }
        heapify(arr, lc, size);
        return;
    }

    int big = index;
    if (lc < len && arr[big] < arr[lc])
        big = lc;
    else if (rc < len && arr[big] < arr[rc])
        big = rc;

    if (big != index)
    {
        swap(arr[big], arr[index]);
        heapify(arr, big, size);
    }
    // heapify(arr, index / 2);
}

// heapsort is logically represented as binary heap where root node is >= to its child node
// also every node should have max 2 child.
// We fill child nodes or leaf nodes from left to right
// Physically binary heap is represented as array[]
// index 0 is intentially left out...

vector<int> heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Building a Max-Heap in a bottom-up manner.
    // Heapifying only the indices in range [0, n/2 - 1) because only these indices will have at-least one
    // child node in the Max-Heap.
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    for (auto i : arr)
    {
        cout << "   " << i << "  ";
    }

    cout << "\nheapsort now  \n";

    for (int i = n - 1; i > 0; i--)
    {
        // if (arr[1] < arr[i])
        swap(arr[1], arr[i]);
        heapify(arr, 0, i);
    }

    for (auto i : arr)
    {
        cout << "   " << i << "  ";
    }
    return arr;
}

int main()
{
    vector<int> arr = {INT16_MAX, 2, 3, 1, 0, -1, 9, 8, -2};
    heapSort(arr);
    return 0;
}