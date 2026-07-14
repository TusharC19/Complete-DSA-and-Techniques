# include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    const int M=1e9;
    typedef long long ll;

    int power(int x,int n){
        int ans=1;

        while(n>0){
            if(n%2==1){
                ans=ans*x;
                n=n-1;
            }
            else{
                x=x*x;
                n=n/2;
            }
        }

        return ans;
    }
    
    vector<int> sequentialDigits(int l, int h) {
        
        vector<int>v,a={1,2,3,4,5,6,7,8,9},ans;
        

        for(int len=2;len<10;len++){
            int num=0;
            for(int i=0;i<len;i++){
                num=num*10+a[i];
            }
            if(num>10 && num<1e9) v.push_back(num);
            int i=0,j=len;
            while(j<9){
                num=num-(a[i]*power(10,len-1)*1LL);
                num=num*10+a[j];

                if(num>10 && num<1e9) v.push_back(num);

                i++,j++;
            }

        }


        for(int i:v){
            if(i>=l && i<=h){
                ans.push_back(i);
            }
        }

        return ans;
    }
};


int main(){
    
 return 0;
}