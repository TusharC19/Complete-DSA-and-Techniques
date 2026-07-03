# include<bits/stdc++.h>
using namespace std; 

void sortSwap(vector<int>&a){
    int n=a.size();
    int i=0;
    while(i<n){
        int idx = a[i]-1;
        if(a[i] !=a[idx]) swap(a[i],a[idx]);
        else i++;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        if(a[i] != i+1) cout<<i+1<<" ";
    }

}


int main(){

    // vector<int>arr = {1,3,5,3,4};  
    vector<int>arr = {5,3,3,3,1};   

    sortSwap(arr);
 return 0;
}