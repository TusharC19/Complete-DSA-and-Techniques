#include <bits/stdc++.h>
using namespace std;

// Example Question - Fibbonacci Sequence
int solveUsingTopDown(int n, vector<int> &dp)
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
    dp[n] = solveUsingTopDown(n - 1, dp) + solveUsingTopDown(n - 2, dp);
    return dp[n];
}
// 1-D dp  solution
// 1D dp  lenght  1

int solveUsingTabulation(int n){

    // step-1: create dp arr
    vector<int>dp(n+1,-1);

    // step-2:
    dp[0] = 0;
    if(n==0) return 0;
    dp[1] = 1;

    // step-3:
    // recursion -> n to 0
    // reverse -> 0 to n

    for(int i=2; i<=n;i++){
        // copy paste
        dp[i] = dp[i-1] + dp[i-2];

    }

    // answer return - at the end dp[n] hi ans hoga
    return dp[n];

}


int fib(int n)
{

    return solveUsingTabulation(n);
}

int main()
{

    int n = 0;
    int ans = fib(n);
    cout << ans << endl;

    return 0;
}