# include<bits/stdc++.h>
using namespace std; 

vector<int> transformArray(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        if(nums[i]%2 == 0) nums[i] = 0;
        else nums[i] = 1;
    }
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        ans[i]=nums[i];
    }

    return ans;
}

int main(){
    vector<int>n= {4,3,2,1};
    auto ans = transformArray(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }



 return 0;
}