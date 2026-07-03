# include<bits/stdc++.h>
using namespace std; 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

int mincoinsUsed(vector<int>coins,int amt){
    // base case
    if(amt==0) return 0;

    int mincoinuse = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int coin = coins[i];

        if(coin<=amt){

            int recAns = mincoinsUsed(coins,amt-coin);
            
            if(recAns != INT_MAX){
                int coinsUsed = 1+ recAns;
                mincoinuse = min(mincoinuse,coinsUsed);
            }
        }
    }
    return mincoinuse;
}



int coinChange(vector<int>coins,int amt){

    int ans = mincoinsUsed(coins,amt);
    if(ans == INT_MAX) return -1;
    else return ans;
}


int main(){
    vector<int>coins = {1,2,5};
    int amt= 11;
    int ans = coinChange(coins,amt);
    cout<<ans<<endl;
    
 return 0;
}