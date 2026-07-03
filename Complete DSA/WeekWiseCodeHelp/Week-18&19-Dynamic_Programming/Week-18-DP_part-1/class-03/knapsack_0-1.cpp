# include<bits/stdc++.h>
using namespace std; 


int solve(vector<int> &val, vector<int> &wt,int capacity,int idx){
    // we are travelling in reverse order in array
    // n-1 to 0 idx
    if(idx == 0){
        // first element
        if(wt[idx]<=capacity){
            return val[idx]; // i.e include this value
        }
        else{
            // exclude this val - i.e include nothing
            return 0;
        }
    }

    int include = 0;
    // here not need to check capacity<=0 or not
    if(wt[idx]<=capacity){
        include = val[idx] + solve(val,wt,capacity-wt[idx],idx-1);
    }
    int exclude = 0 +  solve(val,wt,capacity,idx-1);

    int finalAns = max(include,exclude);
    return finalAns;

}

int memo(vector<int> &val, vector<int> &wt,int capacity,int idx,vector<vector<int>>&dp){
    if(idx == 0){
        // first element
        if(wt[0]<=capacity){
            return val[0]; // i.e include this value
        }
        else{
            // exclude this val - i.e include nothing
            return 0;
        }
    }

    if(dp[capacity][idx] != -1) return dp[capacity][idx];

    int include = 0;
    // here not need to check capacity<=0 or not
    if(wt[idx]<=capacity){
        include = val[idx] + memo(val,wt,capacity-wt[idx],idx-1,dp);
    }
    int exclude = 0 +  memo(val,wt,capacity,idx-1,dp);

    dp[capacity][idx] = max(include,exclude);
    return dp[capacity][idx];
}

int tabu(vector<int> &val, vector<int> &wt,int capacity,int idx){
    int n = val.size();
    vector<vector<int>>dp(capacity+1,vector<int>(n,0));

    // step 2: base case analyze
    // dp arr ke andar mein base case ya initial state maintain kar rha hu
    // taki ise use karke ake ke ans mein build kar saku

    for(int w=wt[0];w<=capacity;w++){
        // bewkoof code
         if(wt[0]<=capacity)
            dp[w][0] = val[0]; // i.e include this value
    }


    // step 3:
    // row ka loop
    for(int weight=0;weight<=capacity;weight++){
        for(int i=1;i<=n-1;i++){
                int include = 0;
                // here not need to check capacity<=0 or not
                if(wt[i]<=weight){
                    include = val[i] + dp[weight-wt[i]][i-1];
                }
                int exclude = 0 +  dp[weight][i-1];

                dp[weight][i] = max(include,exclude);
        }
    }

    return dp[capacity][idx];

}


int optimisation(vector<int> &val, vector<int> &wt,int capacity,int idx){

}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    int capacity = W;
    int idx = n-1;
    // return solve(capacity,val,wt,idx);

    // memo - 2D DP
    // row depend on capacity and col on size n
    // vector<vector<int>>dp(capacity+1,vector<int>(n,-1));
    // return memo(val,wt,capacity,idx,dp);

    return tabu(val,wt,capacity,idx);
        
}

int main(){
    vector<int>val = {1,2,3};
    vector<int>wt = {4,5,1};
    int W = 3;
    int ans = knapsack(W,val,wt);
    cout<<ans<<endl;

 return 0;
}