# include<bits/stdc++.h>
using namespace std; 


string decodeMessage(string key,string message){
    int n = key.length();
    int m = message.length();
    unordered_map<char,char>mapp;
    char space = ' ';
    mapp[space] = space;
    // create mapping
    char start = 'a';
    int idx = 0;
    while(start<= 'z' && idx<n){
        char ch = key[idx];

        if(mapp.find(ch) != mapp.end()){
            idx++;
        }
        else{
            // char already present
            mapp[ch] = start;
            start++;
            idx++;
        }
        
    }
    // decode message
    string ans = "";
    for(int i=0;i<m;i++){
        char ch = message[i];
        ans.push_back(mapp[ch]);
    }
    // return ans
    return ans;
   
}

int main(){

    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    string ans = decodeMessage(key,message);
    cout<<ans<<endl;









    
 return 0;
}