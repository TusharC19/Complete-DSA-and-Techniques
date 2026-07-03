# include<bits/stdc++.h>
using namespace std; 
// SIMILAR TO MERGE INTERVALS
// PARTION LABELS

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.length();
            vector<int>ans;
    
            // mapping create karo
            unordered_map<char,int>mapp;
            for(int i=0;i<n;i++){
                if(mapp.find(s[i]) != mapp.end()){
                    // already present 
                    mapp[s[i]] = i;
                }
                else{
                    mapp[s[i]] = i;
                }
            }
    
            // for(auto&it : mapp) cout<<it.first<<" "<<it.second<<endl;
    
            int startidx = 0;
            int end = 0;
            for(int i=0;i<n;i++){
                end = max(end,mapp[s[i]]);
                if(i==end){
                    ans.push_back(end-startidx+1);
                    startidx = end+1;
                }
    
            }
    
            return ans;
    
    
        }
};


int main(){
    Solution s;
    string st = "abaccbdeffed";
    auto ans = s.partitionLabels(st);
    for(int i:ans) cout<<i<<" ";

 return 0;
}