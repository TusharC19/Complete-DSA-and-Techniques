# include<bits/stdc++.h>
using namespace std; 

const int m = 1e9+7;

void nextGreaterElement(vector<int>&nums,vector<int>&ans){
    int n = nums.size();
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        int ele = nums[i];

        while(!st.empty() && st.top()<ele) st.pop();

        if(st.empty()){
            ans.push_back(-1);
            st.push(ele);
        }
        else{
            ans.push_back(st.top());
            st.push(ele);
        }
    }
}


int main(){
    vector<int>nums = {8,4,6,2,3};
    vector<int>ans;
    nextGreaterElement(nums,ans);
    reverse(ans.begin(),ans.end());
    
    for(int i:ans) cout<<i<<" ";



 return 0;
}