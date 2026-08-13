# include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int f(int i, int j,vector<int>& a) {
        int n = a.size();
        if (i > j) {
            return 0;
        }
        if(i==j) return a[i];

        int take_i=a[i]+min(f(i+2,j,a),f(i+1,j-1,a));
        
        int take_j=a[j]+min(f(i+1,j-1,a),f(i,j-2,a));

        return max(take_i,take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int ind = 0, s = 0, t = 0;
        int n = nums.size();
        
        int totalscore=accumulate(begin(nums),end(nums),0);

        int p1score=f(0,n-1,nums);

        int p2score=totalscore-p1score;

        return p1score>=p2score;
    }
};


int main(){
    
 return 0;
}