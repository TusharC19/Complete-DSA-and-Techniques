# include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
   
    bool solve(int n){
        if(n==0) return false;

        for(int i=1;i*i<=n;i++){
            if(solve(n-i*i)==false){
                // means Bob can't win
                // so alice wins
                return true;
            }
        }

        return false;
    }

    bool memo(int n,vector<int>&dp){
        if(n==0) return false;
        if(dp[n]!=-1) {
            if(dp[n]==1) return true;
            else return false;
        }


        for(int i=1;i*i<=n;i++){
            if(memo(n-i*i,dp)==false){
                // means Bob can't win
                // so alice wins
                return dp[n] = true;
            }
        }

        return dp[n]= false;
        
    }

    bool winnerSquareGame(int n) {
        vector<int>dp(n+2,-1);
        return memo(n,dp);
    }
};


int main(){
    
 return 0;
}