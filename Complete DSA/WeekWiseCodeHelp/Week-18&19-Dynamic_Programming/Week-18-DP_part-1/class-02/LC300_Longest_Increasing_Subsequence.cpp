# include<bits/stdc++.h>
using namespace std; 

/*
// by using 1D dp
int memoUsing1dDp(vector<int>&nums,vector<int>&dp,int i,int lasteleidx){
    
    if(i>=nums.size()) return 0;

    // step3 - phle se ans stored hai toh return that
    if(dp[i] != 0) return dp[i];

    // step2-store in dp array and return dp array
    int currele = nums[i]; // curr element idx = i
    int include = 0;

    if( lasteleidx == -1 || currele > nums[lasteleidx]){
        // here lastele = nums[lasteleidx]
        include = 1 + lengthOfLIS(nums,i+1,i);
    }
    int exclude = 0 + lengthOfLIS(nums,i+1,lasteleidx);

    dp[i] = max(include,exclude);

    return dp[i];

}
*/

// BY Recursion
int lengthOfLIS(vector<int>&nums,int i,int lasteleidx){
    // int n = nums.size();
    if(i>=nums.size()) return 0;

    int currele = nums[i]; // curr element idx = i
    int include = 0;

    if( lasteleidx == -1 || currele > nums[lasteleidx]){
        // here lastele = nums[lasteleidx]
        include = 1 + lengthOfLIS(nums,i+1,i);
    }
    int exclude = 0 + lengthOfLIS(nums,i+1,lasteleidx);
    // int exclude = 0 + lengthOfLIS(nums,i+1);
    // prevele = currele;
    return max(include,exclude);
}   


// YHA PE 2D DP bnegi
int memo(vector<int>&nums,vector<vector<int>>&dp,int i,int lasteleidx){
    
    if(i>=nums.size()) return 0;

    // step3 - phle se ans stored hai toh return that
    if(lasteleidx != -1 &&  dp[i][lasteleidx] != -1) 
        return dp[i][lasteleidx];


    // step2-store in dp array and return dp array
    int currele = nums[i]; // curr element idx = i
    int include = 0;

    if( lasteleidx == -1 || currele > nums[lasteleidx]){
        // here lastele = nums[lasteleidx]
        include = 1 + memo(nums,dp,i+1,i);
    }
    int exclude = 0 + memo(nums,dp,i+1,lasteleidx);

    dp[i][lasteleidx] = max(include,exclude);

    return dp[i][lasteleidx];

}


int main(){
    // vector<int>nums = {0,1,0,3,2,3};
    vector<int>nums = {10,9,2,5,3,7,101,18};
    int n = nums.size();

    int idx = 0;
    int lasteleidx = -1;
    // int ans = lengthOfLIS(nums,idx,lasteleidx);
    // cout<<ans<<endl;

    // // by 1D Dp
    // vector<int>dp(n+1,-1);
    // cout<<memo(nums,dp,idx,lasteleidx)<<endl;

    // by memoisation
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<memo(nums,dp,idx,lasteleidx)<<endl;

    

    

 return 0;
}