# include<bits/stdc++.h>
using namespace std; 

int houseRobber(vector<int>&nums, int s,int i){
        // base case
        if(i>=s) return 0;
        // ek case mera
        int rob = nums[i];
        // include
        int include = rob + houseRobber(nums,s,i+2);
        // exclude
        int exclude = 0 + houseRobber(nums,s,i+1);

        int moneyrob = max(include,exclude); 

        return moneyrob;

    }
    int rob(vector<int>& nums) {
        int index = 0;
        int ans = houseRobber(nums,nums.size(),index);
        return ans;
    }

int solve(vector<int>& nums,int s,int idx){
    if(idx>=s) return 0;

    // ek case mera 
    int moneyrob = nums[idx];
    // include
    int include = moneyrob + solve(nums,s,idx+1);
    // exclude
    int exclude = 0 + solve(nums,s,idx+1);
    int finalans = max(include,exclude);
    return finalans;

}

int robbed(vector<int>& nums) {
    int n=nums.size();
    int idx = 0;
    int ans = solve(nums,nums.size(),idx);
    return ans;
}


int main(){
    vector<int>nums = {1,2,3,1};
    int ans = robbed(nums);
    cout<<ans<<endl;
 return 0;
}