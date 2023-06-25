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

// Do it with using Lomutos partitioning logic
vector<int> segregate_evens_and_odds_Lomutos(vector<int> &numbers)
{
    int evenIndex = -1;
    int oddIndex = 0;

    while (oddIndex < numbers.size())
    {
        if (numbers[oddIndex] % 2 == 0)
        {
            evenIndex++;
            swap(numbers[evenIndex], numbers[oddIndex]);
        }
        oddIndex++;
    }

    return numbers;
}

int main()
{
    vector<int> arr = {1, 7, 3, 9, 2, 4, 5, 11};
    segregate_evens_and_odds_Lomutos(arr);

    for (auto &i : arr)
    {
        cout << i << "  ";
    }

    return 0;
}
