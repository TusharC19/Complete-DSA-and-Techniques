# include<bits/stdc++.h>
using namespace std; 


string removeOcc(string &full,string pattern){
    
    // jab tak full k andar pattern milti rhegi tab tak loop chlao
    while(full.find(pattern) != string::npos){
        int index = full.find(pattern);
        int patternlen = pattern.length();
        full.erase(index,patternlen);
    }
    return full;
}

int main(){
    
    // find return valid index or -1
    string s = "daabcbaabcbc";string part = "abc";
    removeOcc(s,part);
    // cout<<s<<endl;

    cout<<part.find('c')<<endl;
    part.erase(0,3);
    cout<<part<<endl;




 return 0;
}