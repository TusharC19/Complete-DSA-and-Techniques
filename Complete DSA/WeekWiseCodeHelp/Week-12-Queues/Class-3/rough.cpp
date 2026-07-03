# include<bits/stdc++.h>
using namespace std; 

string FirstNonRepeating(string &s){
    int n = s.length();
    unordered_map<char,int>m;
    string ans = "";
    deque<char>q;

    for(int i=0;i<n;i++){
        char ch = s[i];
        m[ch]++;
        q.push_back(ch);

        while(!q.empty()){
            char currch = q.front();
            if(m[currch]==1){
                ans.push_back(currch);
                break;

            }
            else{
                // double case
                q.pop_front();
            }
        }
        // if khali huya toh push_back = '#'
        if(q.empty()){
            ans.push_back('#');
        }

    }
    return ans; 

}


int main(){
    string s = "abaccd";
    auto ans = FirstNonRepeating(s);
    for(auto i: ans){
        cout<<i<<" ";
    }
    
 return 0;
}
