# include<bits/stdc++.h>
using namespace std; 

void reverseString(string &st,int s,int e){

    if(s>e) return;

    swap(st[s],st[e]);

    reverseString(st,s+1,e-1);
}

int main(){
    string s = "babbar";
    reverseString(s,0,s.size()-1);
    cout<<s<<endl;

    
 return 0;
}