#include <bits/stdc++.h>
using namespace std;

// Example Question - Fibbonacci Sequence
int solve(int n, vector<int> &dp)
{
    // base case
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;

    // step-3 // base case ke baad ,check if ans already exist or not
    // agar hai toh return dp[n] there
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step-2
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}
// 1-D dp  solution
// 1D dp  lenght  1

int fib(int n)
{

    // return solve(n);

    // step-1
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

int main()
{

    int n = 4;
    int ans = fib(n);
    cout << ans << endl;

    return 0;
}