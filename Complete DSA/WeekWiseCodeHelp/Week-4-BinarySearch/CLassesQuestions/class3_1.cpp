# include<bits/stdc++.h>
using namespace std; 


int BS(vector<int>&a,int target){
    int n = a.size();
    int s=0,e=n-1,mid;

    while(s<=e){
        mid = s + (e-s)/2;

        if(a[mid]==target){
            return mid;
        }

        else if(mid+1<n && a[mid+1]==target ){
            return mid+1;
        }

        else if(mid-1>=0 && a[mid-1]==target ){
            return mid-1;
        }
        else if(target>a[mid]) s = mid+2;

        else e = mid-2;
    }
    return -1;
}


int main(){
    vector<int>a = {10,3,40,20,50,80,70};
    int target = 40;
    int ans = BS(a,target);
    cout<<ans<<endl;
 return 0;
}