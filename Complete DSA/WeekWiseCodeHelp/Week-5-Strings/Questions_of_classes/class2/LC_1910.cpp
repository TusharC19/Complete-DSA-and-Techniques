# include<bits/stdc++.h>
using namespace std; 

string solve(string s,string p){
    int n = s.size();

    while(s.find(p) != string::npos){
        int st = s.find(p);
        s.erase(st,p.length());
    }
    return s;
}   

int main(){
    
    string s = "daabcbaabcbc";
    string p = "abc";
    auto ans = solve(s,p);
    cout<<ans<<endl;
 return 0;
}