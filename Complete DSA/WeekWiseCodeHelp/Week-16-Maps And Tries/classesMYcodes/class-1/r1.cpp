# include<bits/stdc++.h>
using namespace std; 

int main(){
    vector<vector<int>> a = {{1,2,3},{4,6,5},{7,8,9}};
    vector<int>ans;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans.push_back(a[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i: ans) cout<<i<<" ";

 return 0;
}