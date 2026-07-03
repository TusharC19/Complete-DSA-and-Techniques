# include<bits/stdc++.h>
using namespace std; 


int getQutient(int divi,int div){
    int s=0,e=divi;
    long long mid;
    int ans = -1;

    while(s<=e){
        mid = s+((e-s)>>1);
        long long p = div*mid;

        if(p == divi) return mid;

        else if(p < divi){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}


int main(){
    int dividend = 10,divisor=-2;

    int ans = getQutient(abs(dividend),abs(divisor));
    if((dividend <0 && divisor>0 )|| (dividend>0 && divisor <0)){
        ans*= -1;
    }
    cout<<ans<<endl;






 return 0;
}