# include<bits/stdc++.h>
using namespace std; 




int main(){
    // string s = "--dsjkfo---";
    // reverse(s.begin()+2,s.begin()+8);
    // cout<<s<<endl;

    char a = '1';
    int b = '2'-'0';
    // cout<<b<<endl;

    string s = "abcdef";
    int n = s.size();
    // cout<<s.substr(0,4)<<endl;
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+n-1);
    cout<<s;


 return 0;
}