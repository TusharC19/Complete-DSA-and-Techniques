# include<bits/stdc++.h>
using namespace std; 

int main(){
    
    set<pair<int,int>>s;

    s.insert(make_pair(1,-2));
    s.insert(make_pair(-2,1));
    s.insert(make_pair(3,5));

    for(auto i: s){
        cout<<i.first<<" "<<i.second<<endl;
    }






 return 0;
}