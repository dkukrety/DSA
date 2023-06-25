#include <iostream>
#include <vector>

using namespace std;

/*
{
"arr": [5, 8, 3, 9, 4, 1, 7]
}
*/

vector<int> countingSort(vector<int> &arr)
{
    vector<int> aux(arr.size(), 0);
    for (auto i : arr)
    {
        aux[i] = aux[i]++;
    }

    return aux;
}
int main()
{
    vector<int> arr = {
        5,
        8,
        3,
        9,
        4,
        1,
    };

    for (auto i : arr)
    {
        cout << i << "   ";
    }
    cout << endl;

    vector<int> aux = countingSort(arr);

    for (auto i : aux)
    {
        cout << i << "   ";
    }
    cout << endl;
    return 0;
}