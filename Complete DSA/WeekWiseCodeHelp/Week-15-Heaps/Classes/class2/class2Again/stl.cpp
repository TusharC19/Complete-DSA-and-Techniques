# include<bits/stdc++.h>
using namespace std; 

void printHeapMax(priority_queue<int>&pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

void printHeapMin(priority_queue<int,vector<int>,greater<int>>pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

// don't get confuse it is easy 

// max heap - sc = o(K)
int kthsmallestMAXheap(vector<int>&a,int k){
    priority_queue<int>pq;
    int n = a.size();
    for(int i=0;i<n;i++){
        pq.push(a[i]);

        // now it automatically rearrage the largest element at top
        if(pq.size()>k) pq.pop();
    }

    return pq.top();
}


int kthLargestMINheap(vector<int>&a,int k){
    int n = a.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);

        if(pq.size()>k) pq.pop();
    }

    return pq.top();

}


int main(){
    // priority_queue<int>pq;
    // pq.push(10);
    // pq.push(20);
    // pq.push(30);
    // pq.push(40);

    // printHeap(pq);

    // priority_queue<int,vector<int>,greater<int>>pq;
    // pq.push(10);
    // pq.push(20);
    // pq.push(30);
    // pq.push(40);
    // pq.push(50);
    // pq.push(60);

    vector<int>a = {4,3,2,6,5,1};
    int k = 3;
    int kthSmallestElement = kthsmallestMAXheap(a,k);
    cout<<kthSmallestElement<<endl;

    









 return 0;
}