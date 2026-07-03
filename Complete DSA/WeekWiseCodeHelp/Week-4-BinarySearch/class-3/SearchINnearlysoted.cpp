# include<bits/stdc++.h>
using namespace std; 


int applyBS(vector<int>&arr,int target){
    int n =arr.size();
    int s=0,e=n-1,mid;

    while(s<=e){
        mid = s+(e-s)/2;

        if(arr[mid]==target) return mid;
        else if(arr[mid-1]==target) return mid-1;
        else if(arr[mid+1]==target) return mid+1;

        if(arr[mid]>target) e = mid-2;
        else s = mid+2;
    }
    return -1;
}


int main(){

    // arr[] = {3,10,20,40,50,70,80}
    vector<int>arr = {10,3,40,20,50,80,70}; int target = -4;
    // output = 2 index pe hai

    int ans = applyBS(arr,target);
    cout<<ans<<endl;



    
 return 0;
}