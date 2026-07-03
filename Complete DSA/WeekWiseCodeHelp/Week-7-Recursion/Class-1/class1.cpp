# include<bits/stdc++.h>
using namespace std; 

int factorial(int n){
    int f=1;
    for(int i=n;i>0;i--){
        f *= i;
    }
    return f;
}

int fact(int n){
    if(n==0) return 1;
    int f = n * fact(n-1);
    return f;

}

void print(int n){
    if(n==0) return;
    print(n-1);
    cout<<n<<" ";
    // print(n-1);
}

int powerN(int n,int x){
    if(x==0) return 1;

    int ans = n * powerN(n,x-1);
    return ans;
}

int fib(int n){
    // base case
    if(n==0 || n==1){
        return n;
    }
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int getSum(int n){
    if(n==1) return 1;

    int ans = n + getSum(n-1);
    return ans;
}


int main(){
    // int ans = fact(4);
    // cout<<ans<<endl;

    // print(5);
    // int ans = powerN(2,5);
    // int ans = fib(9);
    int ans = getSum(5);
    cout<<ans<<endl;

 return 0;
}