# include<bits/stdc++.h>
using namespace std; 


void normalize(string&s){
    unordered_map<char,char>mp;

    char ch = 'a';
    for(char&i:s){
        if(mp.find(i) == mp.end()){
            mp[i] = ch;
            ch++;
        }
    }

    // mee -> abb (put in original string and change it)
    for(int i=0;i<s.size();i++){
        s[i] = mp[s[i]];
    }

}



vector<string> findAndReplacePattern(vector<string>&words,string pattern){
    vector<string>ans;

    for(auto&it : words){
        string currword = it;
        // string currwordcopy = currword;
        normalize(currword);
        if(pattern == currword){
            ans.push_back(it);
        }
    }

    return ans;
}

int main(){
    string pattern = "abb";
    vector<string>words = {"abc","dzz","mee","aqq","dkd","ccc"};
    auto ans = findAndReplacePattern(words,pattern);
    for(auto&it:ans) cout<<it<<" ";cout<<endl;


 return 0;
}