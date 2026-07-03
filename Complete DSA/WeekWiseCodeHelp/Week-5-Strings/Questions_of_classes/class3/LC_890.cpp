#include <bits/stdc++.h>
using namespace std;

void mapping(string &k,unordered_map<char,char>&mp){
    int n = k.size();

        char curr = 'a';
        for (char&ch:k) {
            if (ch == ' ') continue;
            if(mp.find(ch) == mp.end()){
                mp[ch] = curr;
                curr++;
            }
        }
    
} 
string decodeMessage(string key, string message){
    unordered_map<char,char>mp;
    mapping(key,mp);

    string ans = "";
    for(int i=0;i<message.size();i++){
        if(message[i] == ' ') ans += ' ';
        else ans += mp[message[i]];
    }

    return ans;

}

int main()
{
    string m = "vkbs bs t suepuv";
    string k = "the quick brown fox jumps over the lazy dog";
    string ans = decodeMessage(k,m);
    cout<<ans<<endl;

    return 0;
}