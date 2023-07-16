#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

/*
Given four billion of 32-bit integers, return any one that’s not among them. Assume you have 1 GiB (10243 bytes) of memory.

Follow up: what if you only have 10 MiB of memory?

Example One
{
"arr": [0, 1, 2, 3]
}
Output:

4
Any number in the [4 .. 232) range is a correct answer.
*/

// Some stupid answer:

long long find_integer(vector<long long> &arr)
{
    long long i = 0;
    long long n = arr.size();

    for (long long i = 0; i < n; i++)
    {
        while (arr[i] < n && arr[i] != i)
            swap(arr[arr[i]], arr[i]);
    }
    i = 0;
    while (i < n)
    {
        if (arr[i] != i)
        {
            return i;
        }
        i++;
    }
    return i;
}

// Using 1 GB Memory.
/*
 * Asymptotic complexity in terms of size of `arr` `n`:
 * Time: O(n).
 * Auxiliary space: O(1).
 * Total space: O(n).
 */

/*static Long find_integer(ArrayList<Long> arr)
{
    int size = (int)((Math.pow(2, 32)) / 8);
    byte[] bytes = new byte[size]; // Initialized with zeros by the JVM.
    for (long inputValue : arr)
    {
        int byteIndex = (int)(inputValue / 8);
        int bitIndex = (int)(inputValue % 8);
        // Set the bit corresponding to inputValue:
        bytes[byteIndex] |= 1 << bitIndex;
    }
    for (int byteIndex = 0; byteIndex < size; byteIndex++)
    {
        for (int bitIndex = 0; bitIndex < 8; bitIndex++)
        {
            if ((bytes[byteIndex] & (1 << bitIndex)) == 0)
            {
                // As soon as we have found the first unset bit,
                // return the number corresponding to that bit.
                return byteIndex * 8L + bitIndex;
            }
        }
    }
    throw new IllegalStateException(
        "Must have found an unset bit and returned from the loop");
}*/

/*
 * Asymptotic complexity in terms of size of `arr` `n`:
 * Time: O(n).
 * Auxiliary space: O(1).
 * Total space: O(n).
 */

// We split the whole range of possible input values [0..2^32) into
// 2^16 non-overlapping subranges, each subrange is 2^16-long:
// 0-th subrange: [0 .. 2^16),
// 1-st subrange: [2^16 .. 2^17),
// ...,
// the last, (2^16-1)-th subrange: [2^32-2^16 .. 2^32).
// static final int TWO_POWER_SIXTEEN = (int)(Math.pow(2, 16));

/*static Long find_integer(ArrayList<Long> arr)
{
    // This array will store how many input array elements actually fall
    // into each bucket. Its size is 2^16 * 8 bytes = 2^19 bytes = 1/2 MiB.
    long[] numbersInBucket = new long[TWO_POWER_SIXTEEN];
    for (long inputValue : arr)
    {
        // Dividing the number by 2^16 determines which bucket/subrange it falls into.
        int bucket = (int)(inputValue >> 16);
        numbersInBucket[bucket]++;
    }
    // Now let's find a bucket/subrange that has at least one number missing
    // from the input AND then find a missing number in that subrange.
    for (int bucket = 0; bucket < TWO_POWER_SIXTEEN; bucket++)
    {
        if (numbersInBucket[bucket] >= TWO_POWER_SIXTEEN)
        {
            // This bucket _might_ have its entire subrange covered by input values.
            // Let's skip it. There certainly exists a bucket will fewer input values.
            continue;
        }
    // We found a bucket with fewer than 2^16 input values fallen into it.
    // This guarantees that at least one value from this bucket's subrange
    // isn't present in the input.
    // Such value is
*/

int main()
{
    vector<long long> v = {123123, 43, 54, 2};
    bitset<32> bs;

    for (auto i : v)
    {
        cout << i << "  ";
        bs = bs + i;
        cout << bs << endl;
    }
    return 0;
}