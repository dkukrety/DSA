/*
Asymptotic complexity in terms of input integer `n`:
* Time: O(n).
* Auxiliary space: O(1).
* Total space: O(1).
*/

int find_fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int super_previous = 0;
    int previous = 1;
    for (int i = 2; i <= n; i++)
    {
        int current = super_previous + previous;
        super_previous = previous;
        previous = current;
    }
    return previous;
}

// Using recursion and memonization.

int find_fibonacci(int n)
{
    // Write your code here.
    static vector<int> fib(n + 1, -1);
    if (fib[n] != -1)
        return fib[n];

    if (n == 0 || n == 1)
    {
        fib[n] = n;
        return fib[n];
    }

    fib[n] = find_fibonacci(n - 1) + find_fibonacci(n - 2);
    return fib[n];
}
