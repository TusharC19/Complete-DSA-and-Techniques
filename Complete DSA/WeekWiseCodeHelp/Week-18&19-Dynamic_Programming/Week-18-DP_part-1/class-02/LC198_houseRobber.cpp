# include<bits/stdc++.h>
using namespace std; 

int rob(vector<int>&nums,int i){
    if(i>=nums.size()) return 0;

    int include = nums[i] + rob(nums,i+2);
    int exclude = 0 + rob(nums,i+1);
    int finalAns = max(include,exclude);
    return finalAns;
}

int memoisation(vector<int>&nums,int i,vector<int>&dp){
    if(i>=nums.size()) return 0;

    // step 2
    if(dp[i] != -1) return dp[i];

    // step3
    int include = nums[i] + memoisation(nums,i+2,dp);
    int exclude = 0 + memoisation(nums,i+1,dp);

    dp[i] = max(include,exclude);
    return dp[i];
}

int Tabulation(vector<int>&nums,int idx){
    int n = nums.size();
    // step 1
    vector<int>dp(n+2,-1);

    // step 2
    dp[n] = 0;
    // dp[n+1] = 0;
    

    // step 3 reverse loop and copy paste
    for(int i=n-2;i>=0;i--){
        int include = nums[i] + dp[i+2];
        int exclude = 0 + dp[i+1];
        dp[i] = max(include,exclude);   
    }

    return dp[idx];
}


int optimisation(vector<int>&nums,int idx){
    int n = nums.size();
    // step 1
    vector<int>dp(n+2,-1);

    // step 2
    int next1 = 0;
    int next2 = 0;
    
    // step 3 reverse loop and copy paste
    for(int i=n-2;i>=0;i--){
        
        int include = nums[i] + next2;
        int exclude = 0 + next1;
        int curr = max(include,exclude);
        next2 = next1;
        next1 = curr;

    }

    return next1;

  
}


int main(){
    vector<int>nums = {1,2,3,1};
    int idx = 0;
    int n  = nums.size();
    // int ans = rob(nums,idx);
    // cout<<ans<<endl;

    // memoisation
    // step 1
    vector<int>dp(n+1,-1);
    // cout<<memoisation(nums,idx,dp)<<endl;

    // Tabulation
    // cout<<Tabulation(nums,idx)<<endl;

    // Optimisaton
    cout<<optimisation(nums,idx)<<endl;

 return 0;
}