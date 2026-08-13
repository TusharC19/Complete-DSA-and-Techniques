# include<bits/stdc++.h>
using namespace std; 

// 1081. Smallest Subsequence of Distinct Characters
// similar: 316. Remove Duplicate Letters

class Solution1 {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            // i.e last occurence of s[i] in string
            mp[ch - 'a'] = i;
        }

        // for(auto&it:mp) cout<<it.first<<" "<<it.second<<endl;

        vector<int> taken(26, 0);
        stack<char> st;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (st.empty()) {
                st.push(ch);
                taken[ch - 'a'] = 1;
                continue;
            }

            while (!st.empty() && st.top() > ch && i < mp[st.top() - 'a'] &&
                   taken[ch - 'a'] == 0) {
                taken[st.top() - 'a'] = 0;
                st.pop();
            }

            if (taken[ch - 'a'] == 0) {
                st.push(ch);
                taken[ch - 'a'] = 1;
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(begin(ans), end(ans));

        return ans;
    }


};

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> lastIdx(26, 0),taken(26,0);
        string ans="";

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            // i.e last occurence of s[i] in string
            lastIdx[ch - 'a'] = i;
        }


        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if(taken[ch-'a']==1){
                // already taken
                continue;
            }

            while(!ans.empty() && ans.back()>ch && i<lastIdx[ans.back()-'a']){
                taken[ans.back()-'a']=0;
                ans.pop_back();
            }

            // here we insert no matter what
            ans.push_back(ch);
            taken[ch-'a']=1;
            
        }

        

        return ans;
    }


};

int main(){
    string a="cbacdcbc";
    // if(a>b) cout<<1;
    // else cout<<0;
    Solution s;
    string ans=s.smallestSubsequence(a);
    cout<<ans<<endl;


 return 0;
}