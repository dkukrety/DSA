/*

we have to choose k numbers from n numbers.

helper(n,k,slate,result)
{
    if(k == 0)
    {
        result.push_back(slate)
        return result;
    }
for(choice i --> k)
    slate.push_back(n)
    helper(n-1,i+1,slate,result)
    slate.pop_back();
}
*/

/*

Another method is use pascal traingal analogy

(n,k) = (n-1,k) + (n-1, k - 1)

here is base case is
(n,0) will be 1
(n,k==n) or "n == k" is also 1
if(k == 0 or k == n) return 1;

so code will be

helper(n,k)
{
    vector<vector<int>> table(n,k,-1)
    for(i=0 to k)
      table[n][n] = 1;

    for(i --> 0 to n)
      tab[n][0] = 1;

    for(row : 2 -->n)
    for(col :  1--> min(row,k) )
     tab[row][col] = tab[row-1][col-1] + tab[col-1][k]

}

*/

/*

N Choose R
Consider you have n distinct elements, find the number of ways through which you can choose exactly r number of elements out of those.

Example One
{
"n": 5,
"r": 3
}
Output:

10
There is a set of 5 elements {1, 2, 3, 4, 5}. You need to pick a subset of size 3. Eligible subsets are {1, 2, 3}, {1, 2, 4}, {1, 2, 5}, {1, 3, 4}, {1, 3, 5}, {1, 4, 5}, {2, 3, 4}, {2, 3, 5}, {2, 4, 5}, {3, 4, 5}. There are 10 subsets of size 3.

Example Two
{
"n": 3,
"r: 5
}
Output:

0
There is a set of 3 elements {1, 2, 3}. You need to pick a subset of size 5. Which is not possible, that's why the answer is 0.

Notes
Here the answer can be very big, find it modulo 109 + 7.

Constraints:

0 <= n, r <= 1000
*/
const int P = 1000000007;

int ncr(int n, int r)
{
  // Write your code here.
  static vector<std::vector<int>> table(n + 1, std::vector<int>(r + 1));
  if (r > n)
  {
    return 0;
  }
  if (r == 0 || n == r)
  {
    return 1;
  }
  // cout<<"herer"<<endl;
  for (int i = 0; i <= n; i++)
  {
    table[i][0] = 1;
  }

  for (int j = 0; j <= r; j++)
  {
    table[j][j] = 1;
  }
  // cout<<"herer2"<<endl;
  int i = 0;
  int j = 0;
  for (i = 2; i <= n; i++)
  {
    // cout<<"herer3"<<endl;

    for (j = 1; j <= min(r, i); j++)
    {
      if (i == j)
        continue;

      table[i][j] = (table[i - 1][j] + table[i - 1][j - 1]) % P;
    }
  }

  return table[n][r];
}


