# include<bits/stdc++.h>
using namespace std; 



void bucketSort(vector<double>&arr){
    int n = arr.size();
    vector<vector<double>>bucket(n,vector<double>());

    // inserting Elments into bucket
    for(int i=0;i<n;i++){
        int idx = arr[i]*n;
        bucket[idx].push_back(arr[i]);
    }

    // sort each bucket
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
        sort(bucket[i].begin(),bucket[i].end());
        }
    }

    // combining Elements from buckets
    // int idx = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<buckets[i].size();j++){
    //         arr[idx++] = buckets[i][j];
    //     }
    // }
    // directly
    
    int idx = 0;
    vector<double>ans(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            ans[idx++] = bucket[i][j];
        }
    }

    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }
}


int main(){
    vector<double>a = {0.13,0.45,0.12,0.89,0.75,0.63,0.85,0.39};
    bucketSort(a);
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";


 return 0;
}





