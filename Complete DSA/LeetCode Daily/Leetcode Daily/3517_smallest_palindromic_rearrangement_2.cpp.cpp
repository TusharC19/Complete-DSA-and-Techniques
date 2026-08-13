# include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    string smallestPalindrome1(string s, int k) {
        int n = s.size();
        vector<int> hash(26, 0);
        for (char& ch : s)
            hash[ch - 'a']++;

        priority_queue<string, vector<string>, greater<string>> pq;

        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) {
                string f = "", m = "", l = "";
                int cnt1 = hash[i];
                if (cnt1 & 1) {
                    m += i + 'a';
                    cnt1--;
                }

                f += string(cnt1 / 2, i + 'a');
                l += string(cnt1 / 2, i + 'a');

                for (int j = 0; j < 26; j++) {
                    if (hash[j] != 0) {
                        int cnt2 = hash[j];
                        if (j == i)
                            continue;
                        if (cnt2 & 1) {
                            m += j + 'a';
                            cnt2--;
                        }
                        f += string(cnt2 / 2, j + 'a');
                        l += string(cnt2 / 2, j + 'a');
                    }
                }

                reverse(l.begin(), l.end());
                string st = f + m + l;
                pq.push(st);
            }
        }

        int topop=k-1;
        while (!pq.empty()&&topop--) {
            pq.pop();

        }

        if (pq.empty())
            return "";
        return pq.top();
    }


    string smallestPalindrome(string s, int k){
        
        
    }
};

int main(){
    
 return 0;
}