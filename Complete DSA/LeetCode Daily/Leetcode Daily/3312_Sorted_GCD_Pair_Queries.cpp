# include<bits/stdc++.h>
using namespace std; 



class Solution {
public:
    typedef long long ll;
    const int M=1e9+7;

    vector<int> gcdValues(vector<int>& a, vector<long long>& q) {
        int n=a.size();
        int maxVal = *max_element(begin(a),end(a));
        // factors + freq
        vector<int>factors(maxVal+1,0);
        for(int ind=0;ind<n;ind++){
            int num=a[ind];
            for(int i=1;i*i<=num;i++){
                if(num%i==0){
                    factors[i]++;

                    if(num/i!=i){
                        factors[num/i]++;
                    }
                }

                
            }
        }

        int m=factors.size();
        vector<ll>countPairs(m,0);
        // max gcd/factor = maxVal
        for(int g=maxVal;g>=1;g--){
            // NC2 = n*(n-1)/2;
            ll frq=factors[g];
            ll paircnt= 1LL*frq*(frq-1)/2;
            countPairs[g]=paircnt;

            // correction in paircnt by multiples checking
            for(ll mul=2*g;mul<=maxVal;mul+=g){
                countPairs[g]-=countPairs[mul];
            }
        }


        // cumulative sum
        for(ll i=1;i<m;i++){
            countPairs[i]+=countPairs[i-1];
        }

        // store ans for each query
        vector<int>ans;

        for(ll i=0;i<q.size();i++){
            ll ind=q[i];
            
            // Apply B.Search
            ll l=0,r=maxVal,temp=0;

            while(l<=r){
                ll gcd_mid=l+(r-l)/2;
                ll ithgcd = countPairs[gcd_mid];
                
                if(ithgcd>ind){
                    temp=gcd_mid;
                    r=gcd_mid-1;
                }

                else l=gcd_mid+1;
                
            }

            ans.push_back(temp);

        }
        

        return ans;





    }   
};

int main(){
    
 return 0;
}