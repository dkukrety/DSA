/*
Given a base a and an exponent b. Your task is to find ab.
The value could be large enough. So, calculate ab % 1000000007.

Example
{
"a": 2,
"b": 10
}
Output:

1024
Notes
Constraints:

0 <= a <= 10^4
0 <= b <= 10^9
a and b together won't be 0

Solution is bit of mathematical and using recursion with optimization..

so basically we need to find a^b%1000000007. This is because long long limit is 10^18 only
so if a=10^4 and b =10^9, long long will easily overflow.

if mod = 1000000007
so now a^b%mod == (a%mod*b%mod)%mod, now this is easy to calculate in long long variable.

Next we will try to solve this recursively.

so 10^36 == 10^18 * 10^18
10^18 == 10^9 * 10^9...and so on...

so we will use above logic to calculate.

so in this way time complexity will be log(b) and space complexity for stack is also log(b)+constant space for temp.

*/
long long mod = 1000000007;
int calculate_power(long long a, long long b)
{
    // Write your code here.
    if (b == 0)
        return 1;
    if (b == 1)
        return a % mod;
    long long temp = calculate_power(a, b / 2);
    a = a % mod;
    if (b % 2 == 0)
    {
        return (temp * temp) % mod;
    }
    else
    {
        return (((temp * temp) % mod) * a) % mod;
    }
}