# include<bits/stdc++.h>
using namespace std; 

bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
     
    int n = nums.size();
    int row = queries.size();
    int col = queries[0].size();

    // difference Array Technique 
    // 1. diff array
    vector<int>diff(n+1,0);

    // traverse int queries matrix
    for(int i=0;i<row;i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int val = queries[i][2];

        diff[l] += val;
        diff[r+1] -= val;

        for(int i: diff) cout<<i<<" ";
        cout<<endl;
        
    }

    // 2. Prefix sum of diff array
    for(int i=1;i<n;i++){
        diff[i] = diff[i] + diff[i-1];
    }

    // 3. Check ki agar nums[i]>no.of operation apply se jyada hua toh return false wrna true
    for(int i=0;i<n;i++){
        if(nums[i]>diff[i]) return false;
    }
    return true;

}


int main(){
    
    vector<int>nums = {3,2,2,1};
    vector<vector<int>>q = { {1,3} ,{0,2}};

    bool ans = isZeroArray(nums,q);
    
    if(ans) cout<<"true"<<endl;
    else cout<<"false"<<endl;


    // for(int i: nums) cout<<i<<" ";
    // cout<<endl;

    // int sum = accumulate(nums.begin(),nums.end(),0);
    // cout<<sum<<endl;





 return 0;
}