#include <iostream>


// Sorting characters of a ASCII set...
// since here we have a character set of 255 chars....
// instead of using usual algorithms, it is fine to use
// couting sort with a extra memory as that will be more effcient..
// o(n)

vector<char> sort_array(vector<char> arr)
{
    vector<int> vec(256);

    for (int i = 0; i < arr.size(); i++)
    {
        vec[arr[i]]++;
    }

    int k = 0;

    for (int i = 0; i < 256; i++)
    {
        while (vec[i] > 0)
        {
            arr[k] = (char)i;
            vec[i]--;
            k++;
        }
    }

    return arr;
}

int main()
{
    return 0;
}