# include<bits/stdc++.h>
using namespace std; 


int dp[101][101];
class Solution {
public:
    int rec(int i, int j, int m, int n) {
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if (i == m - 1 && j == n - 1) return 1;

        int right = rec(i, j + 1, m, n) ;
        int down = rec(i + 1, j, m, n) ;

        return right + down;
    }

    int memo(int i, int j, int m, int n) {
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int right = memo(i, j + 1, m, n);
        int down = memo(i + 1, j, m, n);

        dp[i][j] = right + down;
        return dp[i][j];
    }

    int tabu(int m, int n) {
        memset(dp, 0, sizeof(dp));
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
    
    // better way
    int uniquePaths(int m, int n) {
        // Create a 2D array for storing the number of ways to reach each cell
        
        // if we assume that there is 1 way to reach (0,0) from
        // (0,0), so dp[0][0] = 1. also

        // Initialize the first row
        for (int col = 1; col < n; col++) {
            dp[0][col] = 1; // Only one way to reach any cell in the first row
        }

        // Initialize the first column
        for (int row = 1; row < m; row++) {
            dp[row][0] = 1; // Only one way to reach any cell in the first column
        }

        // Fill the rest of the table using the relation:
        // t[i][j] = t[i-1][j] + t[i][j-1]
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The bottom-right cell contains the total number of unique paths
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>>vis(m,vector<int>(n,0));
        // memset(dp,-1,sizeof(dp));
        int ans = tabu(m, n);
        return ans;
    }
};

int main(){
    
 return 0;
}