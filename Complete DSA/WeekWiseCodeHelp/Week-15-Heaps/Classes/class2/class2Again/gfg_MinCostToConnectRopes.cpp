# include<bits/stdc++.h>
using namespace std; 


int minCost(vector<int>& arr) {
    int n = arr.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    int mincost=0;
    while(pq.size() != 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int cost = a + b;
        mincost += cost;
        pq.push(cost);
    }

    return mincost;
        
}

int main(){
    vector<int>a = {4,3,2,6};
    int mincost = minCost(a);
    cout<<mincost<<endl;

 return 0;
}