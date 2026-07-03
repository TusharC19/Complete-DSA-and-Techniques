# include<bits/stdc++.h>
using namespace std; 

vector<int> MergeTwoSortedArrays(vector<int>&a,vector<int>&b){
    vector<int>ans;
    int n=a.size(),m=b.size();

    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        } 
        else{
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i<n){
        ans.push_back(a[i]);
        i++;
    }

    while(j<m){
        ans.push_back(b[j]);
        j++;
    }

    return ans;

}

int main(){
    
    vector<int>a = {20,40,60,80,100};
    vector<int>b = {10,30,50,70};

    auto ans = MergeTwoSortedArrays(a,b);
    for(auto it: ans) cout<<it<<" ";


 return 0;
}