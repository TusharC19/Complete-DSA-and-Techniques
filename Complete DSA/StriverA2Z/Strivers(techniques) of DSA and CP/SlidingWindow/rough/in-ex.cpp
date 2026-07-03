# include<bits/stdc++.h>
using namespace std; 

void solve(string &s,int i,string output){
    if(i>=s.size()){
        cout<<output<<endl;
        return ;
    }
    char ch = s[i];
    // include 
    solve(s,i+1,output+ch);
    // exclude
    solve(s,i+1,output);
}

int main(){
    string s = "abc";
    string ans = "";
    solve(s,0,ans);
    
 return 0;
}