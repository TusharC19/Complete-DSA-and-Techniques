# include<bits/stdc++.h>
using namespace std; 

bool twoSum(vector<int>&arr,int target){
    int l = 0,h = arr.size();

    while(l<h){
        if(arr[l] + arr[h] == target) return true;
        else l++,h--;
    }
}

int main(){
    
    vector<int>arr = {1,4,45,6,10,8};
    sort(arr.begin(),arr.end());
    auto ans = twoSum(arr,16);
    if(ans) cout<<"present"<<endl;
    else cout<<"not present"<<endl; 
    return 0;
}