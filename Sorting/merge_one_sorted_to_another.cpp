#include <iostream>
#include <vector>

using namespace std;

// Merging two sorted list, second list is twice of first list.
// idea is not to use any auxillary space.

// So basically merge from the end of both array....
// but remember that we need to copy element from second array [first.size()-1]
// position as element is both sorted array are same...it is just that second
// array as more space filled with zero.

// if in case both array size is same, then we need to use aux array or
// expand size of second array which is again will increase time complexity.

vector<int> merge_one_into_another(vector<int> &first, vector<int> &second)
{
    int flen = first.size() - 1;
    int slen = flen;
    int tlen = flen + slen + 1;

    while (tlen >= 0 && flen >= 0 && slen >= 0)
    {
        if (first[flen] >= second[slen])
        {
            second[tlen--] = first[flen--];
        }
        else if (first[flen] < second[slen])
        {
            second[tlen--] = second[slen--];
        }
    }
    // cout << flen << "   " << slen << "  " << tlen;

    while (flen >= 0 && tlen >= 0)
        second[tlen--] = first[flen--];

    while (slen >= 0 && tlen >= 0)
        second[tlen--] = second[slen--];

    return second;
}

int main()
{
    vector<int> first = {-2, 1, 5};
    vector<int> second = {2, 4, 6, 0, 0, 0};

    merge_one_into_another(first, second);

    for (auto &i : second)
    {
        cout << i << " ";
    }
}