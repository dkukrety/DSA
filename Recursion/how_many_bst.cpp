/*
Write a function that returns the number of distinct binary
search trees that can be constructed with n nodes.
For the purpose of this exercise, do solve the problem using
recursion first even if you see some non-recursive approaches.

Logic is:
for a n number ...say it is in form of array[1,2,3,...i....n-2,n-1,n]
if i select position i, how many bst can be there if we take
"i" as root position.

Suppose number of bst when we take i as root is x,
then total bst when i --> 1 to n is
sum = sum + x;

here am assuming that x is the number of bst when we take i as root.

now what is x?

x bst at root i is --> number_of_bst(0..to ..i-1) * number_of_bst( i+1 to n)

so it becomes sum = sum + how_many_bsts(i-1)*how_many_bsts(n-i);
above is similar to question, like if i have 3 shirts and 4 pants, then how many
cobination i can have, it will be 4*3 == 12..

so when i == 1 for n == 3
sum = sum + how_many_bsts(0)*how_many_bsts(2);

time complexity is nth catalan number, which is exponential

1/1+n * 2n!/n!n!

hieght is o(n), so stack space is o(n)
*/
long long how_many_bsts(int n)
{
    // Write your code here.
    if (n == 0 || n == 1)
        return 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += how_many_bsts(i - 1) * how_many_bsts(n - i);
    }
    return ans;
}