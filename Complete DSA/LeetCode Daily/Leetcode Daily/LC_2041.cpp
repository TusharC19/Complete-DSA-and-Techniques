# include<bits/stdc++.h>
using namespace std; 

// Hidden question ki sabhi pairs ka end 0 hai ya nhi
// Brute Approach - bitmasking - O(N3)
bool isNiceArr(vector<int>&nums,int s,int e){
    int mask = 0;
    for(int i=s;i<=e;i++){
        int element = nums[i];
        // 1 mask & nums[i];
        if(mask&element == 0) mask = mask | element;
        else return false;
    }
    // yha tak aya matlab har har ekk pair ka " & " is 0;
    return true;
}

int brute(vector<int>&nums){
    int n = nums.size();
    int maxLength = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(isNiceArr(nums,i,j)){
                maxLength = j-i+1;
            }
            else break; // breaking the loop

        }
    }

    return maxLength;

}

// Better Approach - O(N2)
int better(vector<int>&nums){
    int n = nums.size();
    int maxLength = 1;
    for(int i=0;i<n;i++){
        int mask = 0;
        for(int j=i;j<n;j++){
            if((mask & nums[j]) == 0){
                maxLength = max(maxLength,j-i+1);
                mask |= nums[j];
            }
            else break; // breaking the loop

        }
    }

    return maxLength;
}


// OPTIMAL APPROACH - sliding window - O(N)
int optimal(vector<int>&nums){
    int n = nums.size();
    int i=0,j=0;
    int mask = 0;
    int maxLength = 1;

    while(j<n){
        // if mask & nums[j] != 0
        // shrink karte rhna padega

        while(mask & nums[j] != 0){
            // keep shrinking
            mask = (mask^nums[i]);
            i++;
        }

        maxLength = max(maxLength,j-i+1);
        mask = (mask | nums[j]);
        j++;

    }
    return maxLength;
}



int main(){
    vector<int>nums = {1,3,8,48,10};
    // cout<<isNiceArr(nums,0,3)<<endl;

    // int ans1 = brute(nums);
    // cout<<ans1<<endl;

    int ans2 = better(nums);
    cout<<ans2<<endl;

    int ans3 = optimal(nums); 
    cout<<ans3<<endl;






 return 0;
}