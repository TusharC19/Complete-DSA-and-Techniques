# include<bits/stdc++.h>
using namespace std; 

int canCompleteCircuit(vector<int>&gas,vector<int>&cost){
    int start=0;
    int balance=0;
    int deficit=0;
    int n = gas.size();int m = cost.size();

    for(int i=0;i<n;i++){
        if(gas[i]<cost[i]){
            deficit += abs(gas[i]-cost[i]);
            start = i+1;
        }
        else{
            // not deficit 
            balance += abs(gas[i]-cost[i]);
        }

    }
    if(balance-deficit >= 0) return start;
    else return -1;
}

int main(){
    vector<int>gas = {1,2,3,4,5};
    vector<int>cost = {3,4,5,1,2};

    int ans = canCompleteCircuit(gas,cost);
    cout<<ans<<endl;

    
 return 0;
}