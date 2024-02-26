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
    vector<int> aux(20, 0);
    for (auto i : arr)
    {
        aux[i] = ++aux[i];
    }

    return aux;
};

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

    for (int i = 0; i < 20; i++)
    {
        if (aux[i])
            cout << i << "   ";
    }
    cout << endl;
    return 0;
}