# include<bits/stdc++.h>
using namespace std; 

int main(){
    
    unordered_map<int ,int>mapp;

    mapp[1] = 10;
    mapp[2] = 20;
    mapp[3] = 30;

    vector<int>ans;
    for(int i=1;i<=3;i++){
        ans.push_back(mapp[i]);
    }

    for(auto i:ans) cout<<i<<" ";


 return 0;
}