# include<bits/stdc++.h>
using namespace std; 


int sumHighestAndLowestFrequency(vector<int>& nums) {
        unordered_map<int,int>hash;

        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto i:hash){
            if(maxi<i.second) maxi=i.second;
            if(mini>i.second) mini = i.second;
        }
        cout<<maxi<<" "<<mini<<endl;
        return maxi-mini;
}

int main(){
    vector<int>nums = {1,2,2,3,3,3};
    int ans = sumHighestAndLowestFrequency(nums);
    cout<<ans<<endl;
    
 return 0;
}