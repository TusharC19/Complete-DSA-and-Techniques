# include<bits/stdc++.h>
using namespace std; 

string removeDuplicates(string s){
    string ans = "";
    int n = s.length();

    for(int i=0;i<n;i++){
        char ch = s[i];
        if(ans.empty()) ans.push_back(ch); // first char push_back
        
        else if(ans.back()==ch) ans.pop_back();

        else ans.push_back(ch);
    }

    return ans;
}


int main(){

    string s = "abccbade";

    auto ans = removeDuplicates(s);
    cout<<ans<<endl;

 return 0;
}