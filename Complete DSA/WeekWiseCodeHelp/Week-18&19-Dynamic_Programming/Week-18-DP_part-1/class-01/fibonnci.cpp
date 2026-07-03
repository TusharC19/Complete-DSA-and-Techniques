# include<bits/stdc++.h>
using namespace std; 

int fib(int n){
    if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}


int fibMemo(int n,vector<int>&dp){
    if(n<=1) return n;
    
    // step 3
    if(dp[n] != -1) return dp[n];
    
    // step2-store in dp array and return dp array
    dp[n] = fibMemo(n-1,dp) + fibMemo(n-2,dp);
    return dp[n];
    
}

int fibTab(int n){
    // step1 
    vector<int>dp(n+1,-1);
    
    
    // step 2
    dp[1] = 1;
    dp[0] = 0;
    
    // step 3
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}



int fibOptimisation(int n){
    
    if(n<=1) return n;
    
    // step 1
    int prev = 0;
    int curr = 1;
    
    // step2
    for(int i=2;i<=n;i++){
        int ans = prev + curr;
        prev = curr;
        curr = ans;
    }
    
    // step 3
    return curr;
    
}
int main(){
    
    // By recursion
    int n = 5;
    // cout<<fib(6)<<endl;
    
    // by memoisation
    // step1
    vector<int>dp(n+1,0);
    // int ans = fibMemo(n,dp);
    // cout<<ans<<endl;
    
    
    // using tabulation
    // cout<<fibTab(n)<<endl;
    
    // using Optimisation
    cout<<fibOptimisation(n)<<endl;
    
    
 return 0;
}

