# include<bits/stdc++.h>
using namespace std; 

int main(){
    set<pair<int,int>>s;
    s.insert({1,1});
    s.insert({1,1});
    s.insert({1,1});
    for(auto i: s){
        cout<<i.first<<" "<<i.second<<endl;
    }
 return 0;
}