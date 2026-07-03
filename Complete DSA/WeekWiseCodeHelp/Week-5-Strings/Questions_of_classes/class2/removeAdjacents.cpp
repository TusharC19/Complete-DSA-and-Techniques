# include<bits/stdc++.h>
using namespace std; 

string solve(string s){
    int n = s.size();
    string st="";

    for(int i=0;i<n;i++){
        if(st.empty()) st.push_back(s[i]);
        else if(st.back() == s[i]){
            st.pop_back();
        }
        else st += s[i];
    }

    return st;
}



int main(){
    string s = "abbaca";
    auto ans = solve(s);

    cout<<ans<<endl;




 return 0;
}