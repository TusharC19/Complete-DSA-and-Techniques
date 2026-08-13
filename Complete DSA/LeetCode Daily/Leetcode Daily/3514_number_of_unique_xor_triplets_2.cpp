# include<bits/stdc++.h>
using namespace std; 

class Solution1 {
public:

    int uniqueXorTriplets(vector<int>& a) {
        int n=a.size();
        unordered_set<int>s,t;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int xorr=a[i]^a[j];
                s.insert(xorr);
                // on going to next j
                xorr=xorr^a[j];
            }
        }

        int cnt=0;
        for(auto&i:s){
            for(int j:a){
                int x=i^j;
                t.insert(x);
            }
        }

        return t.size();
    }
};


class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        int n=a.size();
    }
};

int main(){
    
 return 0;
}