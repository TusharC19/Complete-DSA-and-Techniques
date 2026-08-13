# include<bits/stdc++.h>
using namespace std; 


int dp[101][101];
class Solution {
public:
// vector<vector<int>>& obstacleGrid
    int rec(int i, int j,vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        if (i == m - 1 && j == n - 1) return 1;
        if(g[i][j]==1) return 0;

        int right = (j + 1 < n) ? rec(i, j + 1,g) : 0;
        int down = (i + 1 < m) ? rec(i + 1, j,g) : 0;

        return right + down;
    }

    int memo(int i, int j,vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        if (i == m - 1 && j == n - 1)
            return 1;
        if(g[i][j]==1) return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = (j + 1 < n) ? memo(i, j + 1,g) : 0;
        int down = (i + 1 < m) ? memo(i + 1, j, g) : 0;

        dp[i][j] = right + down;
        return dp[i][j];
    }

    int tabu(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1) dp[i][j]=0;
            }
        }
        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue; // skip destination
                int right = (j + 1 < n) ? dp[i][j + 1] : 0;
                int down = (i + 1 < m) ? dp[i + 1][j] : 0;
                dp[i][j] = right + down;
            }
        }
        return dp[0][0];
    }

    int uniquePaths(vector<vector<int>>& g) {
        // vector<vector<int>>vis(m,vector<int>(n,0));
        // memset(dp,-1,sizeof(dp));
        int ans = tabu(g);
        return ans;
    }
};

int main(){
    
 return 0;
}