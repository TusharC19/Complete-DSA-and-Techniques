# include<bits/stdc++.h>
using namespace std; 
// 3499. Maximize Active Section with Trade I

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();

        int activeCount=count(begin(s),end(s),'1');

        vector<int>zeroblocks;
        
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(s[i]=='0') i++;

                zeroblocks.push_back(i-start);

            }
            else i++;
        }

        int mx=0,m=zeroblocks.size();
        for(int i=1;i<m;i++){
            mx=max(mx,zeroblocks[i]+zeroblocks[i-1]);
        }

        return mx+activeCount;
    }
};


int main(){
    
 return 0;
}