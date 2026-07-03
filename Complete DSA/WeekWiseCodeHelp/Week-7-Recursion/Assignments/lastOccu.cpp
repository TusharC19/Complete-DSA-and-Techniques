# include<bits/stdc++.h>
using namespace std; 

void LastOcu(string &st,char ch,int idx,int &ans){
    if(idx>=st.size()) return;

    if(st[idx] == ch){
        ans = idx;
    }
    
    LastOcu(st,ch,idx+1,ans);
    
    
}

void LastRTL(string &st,char ch,int idx,int &ans){
    if(idx<0) return;

    if(st[idx] == ch){
        ans = idx;
    }
    
    LastOcu(st,ch,idx-1,ans);
    
    
}



int main(){
    string st = "dabceg";
    char ch = 'd';
    int ans=0;
    int idx=st.size()-1;
    
    // LastOcu(st,ch,idx,ans);
    LastRTL(st,ch,idx,ans);
    cout<<ans<<endl;

 return 0;
}