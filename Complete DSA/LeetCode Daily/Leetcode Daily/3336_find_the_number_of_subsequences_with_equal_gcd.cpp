# include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    typedef long long ll;
    const int M = 1e9 + 7;

    int dp[202][202][202];

    int gcd1(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int tabu(vector<int>& a) {
        int n = a.size();
        memset(dp, 0, sizeof(dp));

        // Base case
        for (int g1 = 0; g1 < 202; g1++) {
            for (int g2 = 0; g2 < 202; g2++) {
                if (g1 == g2 && g1 != 0)
                    dp[n][g1][g2] = 1;
                else
                    dp[n][g1][g2] = 0;
            }
        }

        // Bottom-up DP
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int g1 = 201; g1 >= 0; g1--) {
                for (int g2 = 201; g2 >= 0; g2--) {
                    int s1 = dp[ind + 1][gcd(g1, a[ind])][g2];
                    int s2 = dp[ind + 1][g1][gcd(g2, a[ind])];
                    int skip = dp[ind + 1][g1][g2];

                    dp[ind][g1][g2] = (0LL + s1 + s2 + skip) % M;
                }
            }
        }

        return dp[0][0][0];
    }

    int memo(int ind, int g1, int g2, vector<int>& a) {
        int n = a.size();
        if (ind == n) {
            if (g1 == g2 && g1 != 0 && g2 != 0)
                return 1;
            return 0;
        }

        if (dp[ind][g1][g2] != -1)
            return dp[ind][g1][g2];

        int s1 = memo(ind + 1, gcd(g1, a[ind]), g2, a);

        int s2 = memo(ind + 1, g1, gcd(g2, a[ind]), a);

        int skip = memo(ind + 1, g1, g2, a);

        // dp[ind][g1][g2] = ((s1+s2)%M+skip)%M;
        dp[ind][g1][g2] = (0LL + s1 + s2 + skip) % M;

        return dp[ind][g1][g2];
    }

    int subsequencePairCount(vector<int>& a) {
        int n = a.size();
        // memset(dp,-1,sizeof(dp));

        // int ans=memo(0,0,0,a);
        int ans = tabu(a);
        return ans;
    }
};

int main(){
    
 return 0;
}