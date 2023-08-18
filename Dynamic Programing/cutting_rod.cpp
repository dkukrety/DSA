#include <iostream>
#include <vector>
using namespace std;

/*
Cutting rod..

price = []
len = []

formula is
max = 0
if(len == 1)
{
    return price[0];
}
for(cut 1-->len)
{
sum = price[cut]+cutting_rod(len-cut);
maxSum = max(maxSum,sum);
int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 }

}
*/
// Not sure whu below code is not working...something wrong...

int cutting_rod(int len, vector<int> arr)
{
    static int maxPrice = 0;

    if (len == 1)
    {
        return arr[0];
    }

    for (int cut = 1; cut < len; cut++)
    {
        maxPrice = max(maxPrice, arr[cut - 1] + cutting_rod(len - cut, arr));
        // maxPrice = max(price, maxPrice);
    }

    return maxPrice;
}

int main()
{
    vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
    // vector<int> arr = {1, 5, 8};
    int len = arr.size();
    cout << cutting_rod(len, arr);
}