# include<bits/stdc++.h>
using namespace std; 

double mysqrt(int x){
    int s=0,e=x;
    long long mid;
    int ans=-1;

    while(s<=e){
        mid = s+(e-s)/2;
        long long product = mid*mid;

        if(product==x) ans = mid;
        else if(product>x) s=mid+1;
        else e = mid-1;
    }
    // return ans;

    double sqrtans = ans;
    // precision upto how many digits
    int p;cout<<"p: ";cin>>p;
    int factor=1;

    for(int i=0;i<p;i++){
        factor /= 10;
        for(int n=0;n<=9;n++){
            int toAdd;
        }
    }
}


int main(){
    

 return 0;
}