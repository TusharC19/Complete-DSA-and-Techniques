#include <bits/stdc++.h>
using namespace std;


int solveMemo(string &s, int k, int i,vector<int>&dp){
    if (i < 0) return 0;

    // step2;
    if(dp[i] != 0) return dp[i];

    long long val = (s[i] - '0') * (1 << (s.size() - i - 1));
    int inclen = 0;
    if (s[i]=='0' || val <= k)
    {
        inclen = 1 + solveMemo(s, k - val, i - 1,dp);
    }
    int exclen = 0 + solveMemo(s, k, i - 1,dp);

    dp[i] = max(inclen, exclen);
    return dp[i];

}


int solveRec(string &s, int k, int i)
{
    if (i < 0) return 0;

    long long val = (s[i] - '0') * (1 << (s.size() - i - 1));
    int inclen = 0;
    if (s[i]=='0' || val <= k)
    {
        inclen = 1 + solveRec(s, k - val, i - 1);
    }
    int exclen = 0 + solveRec(s, k, i - 1);

    int finalAns = max(inclen, exclen);
    return finalAns;
}

int longestSubsequence(string s, int k)
{
    int n = s.size();
    int i = n - 1;
    vector<int>dp(n+1,0);
    int ans = solveMemo(s, k, i,dp);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s = "00101001";
    int k = 1;
    int ans = longestSubsequence(s, k);
    cout << ans << endl;

    return 0;
}
