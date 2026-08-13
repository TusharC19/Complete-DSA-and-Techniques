# include<bits/stdc++.h>
using namespace std; 

class Solution {
public:

    int dp[2][101][101];

    int solve(int p,int i,int M,vector<int>&a){
        int n=a.size();
        if(i>=n) return 0;

        int stones=0;
        int result=(p==1)?-1:1e9;

        for(int x=1;x<=min(n-i,2*M);x++){
            stones+=a[i+x-1];

            if(p==1){
                result=max(result,stones+solve(0,i+x,max(M,x),a));
            }
            else{
                result=min(result,solve(1,i+x,max(M,x),a));
            }

        }

        return result;

    }

    int memo(int p,int i,int M,vector<int>&a){
        int n=a.size();
        if(i>=n) return 0;

        if(dp[p][i][M]!=-1) return dp[p][i][M];

        int stones=0;
        int result=(p==1)?-1:1e9;

        for(int x=1;x<=min(n-i,2*M);x++){
            stones+=a[i+x-1];

            if(p==1){
                result=max(result,stones+solve(0,i+x,max(M,x),a));
            }
            else{
                result=min(result,solve(1,i+x,max(M,x),a));
            }

        }

        dp[p][i][M] = result;
        return dp[p][i][M];

    }


    int stoneGameII(vector<int>& piles) {
        // recursion: solve for alice
        int person=1,ind=0,M=1;
        memset(dp,-1,sizeof(dp));
        return memo(person,ind,M,piles);
    }
};


int main(){
    
 return 0;
}