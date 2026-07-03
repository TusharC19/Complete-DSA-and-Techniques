# include<bits/stdc++.h>
using namespace std; 

int singleNum(vector<int>&nums){
    int ans = 0;
    int n = nums.size();

    for(int i=0;i<n;i++){
        ans = ans^nums[i];
    }
    return ans;

}


int main(){

    vector<int>v = {4,1,2,1,4,5,2};
    int ans = singleNum(v);
    cout<<ans<<endl;
    
 return 0;
}