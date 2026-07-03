# include<bits/stdc++.h>
using namespace std; 

bool comp(int a,int b){
    return a>b;
}


int main(){
    vector<vector<float>>a = {{0.23,1,3},{0.45,8,5},{0.25,7,4}};
    sort(a.begin(),a.end());
    for(auto it: a){
        cout<<it[0]<<" "<<it[1]<<" "<<it[2];
        cout<<endl;
    }    
 return 0;
}