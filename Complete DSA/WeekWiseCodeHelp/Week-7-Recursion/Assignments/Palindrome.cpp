# include<bits/stdc++.h>
using namespace std; 

bool checkPalindrome(string &st,int s,int e){
    if(s>e) return true;

    if(st[s] != st[e]) return false;

    bool ans = checkPalindrome(st,s+1,e-1);
    return ans;
}


int main(){
    string st= "racecar";
    int s=0,e=st.size()-1;
    if(checkPalindrome(st,s,e)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    

 return 0;
}