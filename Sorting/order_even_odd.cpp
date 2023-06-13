#include <iostream>
#include <vector>

using namespace std;

vector<int> segregate_evens_and_odds(vector<int> &numbers)
{
    int e = 0;
    int o = numbers.size() - 1;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2 == 0 && e < i)
        {
            swap(numbers[i], numbers[e++]);
            i--;
        }
        else if (o > i)
        {
            swap(numbers[i], numbers[o--]);
            i--;
        }
    }
    return numbers;
}

int main()
{
    vector<int> arr = {1, 7, 3, 9, 5, 11 };
    segregate_evens_and_odds(arr);

    for (auto &i : arr)
    {
        cout << i << "  ";
    }

    return 0;
}
