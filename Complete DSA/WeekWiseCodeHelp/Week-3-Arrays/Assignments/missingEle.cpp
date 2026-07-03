# include<bits/stdc++.h>
using namespace std; 

void missingInd(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int index= abs(arr[i]);
        if(arr[index-1] >0) arr[index-1] *= -1;
    }


    for(int i=0;i<n;i++){
        if(arr[i]>0) cout<<i+1<<" ";
    }
}


int main(){
    vector<int>arr= {1,3,5,3,4};
    vector<int>ar= {1,3,3,3,4};

    missingInd(ar);
    // for(int i:arr) cout<<i<<" ";

 return 0;
}