# include<bits/stdc++.h>
using namespace std; 


// first using min heap
int kthSmallestElement(vector<int>&nums,int k){
    int n = nums.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++) pq.push(nums[i]);
    for(int i=0;i<k;i++) pq.pop();
    return pq.top();

}

int kthSmallestElement_MAX_HEAP(vector<int>&nums,int k){
    int n = nums.size();
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        pq.push(nums[i]);
        if(pq.size()>k) pq.pop();
    }
    
    return pq.top();

}

int kthlargestElement_Using_MIN_HEAP(vector<int>&nums,int k){
    int n = nums.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(nums[i]);
        if(pq.size()>k) pq.pop();
    }
    return pq.top();

}

int kthlargestElement_Using_MAX_HEAP(vector<int>&nums,int k){
    int n = nums.size();
    priority_queue<int>pq;
    for(int i=0;i<n;i++) pq.push(nums[i]);
    for(int i=0;i<k-1;i++) pq.pop();
    return pq.top();

}




int main(){
    vector<int>nums = {1,6,10,8,4,3};
    int k = 3;
    auto ans = kthlargestElement_Using_MAX_HEAP(nums,k);
    cout<<ans<<endl;

 return 0;
}