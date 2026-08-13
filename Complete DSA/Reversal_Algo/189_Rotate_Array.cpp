# include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        k=k%n;
        reverse(end(a)-k,end(a));
        reverse(begin(a),end(a)-k);
        reverse(begin(a),end(a));

    }
};

int main(){
    
 return 0;
}