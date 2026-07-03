#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int amount)
{

    if (amount == 0)
        return 0;

    int minCoinCnt = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];

        if (coin <= amount)
        {

            int recursionAns = solve(coins, amount - coin);

            if (recursionAns != INT_MAX)
            {
                int coinsUsed = 1 + recursionAns;

                minCoinCnt = min(minCoinCnt, coinsUsed);
            }
        }
    }

    return minCoinCnt;
}

// using 1d DP
int memo(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
        return 0;

    // step3: if already ans exists then return it
    if (dp[amount] != -1)
        return dp[amount];

    int minCoinCnt = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];

        if (coin <= amount)
        {

            int recursionAns = memo(coins, amount - coin, dp);

            if (recursionAns != INT_MAX)
            {
                int coinsUsed = 1 + recursionAns;

                minCoinCnt = min(minCoinCnt, coinsUsed);
            }
        }
    }

    // step2: store in and return from dp array
    dp[amount] = minCoinCnt;
    return dp[amount];
}

// using 1d DP
int tabulation(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);

    // step2:
    dp[0] = 0;

    // step3: reverse loop and change recursive call to dp
    // since dp[0] ke liye already solved
    for (int amt = 1; amt <= amount; amt++)
    {
        int minCoinCnt = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int coin = coins[i];

            if (coin <= amt)
            {

                int recursionAns = dp[amt - coin];

                if (recursionAns != INT_MAX)
                {
                    int coinsUsed = 1 + recursionAns;
                    minCoinCnt = min(minCoinCnt, coinsUsed);
                }
            }
        }
        // dp me store and return
        dp[amt] = minCoinCnt;
    }

    // final return
    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    // by recursion
    // int ans = solve(coins, amount);

    // By using topdown - 1d DP
    // step 1:
    // amount + 1 to include 11 also - since 0 based indexing
    // vector<int> dp(amount + 1, -1);
    // int ans = memo(coins, amount, dp);

    // Using tabulation
    int ans = tabulation(coins, amount);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int ans = coinChange(coins, amount);
    cout << ans << endl;

    return 0;
}