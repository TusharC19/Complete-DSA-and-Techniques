# include<bits/stdc++.h>
using namespace std; 


class Solution {
public:
    typedef long long ll;
    const int mod = 1e5;

    long long power(long long x, long long n) {
        long long ans = 1;
        while (n) {
            if (n % 2) {
                ans = (ans * x) % mod;
                n--;
            } else {
                x = (x * x) % mod;
                n /= 2;
            }
        }
        return ans;
    }


    int uniqueXorTriplets(vector<int>& a) {
        int n=a.size();
        int maxele=*max_element(begin(a),end(a));
        // maxval can be achieved = set(1) all bits of maxele bits
        int bits=0;
        while(maxele){
            bits++;
            maxele>>=1;
        }

        // int ans=power(2,bits);
        int ans=1<<bits;
        return ans;

    }
};


int main(){
    
 return 0;
}

// 3513_number_of_unique_xor_triplets_2.cpp