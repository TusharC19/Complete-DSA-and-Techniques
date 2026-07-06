# include<bits/stdc++.h>
using namespace std; 

int power(int x,int n){
    int ans=1;

    while(n>0){
        if(n%2==0){
            n=n/2;
            x=x*x;
        }
        else{
            ans=ans*x;
            n=n-1;
        }
    }


    return ans;
}

int main(){
    int x=2,n=7;
    int ans=power(x,n);
    cout<<ans<<endl;
 return 0;
}